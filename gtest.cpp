#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

using namespace std;
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

// class TestS21Matrix {
//  public:
//   TestS21Matrix() {
//     matrix(0, 0) = 7, matrix(0, 1) = 8, matrix(0, 2) = 3;
//     matrix(1, 0) = 5, matrix(1, 1) = 9, matrix(1, 2) = 1;
//     matrix(2, 0) = 9, matrix(2, 1) = 4, matrix(2, 2) = 2;

//     i_matrix(0, 0) = -0.150538, i_matrix(0, 1) = 0.0430108;
//     i_matrix(0, 2) = 0.204301, i_matrix(1, 0) = 0.0107527;
//     i_matrix(1, 1) = 0.139785, i_matrix(1, 2) = -0.0860215;
//     i_matrix(2, 0) = 0.655914, i_matrix(2, 1) = -0.473118;
//     i_matrix(2, 2) = -0.247312;

//     alg_matrix(0, 0) = 14, alg_matrix(0, 1) = -1, alg_matrix(0, 2) = -61;
//     alg_matrix(1, 0) = -4, alg_matrix(1, 1) = -13, alg_matrix(1, 2) = 44;
//     alg_matrix(2, 0) = -19, alg_matrix(2, 1) = 8, alg_matrix(2, 2) = 23;
//   }
//   TestS21Matrix(int status) {
//     if (status == 0) {
//       matrix.setCols(2);
//       matrix.setRows(2);
//       matrix(0, 0) = 7, matrix(0, 1) = 8;
//       matrix(1, 0) = 5, matrix(1, 1) = 9;
//     }
//     if (status == 1) {
//     }
//     if (status == 2) {
//       matrix.setRows(4);
//       matrix.setCols(4);
//       matrix(0, 0) = 1.2, matrix(1, 0) = 10.2, matrix(2, 0) = 5.8,
//                 matrix(3, 0) = 2.6, matrix(0, 1) = 4.8, matrix(1, 1) = -6.7;
//       matrix(2, 1) = 3.45, matrix(3, 1) = -8.9, matrix(0, 2) = -3.2;
//       matrix(1, 2) = 1.9, matrix(2, 2) = -7.8, matrix(3, 2) = 2.2;
//       matrix(0, 3) = 9.08, matrix(1, 3) = 9.1, matrix(2, 3) = 0.34,
//                 matrix(3, 3) = -1.5;
//     }
//     if (status == 3) {
//       matrix(0, 0) = 116, matrix(0, 1) = 140, matrix(0, 2) = 35;
//       matrix(1, 0) = 89, matrix(1, 1) = 125, matrix(1, 2) = 26;
//       matrix(2, 0) = 101, matrix(2, 1) = 116, matrix(2, 2) = 35;
//     }
//     if (status == 4) {
//       matrix(0, 0) = 14, matrix(0, 1) = 16, matrix(0, 2) = 6;
//       matrix(1, 0) = 10, matrix(1, 1) = 18, matrix(1, 2) = 2;
//       matrix(2, 0) = 18, matrix(2, 1) = 8, matrix(2, 2) = 4;
//     }
//     if (status == 5) {
//       matrix.setRows(2);
//       matrix(0, 0) = 0, matrix(0, 1) = 1, matrix(0, 2) = 2;
//       matrix(1, 0) = 3, matrix(1, 1) = 4, matrix(1, 2) = 5;

//       t_matrix.setCols(2);
//       t_matrix.setRows(3);
//       t_matrix(0, 0) = 0, t_matrix(0, 1) = 3;
//       t_matrix(1, 0) = 1, t_matrix(1, 1) = 4;
//       t_matrix(2, 0) = 2, t_matrix(2, 1) = 5;
//     }
//   }
//   S21Matrix matrix;
//   S21Matrix t_matrix;
//   S21Matrix i_matrix;
//   S21Matrix alg_matrix;
// };

// TEST(EqMatrixTest, HanglesInitedEqualMatrices) {
//   TestS21Matrix A, B;
//   ASSERT_EQ(true, A.matrix.EqMatrix(B.matrix));
// }

// TEST(EqMatrixTest, HanglesInitedUnEqualMatrices) {
//   TestS21Matrix A, B;
//   B.matrix(0, 0) = A.matrix(0, 0) - 1;
//   ASSERT_EQ(false, A.matrix.EqMatrix(B.matrix));
// }

TEST(Constructors, Default) {
  S21Matrix m1;
  EXPECT_EQ(3, m1.getRows());
  EXPECT_EQ(3, m1.getCols());
}

