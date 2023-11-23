#include <bits/stdc++.h>
#include "E:\BaiduSyncdisk\Eigen\Dense"
using namespace Eigen;

int main() {
    MatrixXd A(2, 2); // 创建一个2x2的矩阵
    A << 1, 2, 3, 4; // 赋值矩阵


    MatrixXd B(2, 3);
    B << 5, 6, 7, 8, 9, 10;

    MatrixXd C = A * B;

    // 输出结果
    std::cout << "Matrix C:\n" << C << "\n";

    std::cout << C.determinant() << std::endl;

    // 计算逆矩阵
    MatrixXd D = A.inverse();
    Eigen::

    // 输出逆矩阵
    std::cout << "Inverse of A:\n" << D << "\n";
    system("pause");
    return 0;
}
