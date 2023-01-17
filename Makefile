G =gcc -lstdc++
# G=g++
GCC =$(G) -Wall -Wextra -Werror -Wuninitialized  #проверка на инициализацию
LIBS =-lgtest 
LINUX=-lsubunit -lrt -lpthread -lm
OS=$(shell uname -s)

ifeq ($(OS), Darwin)
	G+= -D OS_MAC
endif
ifeq ($(OS), Linux)
	G+= -D OS_LINUX
	LIBS+= -lgmock -pthread
endif

all: clean s21_matrix_oop.a 

s21_matrix_oop.a: build_s21_matrix

build_s21_matrix:
	g++ -c s21_*.cpp
	ar rcs s21_matrix_oop.a s21_*.o
	ranlib s21_matrix_oop.a

test: clean s21_matrix_oop.a
	$(GCC) -g s21_matrix_oop.a gtest.cpp -o test $(LIBS)
	./test
# --gtest_repeat=10 --gtest_break_on_failure

gcove_report: clean
	$(GCC) --coverage gtest.cpp s21_*.cpp -o test $(LIBS)
	chmod +x *
	./test
	lcov -t "test" -o test.info --no-external -c -d .
	genhtml -o report/ test.info
	open ./report/index.html

valgrind:
	valgrind --leak-check=full --track-origins=yes --trace-children=yes -s ./test

lo:
	for i in `seq 10 $(OP)`;	do ./test; done;

clang:
	@echo -------------------CLANG_FORMAT------------------------
# @cp ../materials/linters/.clang-format .clang-format
	@clang-format -n s21_*.cpp s21_*.h gtest.cpp
	@clang-format -i s21_*.cpp s21_*.h gtest.cpp
# @rm .clang-format
# @make leaks

# leak:
# 	@echo --------------------MEMORY_LEAKS-----------------------
# 	$(GCC) gtest.cpp s21_*.cpp -lgtest -o leaks -g
# 	CK_FORK=no leaks --atExit -- ./leaks
# 	@rm ./leaks

# cppcheck:
# 	cppcheck --enable=all --suppress=missingIncludeSystem *.cpp

dbg:
	$(GCC) s21_main.cpp s21_matrix.cpp s21_operator.cpp  -g

clean:
	@echo ".....(-_(С_С)_-)....чисто..."
	@rm -rf s21_*o
	@rm -rf *.a
	@rm -rf a.out*
	@rm -rf gtest.*o
	@rm -rf report
	@rm -rf test*
	@rm -rf *.gcda