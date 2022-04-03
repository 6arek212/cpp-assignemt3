
#include <iostream>
#include "Matrix.hpp"
using namespace std;
using namespace zich;

int main(int argc, char const *argv[])
{

    Matrix matrix1(2, 2);
    cout << "Enter matrix of size 2*2 numbers :";
    cin >> matrix1;

    vector<double> arr1 = {
        3, 0,
        0, 3};
    Matrix matrix2(arr1, 2, 2);

    cout << "Matrix 1" << endl;
    cout << matrix1;

    cout << endl
         << "-----------------" << endl;

    cout << "Matrix 2" << endl;
    cout << matrix2;

    cout << endl
         << "-----------------" << endl;

    cout << "Matrix1 + Matrix2" << endl;
    cout << matrix1 + matrix2;

    cout << endl
         << "-----------------" << endl;

    cout << "Matrix1 - Matrix2" << endl;
    cout << matrix1 - matrix2;

    cout << endl
         << "-----------------" << endl;

    cout << "Matrix1 * Matrix2" << endl;
    cout << matrix1 * matrix2;

    cout << endl
         << "-----------------" << endl;
    matrix1++;
    ++matrix1;
    cout << "++Matrix1++" << endl;
    cout << matrix1 << endl;

    return 0;
}