TEST(Constructors, With_parameters) {
  S21Matrix m1(4, 5);
  EXPECT_EQ(4, m1.getRows());
  EXPECT_EQ(5, m1.getCols());
  EXPECT_NO_THROW(S21Matrix m1(4, 5));

  EXPECT_ANY_THROW(S21Matrix m2(0, 8));
  EXPECT_ANY_THROW(S21Matrix(-8, 8));
}

TEST(Constructors, Copy) {
  S21Matrix m1(5, 5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      m1(i, j) = i * j;
    }
  }

  S21Matrix m2(m1);
  EXPECT_EQ(m1.getRows(), m2.getRows());
  for (int i = 0; i < m2.getRows(); i++) {
    for (int j = 0; j < m2.getCols(); j++) {
      EXPECT_EQ(m1(i, j), m2(i, j));
    }
  }
}

TEST(Constructors, Move) {
  S21Matrix m2(4, 5);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      m2(i, j) = i * j;
    }
  }
  S21Matrix res1(m2);
  S21Matrix m1(move(m2));
  EXPECT_EQ(m1.getRows(), res1.getRows());
  EXPECT_EQ(m1.getCols(), res1.getCols());
  EXPECT_EQ(true, m1.EqMatrix(res1));
}

TEST(Constructors, Destructor) {
  S21Matrix m1(4, 5);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      m1(i, j) = i * j;
    }
  }
  m1.~S21Matrix();
  EXPECT_EQ(0, m1.getRows());
  EXPECT_EQ(0, m1.getCols());
}

TEST(Method, Equal) {
  S21Matrix m1(4, 5), test1(4, 5);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      m1(i, j) = i * j;
      test1(i, j) = i * j + 1;
    }
  }
  S21Matrix test2(m1);
  EXPECT_EQ(false, m1.EqMatrix(test1));
  EXPECT_EQ(true, m1.EqMatrix(test2));
}

TEST(Method, Sum) {
  S21Matrix m1(4, 5), m2(4, 5), m3(4, 5);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      m1(i, j) = i * j;
      m2(i, j) = i * j + 1;
      m3(i, j) = i * j + 2;
    }
  }
  m1.SumMatrix(m2);
  EXPECT_EQ(false, m1.EqMatrix(m3));
}

TEST(Method, Sub) {
  S21Matrix m1(4, 5), m2(4, 5), m3(4, 5);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      m1(i, j) = i * j;
      m2(i, j) = i * j + 1;
      m3(i, j) = i * j + 2;
    }
  }
  m1.SubMatrix(m2);
  EXPECT_EQ(false, m1.EqMatrix(m3));
}

TEST(Method, MulNumber) {
  S21Matrix m1(4, 5), m2(4, 5);
  int num = 2;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      m1(i, j) = i * j;
      m2(i, j) = i * j + 1;
    }
  }
  m1.MulNumber(num);
  EXPECT_EQ(false, m1.EqMatrix(m2));
}

TEST(Method, MulMatrix) {
  S21Matrix m1(2, 2), m2(2, 2), m3(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      m1(i, j) = 2;
      m2(i, j) = 3;
      m3(i, j) = 12;
    }
  }
  m1.MulMatrix(m2);

  S21Matrix m2_2(3, 4);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      m2_2(i, j) = i * j;
    }
  }
  EXPECT_EQ(true, m1.EqMatrix(m3)); 
  EXPECT_ANY_THROW(m1.MulMatrix(m2_2)); 
}

TEST(Operator, Sum) {
  S21Matrix m1(2, 2), m2(2, 2), m3(2, 2);
  for (int i = 1; i < 2; i++) {
    for (int j = 1; j < 2; j++) {
      m1(i, j) = i * j * 6.6;
      m2(i, j) = i * j * 7.7;
      m3(i, j) = i * j * (6.6 + 7.7);
    }
  }
  S21Matrix m4 = m1 + m2;
  EXPECT_EQ(true, m3.EqMatrix(m4));
}

// TEST(Operator, Sub) {
//   int arr1[] = {3, 2, -6, 0};
//   int arr2[] = {-7, 0, -3, 2};
//   int arr3[] = {10, 2, -3, -2};
//   int tmp = 0;
//   S21Matrix m1(2, 2), m2(2, 2), m3(2, 2);
//   for (int i = 1; i < 2; i++) {
//     for (int j = 1; j < 2; j++) {
//       m1(i, j) = arr1[tmp];
//       m2(i, j) = arr2[tmp];
//       m3(i, j) = arr3[tmp];
//       tmp++;
//     }
//   }
//   S21Matrix m4 = m1 - m2;
//   EXPECT_EQ(true, m3.EqMatrix(m4));
// }

