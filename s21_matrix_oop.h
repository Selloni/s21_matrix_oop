#pragma once

#include <iostream>
#include <cmath>


class S21Matrix {
    public:

        S21Matrix();
        S21Matrix(int rows, int cols);
        S21Matrix(const S21Matrix& other);
        S21Matrix(S21Matrix&& other);
        ~S21Matrix();

        S21Matrix operator+(const S21Matrix &other);
        S21Matrix operator-(const S21Matrix &other);
        S21Matrix operator*(const S21Matrix &other);
        bool operator==(const S21Matrix &other);
        S21Matrix operator=(const S21Matrix &other);
        S21Matrix operator+=(const S21Matrix &other);
        S21Matrix operator-=(const S21Matrix &other);
        S21Matrix operator*=(const S21Matrix &other);
        double &operator()(int row, int col);
        double operator()(int row, int col) const;

        bool EqMatrix(const S21Matrix& other);
        void SumMatrix(const S21Matrix& other);
        void SubMatrix(const S21Matrix& other);
        void MulNumber(const double num);
        void MulMatrix(const S21Matrix& other);
        S21Matrix Transpose();
        S21Matrix CalcComplements();
        double Determinant();
        S21Matrix InverseMatrix();

        void Create();
        void Remove();
        void Copy(const S21Matrix &other);
        int getRows() const;
        void setRows(const int row);
        int getCols() const;
        void setCols(const int col);


    private:
        int rows_, cols_;
        double **matrix_;

};