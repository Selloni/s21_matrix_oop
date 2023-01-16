// #ifndef SRC_S21_MATRIX_OOP_H_
// #define SRC_S21_MATRIX_OOP_H_
#pragma once

#include <cmath>
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

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

 private:
  int rows_, cols_;
  double **matrix_;

  void Create();
  void Remove();
  void Copy(const S21Matrix &other);
  void getMinor(int row, int col, S21Matrix *other);
  double get_Determinant(S21Matrix *eto);
};

// #endif  //  SRC_S21_MATRIX_OOP_H_