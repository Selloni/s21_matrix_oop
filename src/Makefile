G =gcc -lstdc++
GCC =$(G) -Wall -Wextra -Werror -Wuninitialized
LIBS =-lgtest 
LINUX=-lsubunit -lrt -lpthread -lm
OS=$(shell uname -s)

ifeq ($(OS), Linux)
	LIBS+= -lgmock -pthread
endif

all: clean s21_matrix_oop.a

s21_matrix_oop.a: build_s21_matrix

build_s21_matrix:
	$(G) -c s21_*.cpp
	ar rcs s21_matrix_oop.a s21_*.o
	ranlib s21_matrix_oop.a

test: clean s21_matrix_oop.a
	$(GCC) s21_matrix_oop.a gtest.cpp -o test $(LIBS)
	./test --gtest_repeat=10 --gtest_break_on_failure
	@make leak
	@make clang

gcove_report: clean
	$(GCC) --coverage gtest.cpp s21_*.cpp -o test $(LIBS)
	chmod +x *
	./test
	lcov -t "test" -o test.info --no-external -c -d .
	genhtml -o report/ test.info
	open ./report/index.html

clang:
#@echo -------------------CLANG_FORMAT-----------------------
#clang-format -style=Google -dump-config > .clang-format
#clang-format -n s21_*.cpp s21_*.h gtest.cpp
#clang-format -i s21_*.cpp s21_*.h gtest.cpp
#@rm .clang-format

leak:
	@echo --------------------MEMORY_LEAKS-----------------------
	@$(GCC) gtest.cpp s21_*.cpp -lgtest -o leaks -g
	CK_FORK=no leaks --atExit -- ./leaks
	@rm ./leaks

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
	@rm -rf *.dSYM

git:
	open 'https://github.com/Selloni'

build: stop
	docker build -t grandpat:latest .
	docker run -it --name my grandpat bash

stop:
	docker stop my
	docker rm my
	docker system prune -a --volumes
