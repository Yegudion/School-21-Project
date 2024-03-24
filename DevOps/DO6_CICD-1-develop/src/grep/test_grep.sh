#!/bin/bash
#1
./s21_grep -e 127 s21_grep.c >> s21_grep.txt
grep -e 127 s21_grep.c >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
#2 -i
./s21_grep -i e s21_grep.c >> s21_grep.txt
grep -i e s21_grep.c >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #3 -c
./s21_grep -c e s21_grep.c > s21_grep.txt
grep -c e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #4 -l
./s21_grep -l e s21_grep.c s21_grep.c s21_grep.c > s21_grep.txt
grep -l e s21_grep.c s21_grep.c s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #5 -n
./s21_grep -n e s21_temp.txt s21_de.txt > s21_grep.txt
grep -n e s21_temp.txt s21_de.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #6 -h
./s21_grep -h e s21_grep.c > s21_grep.txt
grep -h e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #7 -s
./s21_grep -s e s21_grep.c > s21_grep.txt
grep -s e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #8 -f
./s21_grep -f s21_temp.txt s21_grep.c > s21_grep.txt
grep -f s21_temp.txt s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #9 -sn
./s21_grep int s21_grep.c s21_de.txt > s21_grep.txt
grep int s21_grep.c s21_de.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #10 -sb
./s21_grep -i int s21_grep.c > s21_grep.txt
grep -i int s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #11 -v
./s21_grep -c s s21_grep.c > s21_grep.txt
grep -c s s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #12 -ne
./s21_grep -l s s21_grep.c > s21_grep.txt
grep -l s s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #13 -ne 1
./s21_grep -l s s21_de.txt > s21_grep.txt
grep -l s s21_de.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #14 -err
./s21_grep -n s s21_de.txt > s21_grep.txt
grep -n s s21_de.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #14 -err 1
./s21_grep -n s s21_grep.c > s21_grep.txt
grep -n s s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #15 -err
./s21_grep -o 123 s21_grep.c > s21_grep.txt
grep -o 123 s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #16 -err
./s21_grep -h options s21_grep.c s21_de.txt > s21_grep.txt
grep -h options s21_grep.c s21_de.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #17 -err
./s21_grep -s grep 123123 > s21_grep.txt
grep -s grep 123123 > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #18 -err
./s21_grep -f s21_temp.txt s21_grep.c > s21_grep.txt
grep -f s21_temp.txt s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #19 -err
./s21_grep -in options s21_grep.c > s21_grep.txt
grep -in options s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #20 -err
./s21_grep -cv s s21_grep.c > s21_grep.txt
grep -cv s s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #21 -err
./s21_grep -cv s s21_grep.c s21_de.txt > s21_grep.txt
grep -cv s s21_grep.c s21_de.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #22 -err
./s21_grep -lv s s21_grep.c > s21_grep.txt
grep -lv s s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #23 -err
./s21_grep -ho int s21_temp.txt s21_de.txt > s21_grep.txt
grep -ho int s21_temp.txt s21_de.txt s21_temp.txt s21_de.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #24 -err
./s21_grep -nf s21_temp.txt s21_de.txt > s21_grep.txt
grep -nf s21_temp.txt s21_de.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt