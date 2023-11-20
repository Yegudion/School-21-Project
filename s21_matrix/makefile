CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -g
SOURCES=s21_matrix.c s21_arithmetics.c s21_comparison.c s21_support_functions.c s21_transformation.c
OBJECTS=$(SOURCES:.c=.o)
OS = $(shell uname)
TEST_FILE_NAME = s21_test_matrix.c

ifeq ($(OS), Linux)
	TEST_LIBS=-lcheck -lsubunit
else
	TEST_LIBS=-lcheck
endif

all: s21_matrix.a

s21_matrix.a: clean $(OBJECTS)
	ar -rcs s21_matrix.a $(OBJECTS)
	rm -f *.o

test: $(TEST_FILE_NAME) s21_matrix.a
	$(CC) $(CFLAGS) $(TEST_FILE_NAME) $(SOURCES) -o test $(TEST_LIBS) -L. --coverage
	./test

style: clean
	clang-format --style=google -i s21_*.c *.h
	clang-format --style=google -n s21_*.c *.h

leaks: test
	CK_FORK=no leaks --atExit --list -- ./test

gcov_report: test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css test report *.txt test.info test.dSYM proj