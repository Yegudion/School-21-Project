FLAGS = -Wall -Wextra -Werror -Wuninitialized -fsanitize=address -std=c11 
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
	gcc $(FLAGS) -c $(SOURCES_FUN)
	ar rcs s21_matrix.a *.o
	@ranlib s21_matrix.a

test: s21_matrix.a
	@gcc *.c s21_matrix.a $(TESTFLAGS) -o testing 
	./testing

gcov_report:
	@gcc $(TESTFLAGS) *.c ./test/*.c -o s21_lib_test $(TESTFLAGS) ./s21_lib_test
	@gcov -f $(SOURCES_FUN)
	@lcov --no-external -t test -o coverage.info -c -d . 
	@genhtml -o html_report coverage.info
	@open html_report/index.html

lint:
	@clang-format --style=Google -i *.c *.h test/*.c test/*.h

clean:
	@rm -rf *.o testing.c testing *.a *.gcno *.gcda *.gcov *.info
	@rm -rf html_report s21_decimal s21_lib_test html_report
