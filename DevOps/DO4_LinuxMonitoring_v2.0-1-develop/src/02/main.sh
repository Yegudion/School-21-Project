#!/bin/bash

source ./functions.sh
source ./check.sh

# Обявление "глобальных" перменных для удобной работы
export current_date=$(date +%d%m%y)
export LOG_DATE=$(date +'%Y.%m.%d-%H:%M')
export FREE_SPACE=$(df -k / | awk '{print $4}' | tail -n 1)
export LOG_FILE="main.log"
touch $LOG_FILE


check_input "$1" "$2" "$3"



# Сохраняем в переменную время начала выполнения скрипта в секундах
export start_time=$(date +%s) 
echo "Program started at ${start_time}" >> $LOG_FILE


# Отбираем все подходящие директории и считаем их количесво 
mapfile -t arr < <(find / -type d -perm -o+w 2> /dev/null | grep -v -e proc -e bin -e sbin -e Permission)
export NUMBER_DIR="${#arr[@]}"
echo "Start"


pre_generate "$1" "$2" "$3"

# Цикл пока памяти больше 1 гигабайта
while [[ $FREE_SPACE -gt 1048576 ]];
do
    pre_generate $1 $2 $3
    export FREE_SPACE=$(df -k / | awk '{print $4}' | tail -n 1)
done
column -t $LOG_FILE > temp_file.txt && mv temp_file.txt $LOG_FILE

# Сохраняем в переменную время конца выполнения скрипта в секундах
export end_time=$(date +%s)
export runtime=$((end_time-start_time))  # вычисляем время выполнения скрипта в секундах

#Вывод данных в терминал
echo "Program started at ${start_time}"
echo "Program ended at ${end_time}"
echo "Total runtime: $runtime seconds"

#И в лог файл
echo "Program started at ${start_time}" >> $LOG_FILE
echo "Program ended at ${end_time}" >> $LOG_FILE
echo "Total runtime: $runtime seconds" >> $LOG_FILE
