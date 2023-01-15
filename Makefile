G =gcc -std=c++17
GCC =$(G) -Wall -Wextra -Werror -Wuninitialized  #проверка на инициализацию
LIBS =-lgtest -lgmock -pthread
LINUX=-lsubunit -lrt -lpthread -lm
OS=$(shell uname -s)

s21_matrix_oop.a:
	$(G) s21_*.cpp -c
	ar ars s21_matrix_oop.a s21_*.o


test: s21_matrix_oop.a
	$(GCC) s21_matrix_oop.a -o s21_test.cpp $(LIBS)

valgrind:
	valgrind --leak-check=full --track-origins=yes --trace-children=yes -s ./test

clang:
# cp ../materials/linters/.clang-format .clang-format
	clang-format -n s21_*.cpp s21_*.h test.cpp
	clang-format -i s21_*.cpp s21_*.h test.cpp
# cp .clang-format ../materials/linters/.clang-format

clean:
	rm -rf s21_*.o