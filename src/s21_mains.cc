// #include "s21_matrix_oop.h"
// #include <iostream>
// using namespace std;

// int main () {

//   S21Matrix tmp(3, 3);
//   S21Matrix str(2, 2);
//   tmp.setCols(2);
//   tmp.setRows(2);
//   if (tmp == str) {
//     cout << 'y';
//   } else {
//     cout << 'n';
//   }
  
//   return 0;

// }m

// #include <string>
// #include <regex>
// using namespace std;

// int getCount(const string& inputStr){
//   int num_vowels = 0;
//   smatch m;
//   for (char i : inputStr) {
//     if (regex_search(i, m, regex("[aeiou]"))) num_vowels++;
//   }
//   return num_vowels;
// }