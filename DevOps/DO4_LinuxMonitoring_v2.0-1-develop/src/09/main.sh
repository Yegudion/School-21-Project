#!/bin/bash

output_file="/usr/share/nginx/html/metrics.html"

source ./functions.sh 

# Цикл для автоматической работы с задержкой
while true; do
    myex_cpu="$(cat /proc/loadavg | awk '{print $1}')"
    myex_ram="$(free | head -2 | tail -1 | awk '{print $2}')"
    myex_ram_us="$(free | head -2 | tail -1 | awk '{print $3}')"
    myex_space_avail="$(df /| grep / | awk '{print $4}')"
    myex_space_us="$(df /| grep / | awk '{print $3}')"
    

    echo -n "" > $output_file

    print_metric "myex_cpu" $myex_cpu
    print_metric "myex_ram" $myex_ram
    print_metric "myex_ram_us" $myex_ram_us
    print_metric "myex_space_avail" $myex_space_avail
    print_metric "myex_space_us" $myex_space_us
    
    echo "[$(date +%s)] Program working..."
    sleep 3
done