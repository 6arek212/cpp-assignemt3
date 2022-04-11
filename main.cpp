#include <iostream>
#include "Matrix.hpp"

int main()
{

    std::vector<double> arr1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> arr2 = {2, 0, 1, 0, 2, 3, 0, 0, 2};

    zich::Matrix mat1{arr1, 3, 3};
    zich::Matrix mat2{arr2, 3, 3};
    cout << "-----mat1------" << endl;

    cout << mat1 << endl;

    cout << "-----mat2------" << endl;

    cout << mat2 << endl;

    cout << "-----mat1 + mat2------" << endl;

    cout << mat1 + mat2 << endl;

    cout << "------mat1 - mat2 -----" << endl;

    cout << mat1 - mat2 << endl;

    cout << "------mat1 * mat2-----" << endl;

    cout << mat1 * mat2 << endl;

    cout << "-----++mat1------" << endl;

    cout << ++mat1 << endl;

    cout << "------ --mat1-----" << endl;

    cout << --mat1 << endl;
}