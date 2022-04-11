#include "doctest.h"
#include "Matrix.hpp"
using namespace zich;

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

    matrix1++;
    CHECK((matrix1 == Matrix(arr1pp, 3, 3)));

    matrix1--;
    CHECK((matrix1 == Matrix(arr1, 3, 3)));

    ++matrix1;
    CHECK((matrix1 == Matrix(arr1pp, 3, 3)));

    --matrix1;
    CHECK((matrix1 == Matrix(arr1, 3, 3)));
}

