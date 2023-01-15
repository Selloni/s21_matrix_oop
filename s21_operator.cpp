#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix &other) {}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

bool S21Matrix::operator==(const S21Matrix &other) {
  return this->EqMatrix(other);
}

S21Matrix S21Matrix::operator=(const S21Matrix &other) {
  if (*this == other) {
    return *this;
  }
  Remove();
  rows_ = other.getRows(), cols_ = other.getCols();
  Create();
  Copy(other);
  return *this;
}

S21Matrix S21Matrix::operator+=(const S21Matrix &other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix &other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix &other) {
  this->MulMatrix(other);
  return *this;
}

double &S21Matrix::operator()(int row, int col) {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("Row or Col number out of size of matrix!");
  }
  return matrix_[row][col];
}

double S21Matrix::operator()(int row, int col) const {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("Row or Col number out of size of matrix!");
  }
  return matrix_[row][col];
}