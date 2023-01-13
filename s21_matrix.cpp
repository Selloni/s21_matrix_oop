#include "s21_matrix_oop.h"

void S21Matrix::Create() {
    for (int row = 0; row < rows_; row++) {
        matrix_[row] = new double[cols_];
    }
} 

void S21Matrix::Remove() {
    for(int row = 0; row < rows_; row++){
        delete[] matrix_[row];
        matrix_[row] = nullptr;
    }
    delete [] matrix_;
    matrix_ = nullptr;
    rows_ = cols_ = 0;
}

void S21Matrix::Copy(const S21Matrix &other){
    for(int row = 0; row < rows_; row++){
        for(int col = 0; col < cols_; col++){
            matrix_[row][col] = other(row ,col);
        }
    }
}

S21Matrix::~S21Matrix(){
    if (matrix_ != nullptr){
        Remove();
    }
}
/////////////////////////////////////////
//// перегурзка функции s21Matrix() ////
///////////////////////////////////////

S21Matrix::S21Matrix() : rows_(3), cols_(3) {
    Create();
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
    if (rows < 1 || cols < 1 ){
        throw std::bad_array_new_length();
    }
    Create;
}

S21Matrix::S21Matrix(const S21Matrix &other) {
    rows_ = other.rows_;
    cols_ = other.cols_;
    Create;
    Copy(other);
}

S21Matrix::S21Matrix(S21Matrix &&other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.rows_ = other.cols_ = 0;
  other.matrix_ = nullptr;
}

/////////////////////////////////////////
////         get    //      set     ////
///////////////////////////////////////

int S21Matrix::getRows() const {
    return rows_;
}

void S21Matrix::setRows(int const row) {
    if (row < 1) {
        throw std::out_of_range("setCol: 'cols' element less or equal zero!");
    }
    S21Matrix tmp(*this);
    Remove();
    rows_ = row;
    cols_ = tmp.getCols();
    Create();
    for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      if (row < tmp.getCols()) {
        matrix_[row][col] = tmp(row, col);
      }
    }
  }
}