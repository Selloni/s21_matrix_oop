#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

/*
    Информация о классе:
    Стандартный конструктор без входных параметров создает матрицу 3 на 3 в
   matrix также записывает обратную матрицу данной в i_matrix, также с матрицей
    алгебраических дополнений и записывает в alg_matrix.
    Конструктор с одним входным параметром status
      При status = 0 матрица из стандартного конструктора (matrix)
    обрезается с сохранением значений до размера 2 на 2
      При status = 1 matrix будет иметь размер 3 на 3 с нулевыми значениями
      При status = 2 matrix будет иметь размер 4 на 4 с другими значениями
      При status = 3 в matrix будет лежать матрица 3 на 3 но ее значения будут
    значениями квадрата матрицы (matrix) из стандартного конструктора
      При status = 4 в matrix будет лежать матрица 3 на 3 но ее значения будут
    значениями матрица (matrix) умноженной на 2 из стандартного конструктора
      При status = 5 в matrix будет лежать матрица 2 на 3 и будет записан ее
    трансонированный вариант в t_matrix
    Важно! Там где НЕ упомянуто что значения i_matrix, t_matrix и
    alg_matrix НАЙДЕНЫ их НЕ ИСПОЛЬЗОВАТЬ! Они будут иметь нулевые значения!
*/

class TestS21Matrix {
 public:
  S21Matrix *matrix_3x3;
  S21Matrix *matrix_4x3;
  S21Matrix *matrix_temp;

  void SetUp() {
    matrix_3x3 = new S21Matrix();
    matrix_3x3->operator()(0, 0) = 0;
    matrix_3x3->operator()(0, 1) = 1;
    matrix_3x3->operator()(0, 2) = 2;
    matrix_3x3->operator()(1, 0) = 3;
    matrix_3x3->operator()(1, 1) = 4;
    matrix_3x3->operator()(1, 2) = 5;
    matrix_3x3->operator()(2, 0) = 6;
    matrix_3x3->operator()(2, 1) = 7;
    matrix_3x3->operator()(2, 2) = 8;

    matrix_4x3 = new S21Matrix(4, 3);
    matrix_4x3->operator()(0, 0) = 0;
    matrix_4x3->operator()(0, 1) = 1;
    matrix_4x3->operator()(0, 2) = 2;
    matrix_4x3->operator()(1, 0) = 3;
    matrix_4x3->operator()(1, 1) = 4;
    matrix_4x3->operator()(1, 2) = 5;
    matrix_4x3->operator()(2, 0) = 6;
    matrix_4x3->operator()(2, 1) = 7;
    matrix_4x3->operator()(2, 2) = 8;
    matrix_4x3->operator()(3, 0) = 9;
    matrix_4x3->operator()(3, 1) = 10;
    matrix_4x3->operator()(3, 2) = 11;
  }

  void TearDown() {
    delete matrix_3x3;
    delete matrix_4x3;
  }
};

TEST(S21MatrixTest, constructor) {
  S21Matrix matrix;
  EXPECT_EQ(3, matrix.getRows());
  EXPECT_EQ(3, matrix.getCols());
}

TEST(S21MatrixTest, constructorWithParameters) {
  S21Matrix matrix(5, 6);
  EXPECT_EQ(5, matrix.getRows());
  EXPECT_EQ(6, matrix.getCols());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}