// TEST(Operator, MulNum) {
//   S21Matrix m1(3, 3), m2(3, 3);
//   for (int i = 1; i < 3; ++i) {
//     for (int j = 1; j < 3; ++j) {
//       m1(i, j) = 2;
//       m2(i, j) = 2 * 5;
//     }
//   }
//   S21Matrix m3 = m1 * 5;
//   EXPECT_EQ(true, m2.EqMatrix(m3));
// }

TEST(Operator, MulMat) {
  S21Matrix m1(2, 4), m2(4, 1), m3(2, 1);
  int arr[] = {1, 2, 3, 4, 5, 6, 7, -8, 10, 9, 8, -7, 24, 216};
  int tmp = 0;
  for (int i = 1; i < 2; ++i) {
    for (int j = 1; j < 4; ++j) {
      m1(i, j) = arr[tmp];
      tmp++;
    }
  }
  for (int i = 1; i < 4; ++i) {
    for (int j = 1; j < 1; ++j) {
      m2(i, j) = arr[tmp];
      tmp++;
    }
  }
  for (int i = 1; i < 2; ++i) {
    for (int j = 1; j < 1; ++j) {
      m3(i, j) = arr[tmp];
      tmp++;
    }
  }
  EXPECT_ANY_THROW(m1.MulMatrix(m2));
}

// TEST(Operator, MulMat2) {
//   S21Matrix m1(3, 3), m2(3, 3), m3(3, 3), m4(3, 3), m5(1, 3);
//   for (int i = 0; i < 3; i++) {
//     for (int j = 0; j < 3; j++) {
//       m1(i, j) = 4;
//       m2(i, j) = 4;
//       m3(i, j) = 48;
//     }
//   }
//   m4 = m1 * m2;
//   EXPECT_EQ(true, m4.EqMatrix(m3));
//   EXPECT_ANY_THROW(m1 * m5);
// }

TEST(Operator, Equal) {
  S21Matrix m1(21, 42), m2(21, 42), m3(8, 21);
  EXPECT_EQ(true, m1 == m2);
  EXPECT_NE(true, m1 == m3);
}

TEST(EqMatrixTest, MethodTest) {
  S21Matrix m1(3, 3), m2(3, 3);
  ASSERT_TRUE(m1 == m2);
}

TEST(OperatorEqMatrix2, MethodTest) {
  S21Matrix m1(3, 3), m2(2, 2);
  ASSERT_FALSE(m1 == m2);
}

// TEST(OperatorEqMatrix3, MethodTest) {
//   S21Matrix m1(3, 4), m2(3, 4), m3(3, 33);
//   EXPECT_TRUE(m1 == m2);
//   EXPECT_FALSE(m1 == m3);
// }

TEST(OperatorEqMatrix4, MethodTest) {
  S21Matrix m1(3, 3), m2(3, 33);
  m1 = m2;
  EXPECT_TRUE(m1 == m2);
}

// TEST(EqMatrix1, MethodTest) {
//   S21Matrix m1(21, 42), m2(21, 42), m3(8, 21);
//   EXPECT_TRUE(m1.EqMatrix(m2));
//   EXPECT_FALSE(m1.EqMatrix(m3));
// }

TEST(AccessorMutator1, GetRowsTest) {
  S21Matrix m1(3, 4);
  EXPECT_EQ(m1.getRows(), 3);
}

TEST(AccessorMutator2, getColsTest) {
  S21Matrix m1(3, 4);
  EXPECT_EQ(m1.getCols(), 4);
}

// TEST(AccessorMutator3, SetRowsTest) {
//   S21Matrix m1(4, 3);
//   m1.setRows(3);
//   EXPECT_EQ(m1.getRows(), 3);
//   EXPECT_FALSE(m1.getRows() == 4);
// }

// TEST(AccessorMutator4, SetColsTest) {
//   S21Matrix m1(3, 4);
//   m1.setCols(3);
//   EXPECT_EQ(m1.getCols(), 3);
//   EXPECT_FALSE(m1.getCols() == 4);
// }

