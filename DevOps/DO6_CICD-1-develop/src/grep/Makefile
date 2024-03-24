CC=gcc -Wall -Werror -Wextra 

all: s21_grep

s21_grep : s21_grep.h s21_grep.c
	$(CC) s21_grep.c -o s21_grep

rebuild :
	make clean
	make all

test:
	bash test_grep.sh

clean :
	rm -f s21_grep

clang :
	clang-format -n *.c *.h
	clang-format -i *.c *.h
	