#!/bin/bash

# Обявление "глобальных" перменных для удобной работы
export current_date=$(date +%d%m%y)
export FREE_SPACE=$(df -k / | awk '{print $4}' | tail -n 1)
export LOG_FILE="main.log"


source ./functions.sh
source ./check.sh


check_input "$1" "$2" "$3" "$4" "$5" "$6"
generate "$1" "$2" "$3" "$4" "$5" "$6"

column -t $LOG_FILE > temp_file.txt && mv temp_file.txt $LOG_FILE
