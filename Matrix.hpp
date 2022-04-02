
#include <string>
#include <vector>
#include <iostream>

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
        Matrix multiply(const Matrix &matrix);
        void initMat();

    public:
        Matrix(int rows, int cols);
        Matrix(const Matrix &matrix);
        Matrix(const std::vector<double> &vec, int rows, int cols);
        ~Matrix();

    
        Matrix operator+(const Matrix &matrix);
        Matrix operator-(const Matrix &matrix);
        Matrix operator*(const Matrix &matrix);
        Matrix operator*(double num);

  
        void operator*=(double num);
        void operator+=(const Matrix &matrix);
        void operator-=(const Matrix &matrix);
        void operator*=(const Matrix &matrix);

        bool operator>(const Matrix &matrix);
        bool operator>=(const Matrix &matrix);
        bool operator<(const Matrix &matrix);
        bool operator<=(const Matrix &matrix);
        bool operator==(const Matrix &matrix);
        bool operator!=(const Matrix &matrix);

        Matrix &operator++();
        Matrix operator++(int);

        Matrix &operator--();
        Matrix operator--(int);

        int getRows() const
        {
            return rows;
        }

        int getCols() const
        {
            return cols;
        }

        void setRows(int rows);
        void setCols(int cols);

        friend std::ostream &operator<<(std::ostream &out, const Matrix &matrix);
        friend Matrix operator*(double num, const Matrix &matrix);
        friend Matrix operator-(const Matrix &matrix);
    };

}