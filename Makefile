G =gcc -lstdc++
GCC =$(G) -Wall -Wextra -Werror -Wuninitialized  #проверка на инициализацию
LIBS =-lgtest -lgmock -pthread
LINUX=-lsubunit -lrt -lpthread -lm
OS=$(shell uname -s)

ifeq ($(OS), Darwin)
	G+= -D OS_MAC
endif
ifeq ($(OS), Linux)
	G+= -D OS_LINUX
	TESTFLAGS+= -lgmock -pthread
endif

all: clean s21_matrix_oop.a 

s21_matrix_oop.a: build_s21_matrix

build_s21_matrix:
	g++ -c s21_*.cpp
	ar rcs s21_matrix_oop.a s21_*.o
	ranlib s21_matrix_oop.a

test: clean s21_matrix_oop.a
	$(GCC) s21_matrix_oop.a gtest.cpp -o test $(LIBS)
	./test

valgrind:
	valgrind --leak-check=full --track-origins=yes --trace-children=yes -s ./test

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
	$(GCC) main.cpp s21_matrix.cpp s21_operator.cpp  -g

clean:
	@echo ".....(-_(С_С)_-)....чисто..."
	@rm -rf s21_*.o
	@rm -rf *.a
	@rm -rf a.out*
	@rm -rf test*