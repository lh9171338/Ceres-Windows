#include <iostream>
#include <ceres/ceres.h>
#include <Eigen/Core>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


class Cost {
private:
    const Eigen::Vector2d mObservation;
    const double mSqrtInformation;

public:
    Cost(const Eigen::Vector2d& observation, const double sqrtInformation)
    : mObservation(observation), mSqrtInformation(sqrtInformation) {}

    template <typename T>
    bool operator()(
          const T* const coeff_ptr,
          T* residuals) const {
        Eigen::Map<const Eigen::Matrix<T, 3, 1>> coeff(coeff_ptr);

        // Compute the residuals
        T x = (T) mObservation[0];
        T y = (T) mObservation[1];
        T a = coeff[0];
        T b = coeff[1];
        T c = coeff[2];
        residuals[0] = (T) mSqrtInformation * (y - exp(a * x * x + b * x) - c);
        return true;
    }

    static ceres::CostFunction* Create(const Eigen::Vector2d& observation, 
        const double sqrtInformation) {
        return new ceres::AutoDiffCostFunction<Cost, 1, 3>(
                new Cost(observation, sqrtInformation));
    }

    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};


void optimize(
        const vector<Eigen::Vector2d>& observationList,
        Eigen::Vector3d& coeff,
        double lambda = 1.0
        )
{
    ceres::Problem problem;

    // 添加代价
    ceres::LossFunction* lossFunction = new ceres::HuberLoss(0.5);
    int nObservations = (int) observationList.size();
    for(int i = 0; i < nObservations; i++) {
        const Eigen::Vector2d& observation = observationList[i];
        const double sqrtInformation = lambda;
        ceres::CostFunction* costFunction = Cost::Create(observation, sqrtInformation);
        problem.AddResidualBlock(
            costFunction,
            lossFunction,
            coeff.data()
        );
    }

    // 优化
    ceres::Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR;
    options.minimizer_progress_to_stdout = true;
    ceres::Solver::Summary summary;
    ceres::Solve(options, &problem, &summary);

    if(!summary.IsSolutionUsable()) {
        cout << "Optimize failed" << endl;
    } else {
        cout << summary.BriefReport() << endl;
    }
}


int main() {
    // 参数
    double a = 1.0, b = 2.0, c = 1.0;          
    int N = 100;                              
    double sigma = 1.0;                     
    RNG rng;                                    
    Eigen::Vector3d coeff(0.0, 0.0, 0.0);                  

    // 生成数据 y = exp(a x^2 + b x) + c
    vector<Eigen::Vector2d> observationList(N);
    for (int i = 0; i < N; i++)
    {
        double x = 1.0 * i / N;
        double y = exp(a * x * x + b * x) + c + rng.gaussian(sigma);
        cout << "data " << i + 1 << ": " << x << ", " << y << endl;
        observationList[i] = Eigen::Vector2d(x, y);
    }

    // 优化
    optimize(observationList, coeff);
    cout << "Initial a: " << 0.0 << " b: " << 0.0 << " c: " << 0.0 << endl;
    cout << "Final   a: " << coeff[0] << " b: " << coeff[1] << " c: " << coeff[2] << endl;

    return 0;
}