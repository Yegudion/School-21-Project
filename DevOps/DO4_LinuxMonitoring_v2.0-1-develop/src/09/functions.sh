#!/bin/bash

# Создание html файла
function print_metric() {
    echo "# TYPE $1 gauge" >> "$output_file"
    echo "$1 $2" >> "$output_file"
}
