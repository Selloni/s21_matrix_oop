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
  bool equal = true;
  if (this == &other) {
    return true;
  } else if (rows_ != other.getRows() && cols_ != other.getCols()) {
    return false;
  } else {
    bool check = true;
    for (int row = 0; row < rows_ && check; ++row) {
      for (int col = 0; col < cols_; ++col) {
        if (fabs(matrix_[row][col] - other(row, col)) >= 1e-6) {
          equal = false;
          check = false;
        }
      }
    }
  }
  return equal;
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
  for (int i = 0; i < result.getRows(); i++) {
    for (int j = 0; j < result.getCols(); j++) {
      for (int k = 0; k < other.getRows(); k++) {
        result(i, j) += this->matrix_[i][k] * other(k, j);
      }
    }
  }
  this->setCols(other.getCols());  //////////// question
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

/////////////////////////////////////////
////          сомнительно           ////
///////////////////////////////////////

void S21Matrix::getMinor(int row, int col, S21Matrix* other) {
  int m_row = 0;
  int m_col = 0;
  for (int i = 0; i < rows_; i++) {
    if (i == row) {
      continue;
    }
    m_col = 0;
    for (int j = 0; j < cols_; j++) {
      if (j == col) {
        continue;
      }
      other->matrix_[m_row][m_col] = this->matrix_[i][j];
      m_col++;
    }
    m_row++;
  }
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::logic_error("CalcComplements: Matrix is not a square!");
  }
  for (int row = 0; row < this->rows_; ++row) {
    for (int col = 0; col < cols_; ++col) {
      S21Matrix minor(rows_, cols_);
      get_Determinant(&minor);
      matrix_[row][col] = pow(-1, (row + col)) * Determinant();
    }
  }
  return *this;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::logic_error("Determinant: Matrix is not a square!");
  }
  S21Matrix tmp(rows_, cols_);
  return get_Determinant(&tmp);
}

double S21Matrix::get_Determinant(S21Matrix* eto) {
  double res;
  if (eto->getRows() != eto->getCols()) {
    throw std::logic_error("CalcComplements: Matrix is not a square!");
  }
  S21Matrix tmp(eto->getRows() - 1, eto->getCols() - 1);
  for (int col = 0; col < eto->getCols(); ++col) {
    getMinor(0, col, &tmp);
    if (col % 2) {
      res -= this->matrix_[0][col] * get_Determinant(&tmp);
    } else {
      res += this->matrix_[0][col] * get_Determinant(&tmp);
    }
  }
  return res;
}

/////////////////////////////////////////
////         ===============        ////
///////////////////////////////////////

S21Matrix S21Matrix::InverseMatrix() {
  double determ = Determinant();
  if (fabs(determ) < 1e-7) {
    throw std::range_error("Error: Determinant is 0");
  }
  S21Matrix complements_matrix(CalcComplements());
  S21Matrix transpose_matrix(complements_matrix.Transpose());
  return transpose_matrix * (1. / determ);
}
