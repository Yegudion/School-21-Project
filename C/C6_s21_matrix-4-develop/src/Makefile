FLAGS = -Wall -Wextra -Werror -Wuninitialized -std=c11 -g
TESTFLAGS = -lcheck --coverage 
SOURCES_FUN:=$(wildcard s21_*.c)

ifeq ($(shell uname), Linux)
TESTFLAGS += -lm -lsubunit
else
TESTFLAGS += -fprofile-arcs -ftest-coverage
endif

all: s21_matrix.a
	rm -rf *.o

s21_matrix.a:
	gcc $(FLAGS) -c s21_matrix.*
	ar rcs s21_matrix.a *.o
	@ranlib s21_matrix.a

test: clean s21_matrix.a
	@gcc *.c s21_matrix.a $(TESTFLAGS) -o testing 
	./testing

gcov_report: test
	@gcc $(TESTFLAGS) *.h *.c -o s21_lib_test $(TESTFLAGS) 
	@gcov -f $(SOURCES_FUN)
	@lcov --no-external -t test -o coverage.info -c -d . 
	@genhtml -o html_report coverage.info

lint:
	@clang-format --style=Google -i *.c *.h *.c 

clean:
	@rm -rf *.o testing.c testing *.a *.gcno *.gcda *.gcov *.info *.gch
	@rm -rf html_report s21_decimal s21_lib_test html_report
