#!/bin/bash

function option_1() {
    awk '{print $0 | "sort -n -k 9"}' $log_file
}


function option_2() {
    awk '{ if (!seen[$1]++) print $1 }' $log_file
}

function option_3() {
    awk '{
        first_digit = substr($9, 1, 1);
        if (first_digit == 4 || first_digit == 5) {
            print $0;
        }
    }' $log_file
}

function option_4() {
    awk '{
        first_digit = substr($9, 1, 1);
        if (first_digit == 4 || first_digit == 5) {
            if (!seen[$1]++) print $1;
        }
    }' $log_file
}