// TEST(AccessorMutator5, MinusTest) {
//   S21Matrix m1(2, 2), m2(2, 2), m3(2, 2);
//   double arr[] = {2.4, 5.8,   3.2,  333.89, 3.6,  -5.8,
//                   3.8, -0.89, -1.2, 11.6,   -0.6, 334.78};
//   int t1 = 0, t2 = 4, t3 = 8;
//   for (int i = 1; i < 2; i++) {
//     for (int j = 1; j < 2; j++) {
//       m1(i, j) = arr[t1];
//       m2(i, j) = arr[t2];
//       m3(i, j) = arr[t3];
//       t1++;
//       t2++;
//       t3++;
//     }
//   }
//   ASSERT_TRUE(m1 - m2 == m3);
// }

// TEST(AccessorMutator6, PlusEqualTest) {
//   S21Matrix m1(2, 2), m2(2, 2), m3(2, 2);
//   for (int i = 1; i < 2; ++i) {
//     for (int j = 1; j < 2; ++j) {
//       m1(i, j) = i * j * 6.6;
//       m2(i, j) = i * j * 7.7;
//       m3(i, j) = i * j * (6.6 + 7.7);
//     }
//   }
//   m1 += m2;
//   ASSERT_TRUE(m1 == m3);
// }

// TEST(AccessorMutator7, MinusEqualTest) {
//   S21Matrix m1(2, 2), m2(2, 2), m3(2, 2);
//   for (int i = 1; i < 2; ++i) {
//     for (int j = 1; j < 2; ++j) {
//       m1(i, j) = i * j * 6.6;
//       m2(i, j) = i * j * 7.7;
//       m3(i, j) = i * j * (6.6 - 7.7);
//     }
//   }
//   m1 -= m2;
//   ASSERT_TRUE(m1 == m3);
// }

// TEST(Method, Transpose) {
//   S21Matrix m1(3, 3), m2(3, 3);
//   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 4, 7, 2, 5, 8, 3, 6, 9};
//   int tmp = 0;
//   for (int i = 0; i < 3; i++) {
//     for (int j = 0; j < 3; j++) {
//       m1(i, j) = arr[tmp];
//       tmp++;
//     }
//   }
//   for (int i = 0; i < 3; i++) {
//     for (int j = 0; j < 3; j++) {
//       m2(i, j) = arr[tmp];
//       tmp++;
//     }
//   }
//   S21Matrix m3(m1.Transpose());
//   ASSERT_TRUE(m3 == m2);
// }

// TEST(Method, Complements) {
//   S21Matrix m1(4, 5);
//   EXPECT_ANY_THROW(m1.CalcComplements());
// }

// TEST(Method, Complements2) {
//   int n = 1, add = 1;
//   S21Matrix m1(3, 3), res1(3, 3), test1(2, 2);
//   for (int i = 0; i < 3; i++) {
//     for (int j = 0; j < 3; j++) {
//       m1(i, j) = n;
//       n += add;
//     }
//   }
//   test1 = m1.CalcComplements();
//   res1(0, 0) = -3;
//   res1(0, 1) = 6;
//   res1(0, 2) = -3;
//   res1(1, 0) = 6;
//   res1(1, 1) = -12;
//   res1(1, 2) = 6;
//   res1(2, 0) = -3;
//   res1(2, 1) = 6;
//   res1(2, 2) = -3;
//   EXPECT_EQ(true, test1.EqMatrix(res1));
// }

// TEST(Method, Determinant) {
//   double arr[] = {9.9, 2, 3, 4, 5, 6, 7, 8, 9};
//   int tmp = 0;
//   S21Matrix m1(3, 3);
//   for (int i = 1; i < 3; i++) {
//     for (int j = 1; j < 3; j++) {
//       m1(i, j) = arr[tmp];
//       tmp++;
//     }
//   }
//   double m2;
//   m2 = m1.Determinant();
//   EXPECT_EQ(0, m2);

//   S21Matrix m3(4, 5);
//   EXPECT_ANY_THROW(m3.Determinant());
// }

// TEST(DeterminantTest, MethodTest) {
//   S21Matrix a(1, 1);
//   a(0, 0) = 9;
//   ASSERT_NEAR(a.Determinant(), 9, 1e-7);
// }

// TEST(Methods, Inverse) {
//   S21Matrix m1(3, 3);
//   double arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//   int tmp = 0;
//   for (int i = 1; i < 3; i++) {
//     for (int j = 1; j < 3; j++) {
//       m1(i, j) = arr[tmp];
//       tmp++;
//     }
//   }
//   EXPECT_ANY_THROW(m1.InverseMatrix());
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}