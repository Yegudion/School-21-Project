#!/bin/bash

source ./check.sh
source ./functions.sh


check_input $# $1

export log_file=$(mktemp)
for day in {1..5}; do
    cat "../04/$day.log" >> $log_file
done

case $1 in
    1)
        option_1
        ;;
    2)
        option_2
        ;;
    3)
        option_3
        ;;
    4)
        option_4
        ;;
esac

rm $log_file