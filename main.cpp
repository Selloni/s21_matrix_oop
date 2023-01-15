#include "s21_matrix_oop.h"
#include <iostream>
using namespace std;

int main () {
  S21Matrix max(3, 3);
  int i = max.getCols();
  cout << i << endl;
  return 0; 
}