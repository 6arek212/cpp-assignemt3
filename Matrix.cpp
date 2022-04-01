#include "Matrix.hpp"
using namespace zich;
using namespace std;

namespace zich
{
    ostream &operator<<(std::ostream &out, const Matrix &matrix)
    {
        for (int i = 0; i < matrix.rows; i++)
        {
            out << "[";
            for (int k = 0; k < matrix.cols; k++)
            {
                if (k < matrix.cols - 1)
                {
                    out << matrix.mat[i][k] << " ";
                }
                else
                {
                    out << matrix.mat[i][k];
                }
            }
            out << "]" << endl;
        }

        return out;
    }

    Matrix operator*(double num, const Matrix &matrix)
    {
        Matrix newMat = matrix;
        for (int i = 0; i < matrix.rows; i++)
        {
            for (int k = 0; k < matrix.cols; k++)
            {
                newMat.mat[i][k] *= num;
            }
        }
        return newMat;
    }

    Matrix operator-(const Matrix &matrix)
    {
        Matrix newMat = matrix;

        for (int i = 0; i < matrix.rows; i++)
        {

            for (int k = 0; k < matrix.cols; k++)
            {
                if (newMat.mat[i][k] != 0)
                {
                    newMat.mat[i][k] *= -1;
                }
            }
        }

        return newMat;
    }

}

void hasSameDimensionsCheck(const Matrix &matrix1, const Matrix &matrix2)
{
    if (matrix1.getCols() != matrix2.getCols() || matrix1.getRows() != matrix2.getRows())
    {
        throw "Error the matrixs must be with the same dimenssions";
    }
}

void multiplyableCheck(const Matrix &matrix1, const Matrix &matrix2)
{
    if (matrix1.getCols() != matrix2.getRows())
    {
        throw "Error ,multiplication not defiend for these matrixes";
    }
}

void Matrix::setRows(int rows)
{
    if (rows < 0)
    {
        throw "Rows cant be negative";
    }
    this->rows = rows;
}
void Matrix::setCols(int cols)
{
    if (cols < 0)
    {
        throw "Cols cant be negative";
    }
    this->cols = cols;
}

double Matrix::sumOfMatrix() const
{
    double sum = 0;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t k = 0; k < cols; k++)
        {
            sum += mat[i][k];
        }
    }
    return sum;
}

void Matrix::addNum(int num)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t k = 0; k < cols; k++)
        {
            mat[i][k] += num;
        }
    }
}

bool Matrix::isEquals(const Matrix &matrix) const
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t k = 0; k < cols; k++)
        {
            if (mat[i][k] != matrix.mat[i][k])
            {
                return false;
            }
        }
    }
    return true;
}

Matrix::Matrix(int rows, int cols)
{
    if (rows < 0 || cols < 0)
    {
        throw "Rows | cols , cant be negative";
    }
    this->rows = rows;
    this->cols = cols;
    this->mat = new double *[(size_t)rows];

    for (size_t i = 0; i < rows; i++)
    {
        mat[i] = new double[(size_t)cols];
        for (size_t k = 0; k < cols; k++)
        {
            mat[i][k] = 0;
        }
    }
}

Matrix::Matrix(const vector<double> &vec, int rows, int cols)
{
    if (vec.size() != rows * cols)
    {
        throw "Error size is not correct";
    }

    if (rows < 0 || cols < 0)
    {
        throw "Rows | cols , cant be negative";
    }
    this->rows = rows;
    this->cols = cols;
    this->mat = new double *[(size_t)rows];

    for (size_t i = 0; i < rows; i++)
    {
        mat[i] = new double[(size_t)cols];
        for (size_t k = 0; k < cols; k++)
        {
            mat[i][k] = vec[i * (size_t)rows + k];
        }
    }
}

Matrix::Matrix(const Matrix &matrix)
{
    this->rows = matrix.rows;
    this->cols = matrix.cols;
    this->mat = new double *[(size_t)rows];

    for (int i = 0; i < rows; i++)
    {
        mat[i] = new double[(size_t)cols];
        for (int k = 0; k < cols; k++)
        {
            mat[i][k] = matrix.mat[i][k];
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

Matrix Matrix::operator+(int num)
{
    Matrix newMatrix = *this;
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < rows; k++)
        {
            newMatrix.mat[i][k] += num;
        }
    }
    return newMatrix;
}

Matrix Matrix::operator-(int num)
{
    Matrix newMatrix = *this;
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < rows; k++)
        {
            newMatrix.mat[i][k] -= num;
        }
    }
    return newMatrix;
}

