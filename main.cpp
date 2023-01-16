#include "s21_matrix_oop.h"
#include <iostream>
using namespace std;

int main () {

  S21Matrix m1(3, 3), m2(3, 3), m3(3, 3), m4(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      m1(i, j) = 4;
      m2(i, j) = 4;
      m3(i, j) = 48;
    }
  }
  m4 = m1 * m2;
  // cout << m4(3, 3) <<  endl;
  if (m4.EqMatrix(m3)) cout << "go" ;

  return 0; 
}