CC=gcc -Wall -Werror -Wextra 

all: s21_cat

s21_cat : s21_cat.h s21_cat.c
	$(CC) s21_cat.c -o s21_cat

rebuild :
	make clean
	make all

clean :
	rm -f s21_cat

clang :
	clang-format -n *.c *.h
	clang-format -i *.c *.h
	