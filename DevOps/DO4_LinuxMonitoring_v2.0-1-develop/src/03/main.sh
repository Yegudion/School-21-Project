#!/bin/bash

source ./functions.sh
source ./check.sh


check_input $# $1

case $1 in
    1)
        delete_by_log
        ;;
    2)
        delete_by_date
        ;;
    3)
        delete_by_mask
        ;;
esac