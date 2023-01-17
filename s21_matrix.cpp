#include "s21_matrix_oop.h"

void S21Matrix::Create() {
  matrix_ = new double*[this->rows_];
  for (int row = 0; row < rows_; row++) {
    matrix_[row] = new double[cols_];
  }
}

void S21Matrix::Remove() {
  for (int row = 0; row < rows_; row++) {
    delete[] matrix_[row];
    matrix_[row] = nullptr;
  }
  delete[] matrix_;
  matrix_ = nullptr;
  rows_ = cols_ = 0;
}

void S21Matrix::Copy(const S21Matrix& other) {
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      matrix_[row][col] = other(row, col);
    }
  }
}

S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    Remove();
  }
}

/////////////////////////////////////////
//// перегурзка функции s21Matrix() ////
///////////////////////////////////////

S21Matrix::S21Matrix() : rows_(3), cols_(3) { Create(); }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 1 || cols < 1) {
    throw std::bad_array_new_length();
  }
  Create();
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  Create();
  Copy(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.rows_ = other.cols_ = 0;
  other.matrix_ = nullptr;
}

/////////////////////////////////////////
////         get    //      set     ////
///////////////////////////////////////

int S21Matrix::getRows() const { return rows_; }

void S21Matrix::setRows(int const row) {
  if (row < 1) {
    throw std::out_of_range("setRows: 'rows' element less or equal zero!");
  }
  S21Matrix tmp(*this); /* Coping this matrix to result */
  Remove();
  rows_ = row;
  cols_ = tmp.getCols();
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      if (row < tmp.getRows()) {
        matrix_[row][col] = tmp(row, col);
      }
    }
  }
}

int S21Matrix::getCols() const { return cols_; }

void S21Matrix::setCols(int const col) {
  if (col < 1) {
    throw std::out_of_range("setCols: 'cols' element less or equal zero!");
  }
  S21Matrix tmp(*this);
  Remove();
  cols_ = col;
  rows_ = tmp.getRows();
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      if (row < tmp.getCols()) {
        matrix_[row][col] = tmp(row, col);
      }
    }
  }
}

/////////////////////////////////////////
////             matrix             ////
///////////////////////////////////////

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool return_value = true;
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    for (int i = 0; i < rows_ && return_value; i++) {
      for (int j = 0; j < cols_; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) {
          return_value = false;
          break;
        }
      }
    }
  } else {
    return_value = false;
  }
  return return_value;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.getRows() || cols_ != other.getCols()) {
    throw std::out_of_range("Matrix: Sizes of matrices are not the same!");
  }
  for (int row = 0; row < rows_; ++row) {
    for (int col = 0; col < cols_; ++col) {
      matrix_[row][col] += other(row, col);
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.getRows() || cols_ != other.getCols()) {
    throw std::out_of_range("Matrix: Sizes of matrices are not the same!");
  }
  for (int row = 0; row < rows_; ++row) {
    for (int col = 0; col < cols_; ++col) {
      matrix_[row][col] -= other(row, col);
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int row = 0; row < rows_; ++row) {
    for (int col = 0; col < cols_; ++col) {
      this->matrix_[row][col] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.getRows()) {
    throw std::out_of_range(
        "Columns of first matrix is not equal"
        "to rows of second matrix!");
  }
  S21Matrix result(this->rows_, other.getCols());
  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      for (int k = 0; k < other.rows_; k++) {
        result(i, j) += matrix_[i][k] * other(k, j);
      }
    }
  }
  this->Copy(result);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix transpose_this(cols_, rows_);
  for (int row = 0; row < rows_; ++row) {
    for (int col = 0; col < cols_; ++col) {
      transpose_this(col, row) = matrix_[row][col];
    }
  }
  return transpose_this;
}

S21Matrix S21Matrix::CalcComplements() {
  if (cols_ != rows_) throw std::invalid_argument("The matrix is not square.");
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      double determinant = 0;
      S21Matrix new_minor = MinorMatrix(i, j);
      determinant = new_minor.Determinant();
      determinant = determinant * pow(-1, i + j);
      result.matrix_[i][j] = determinant;
    }
  }
  return result;
}

S21Matrix S21Matrix::MinorMatrix(int rows, int col) {
  S21Matrix result(rows_ - 1, cols_ - 1);
  for (int i = 0, mini_i = 0; i < rows_; i++) {
    if (i == rows) continue;
    for (int j = 0, mini_j = 0; j < cols_; j++) {
      if (j == col) continue;
      result.matrix_[mini_i][mini_j] = matrix_[i][j];
      mini_j++;
    }
    mini_i++;
  }
  return result;
}

double S21Matrix::Determinant() {
  if (cols_ != rows_) throw std::invalid_argument("The matrix is not square.");
  double result = 0;
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    double determinant = 0;
    for (int i = 0; i < rows_; i++) {
      S21Matrix new_minor = MinorMatrix(0, i);
      result = new_minor.Determinant();
      determinant += pow(-1, i) * matrix_[0][i] * result;
    }
    result = determinant;
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double determ = Determinant();
  if (fabs(determ) < 1e-7) {
    throw std::range_error("Error: Determinant is 0");
  }
  S21Matrix complements_matrix(CalcComplements());
  S21Matrix transpose_matrix(complements_matrix.Transpose());
  return transpose_matrix * (1. / determ);
}
