#include "doctest.h"
#include "Matrix.hpp"
using namespace zich;
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

TEST_CASE("bad input")
{
    vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    vector<double> arr2 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 3};

    CHECK_THROWS(Matrix matrix(arr, -3, 3));

    Matrix matrix(arr, 3, 3);
    Matrix matrix2(arr2, 4, 3);
    bool a;

    CHECK_THROWS((matrix * matrix2));
    CHECK_THROWS((matrix *= matrix2));
    CHECK_THROWS((matrix + matrix2));
    CHECK_THROWS((matrix += matrix2));
    CHECK_THROWS(a = (matrix == matrix2));
    CHECK_THROWS(a = (matrix != matrix2));
    CHECK_THROWS(a = (matrix <= matrix2));
    CHECK_THROWS(a = (matrix < matrix2));
    CHECK_THROWS(a = (matrix > matrix2));
    CHECK_THROWS(a = (matrix >= matrix2));

    CHECK_NOTHROW((3 * matrix));
    CHECK_NOTHROW((matrix * 3));
}

TEST_CASE("matrix operations + / - / * ")
{
    vector<double> arr1 = {3, 0, 0,
                           0, 3, 0,
                           0, 0, 3};

    vector<double> arr2 = {1, 0, 0,
                           0, 1, 0,
                           0, 0, 1};

    vector<double> arr3 = {1, 0, 0,
                           2, 1, 0,
                           0, 3, 1};

    vector<double> arr1_arr2_add = {4, 0, 0,
                                    0, 4, 0,
                                    0, 0, 4};

    vector<double> arr1_arr3_add = {4, 0, 0,
                                    2, 4, 0,
                                    0, 3, 4};

    vector<double> arr1_arr3_mul = {3, 0, 0,
                                    6, 3, 0,
                                    0, 9, 3};

    vector<double> arr1_min_arr2 = {2, 0, 0,
                                    0, 2, 0,
                                    0, 0, 2};

    CHECK_THROWS(Matrix matrix(arr1, -3, 3));

    Matrix matrix(arr1, 3, 3);
    Matrix matrix2(arr2, 3, 3);
    Matrix matrix3(arr3, 3, 3);

    // mul
    CHECK(((matrix * matrix2) == Matrix(arr1, 3, 3)));
    CHECK(((matrix * matrix3) == Matrix(arr1_arr3_mul, 3, 3)));

    CHECK(((matrix + matrix2) == Matrix(arr1_arr2_add, 3, 3)));
    CHECK(((matrix + matrix3) == Matrix(arr1_arr3_add, 3, 3)));

    CHECK(((matrix - matrix2) == Matrix(arr1_min_arr2, 3, 3)));

    matrix += matrix3;
    CHECK((matrix == Matrix(arr1_arr3_add, 3, 3)));

    matrix -= matrix3;
    CHECK((matrix == Matrix(arr1, 3, 3)));

    matrix *= matrix2;
    CHECK((matrix == Matrix(arr1, 3, 3)));

    matrix *= matrix3;
    CHECK((matrix == Matrix(arr1_arr3_mul, 3, 3)));
}

TEST_CASE("Matrix op ++ / -- ")
{

    vector<double> arr1 = {3, 0, 0,
                           0, 3, 0,
                           0, 0, 3};

    vector<double> arr4 = {-3, 0, 0,
                           0, -3, 0,
                           0, 0, -3};

    vector<double> arr2 = {1, 0, 0,
                           0, 1, 0,
                           0, 0, 1};

    vector<double> arr3 = {1, 0, 0,
                           2, 1, 0,
                           0, 3, 1};

    vector<double> arr1pp = {4, 1, 1,
                             1, 4, 1,
                             1, 1, 4};

    Matrix matrix1(arr1, 3, 3);
    Matrix matrix2(arr2, 3, 3);
    Matrix matrix3(arr3, 3, 3);
    Matrix matrix4(arr4, 3, 3);

    matrix1++;
    CHECK((matrix1 == Matrix(arr1pp, 3, 3)));

    matrix1--;
    CHECK((matrix1 == Matrix(arr1, 3, 3)));

    ++matrix1;
    CHECK((matrix1 == Matrix(arr1pp, 3, 3)));

    --matrix1;
    CHECK((matrix1 == Matrix(arr1, 3, 3)));

    CHECK((matrix1 == -matrix4));
}

TEST_CASE("Test output/input operator")
{

    vector<double> arr1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double> arr2 = {3, -2, 0, 0, 3, 0, -1, 0, 3};
    vector<double> arr3 = {5, 0, 0, 0, 5, 0, 0, 0, 5};
    vector<double> arr4 = {5, 0, 0, 6, 7,
                           7, 0, 5, 0, 0,
                           0, 5, 0, 0, 0};
    Matrix mat1{arr1, 3, 3};
    Matrix mat2{arr2, 3, 3};
    Matrix mat3{arr3, 3, 3};
    Matrix mat4{arr4, 3, 5};

    // out
    ostringstream ostream1;
    ostream1 << mat1;
    CHECK(ostream1.str() == "[1 0 0]\n[0 1 0]\n[0 0 1]");
    ostringstream ostream2;
    ostream2 << mat2;
    CHECK(ostream2.str() == "[3 -2 0]\n[0 3 0]\n[-1 0 3]");
    ostringstream ostream3;
    ostream3 << mat3;
    CHECK(ostream3.str() == "[5 0 0]\n[0 5 0]\n[0 0 5]");

    // in
    ostringstream ostream4;
    ostream4 << mat4;
    CHECK(ostream4.str() == "[5 0 0 6 7]\n[7    0 5 0 0]\n[0 5 0 0 0]");
    istringstream st1{"[1 1 1 1]$[1 1 1 1], [1 1   1 1]\n"};
    CHECK_THROWS(st1 >> mat1);
    istringstream st2{"[1 1 1 1]+, [1 1 1   1] [1  1 1 1],\n"};
    CHECK_THROWS(st2 >> mat1);
    istringstream st3{"[1 1111 1]    [1 1111 1 1], [1 1 1 1]\n"};
    CHECK_THROWS(st3 >> mat1);
}