Matrix Matrix::operator+(const Matrix &matrix)
{
    hasSameDimensionsCheck(*this, matrix);
    Matrix newMatrix = *this;
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < rows; k++)
        {
            newMatrix.mat[i][k] += matrix.mat[i][k];
        }
    }
    return newMatrix;
}

void Matrix::operator+=(const Matrix &matrix)
{
    hasSameDimensionsCheck(*this, matrix);
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < rows; k++)
        {
            mat[i][k] += matrix.mat[i][k];
        }
    }
}

Matrix Matrix::operator-(const Matrix &matrix)
{
    hasSameDimensionsCheck(*this, matrix);
    Matrix newMatrix = *this;
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < rows; k++)
        {
            newMatrix.mat[i][k] -= matrix.mat[i][k];
        }
    }
    return newMatrix;
}

void Matrix::operator-=(const Matrix &matrix)
{
    hasSameDimensionsCheck(*this, matrix);
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < rows; k++)
        {
            mat[i][k] -= matrix.mat[i][k];
        }
    }
}

Matrix Matrix::operator*(int num)
{
    Matrix newMatrix = *this;

    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < rows; k++)
        {
            newMatrix.mat[i][k] *= num;
        }
    }

    return newMatrix;
}

void Matrix::operator*=(int num)
{
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < rows; k++)
        {
            mat[i][k] *= num;
        }
    }
}

bool Matrix::operator>(const Matrix &matrix)
{
    hasSameDimensionsCheck(*this, matrix);
    return this->sumOfMatrix() > matrix.sumOfMatrix();
}
bool Matrix::operator>=(const Matrix &matrix)
{
    hasSameDimensionsCheck(*this, matrix);
    return isEquals(matrix) || this->sumOfMatrix() > matrix.sumOfMatrix();
}
bool Matrix::operator<(const Matrix &matrix)
{
    hasSameDimensionsCheck(*this, matrix);
    return this->sumOfMatrix() < matrix.sumOfMatrix();
}
bool Matrix::operator<=(const Matrix &matrix)
{
    hasSameDimensionsCheck(*this, matrix);
    return isEquals(matrix) || this->sumOfMatrix() < matrix.sumOfMatrix();
}
bool Matrix::operator==(const Matrix &matrix)
{
    hasSameDimensionsCheck(*this, matrix);
    return isEquals(matrix);
}
bool Matrix::operator!=(const Matrix &matrix)
{
    hasSameDimensionsCheck(*this, matrix);
    return !isEquals(matrix);
}

void Matrix::operator+=(int num)
{
    addNum(num);
}
void Matrix::operator-=(int num)
{
    addNum(-num);
}

Matrix &Matrix::operator++()
{
    addNum(1);
    return *this;
}

Matrix Matrix::operator++(int)
{
    Matrix temp = *this;
    ++*this;
    return temp;
}

Matrix &Matrix::operator--()
{
    addNum(-1);
    return *this;
}

Matrix Matrix::operator--(int)
{
    Matrix temp = *this;
    --*this;
    return temp;
}

Matrix Matrix::multiply(const Matrix &matrix)
{
    multiplyableCheck(*this, matrix);
    Matrix newMatix(rows, matrix.cols);

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t k = 0; k < matrix.cols; k++)
        {
            double newValue = 0;
            for (size_t q = 0; q < cols; q++)
            {
                if (q == 0)
                {
                    newValue = mat[i][q] * matrix.mat[q][k];
                }
                else
                {
                    newValue += mat[i][q] * matrix.mat[q][k];
                }
            }

            newMatix.mat[i][k] = newValue;
        }
    }

    return newMatix;
}

/**
 * @brief multiply this matrix with another without changing this matrix ,
 *
 * @param matrix
 * @return Matrix a copy of the new matrix
 */
Matrix Matrix::operator*(const Matrix &matrix)
{
    return multiply(matrix);
}

void Matrix::operator*=(const Matrix &matrix)
{
    Matrix m = multiply(matrix);

    for (int i = 0; i < rows; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;

    mat = new double *[(size_t)m.rows];
    for (int i = 0; i < rows; i++)
    {
        mat[i] = new double[(size_t)m.cols];
        for (size_t k = 0; k < m.cols; k++)
        {
            mat[i][k] = m.mat[i][k];
        }
    }
    setRows(m.rows);
    setCols(m.cols);
}
