
#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace zich
{

    class Matrix
    {
    private:
        double **mat;
        int rows;
        int cols;

    private:
        double sumOfMatrix() const;
        bool isEquals(const Matrix &matrix) const;
        void addNum(int num);

    public:
        Matrix(int rows, int cols);
        Matrix(const Matrix &matrix);
        Matrix(const std::vector<double> &vec, int rows, int cols);
        ~Matrix();

        Matrix operator+(const Matrix &matrix) const;
        Matrix operator-(const Matrix &matrix) const;
        Matrix operator*(const Matrix &matrix) const;
        Matrix operator*(double num) const;

        Matrix &operator*=(double num);
        Matrix &operator+=(const Matrix &matrix);
        Matrix &operator-=(const Matrix &matrix);
        Matrix &operator*=(const Matrix &matrix);

        bool operator>(const Matrix &matrix) const;
        bool operator>=(const Matrix &matrix) const;
        bool operator<(const Matrix &matrix) const;
        bool operator<=(const Matrix &matrix) const;
        bool operator!=(const Matrix &matrix) const;

        Matrix &operator=(const Matrix &matrix);

        Matrix &operator++();
        Matrix operator++(int);

        Matrix &operator--();
        Matrix operator--(int);

        int getRows() const { return rows; }

        int getCols() const { return cols; }

        void setRows(int rows);
        void setCols(int cols);

        friend std::ostream &operator<<(std::ostream &out, const Matrix &matrix);
        friend void operator>>(std::istream &in, Matrix &matrix);
        friend Matrix operator*(double num, const Matrix &matrix);
        friend Matrix operator-(const Matrix &matrix);
        friend Matrix operator+(const Matrix &matrix);
        friend bool operator==(const Matrix &matrix1, const Matrix &matrix2);
    };

}