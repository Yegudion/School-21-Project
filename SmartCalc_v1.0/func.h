#ifndef FUNC
#define FUNC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define INCORRECT 0

#define N 256 

//проверка и отчистка строки перед обработкой
int check_and_clean(char str[N]);

//отчистка от пробелов
void clean_space(char str[N]);

#endif
