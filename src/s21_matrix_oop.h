// #ifndef SRC_S21_MATRIX_OOP_H_
// #define SRC_S21_MATRIX_OOP_H_
#pragma once

#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix &other);
  S21Matrix operator=(const S21Matrix &other);
  S21Matrix operator+=(const S21Matrix &other);
  S21Matrix operator-=(const S21Matrix &other);
  S21Matrix operator*=(const S21Matrix &other);
  S21Matrix operator*=(const double num);
  double &operator()(int row, int col);
  double operator()(int row, int col) const;

  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);

  int getRows() const;
  void setRows(const int row);
  int getCols() const;
  void setCols(const int col);
  void Copy(const S21Matrix &other);

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  S21Matrix MinorMatrix(int rows, int col);
  double Determinant();
  S21Matrix InverseMatrix();

 private:
  int rows_, cols_;
  double **matrix_;

  void Create();
  void Remove();
};

// #endif  //  SRC_S21_MATRIX_OOP_H_