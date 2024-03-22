#!/bin/bash

# Генерация случайного IP-адреса
function random_ip() {
    printf "%d.%d.%d.%d" "$((RANDOM % 256))" "$((RANDOM % 256))" "$((RANDOM % 256))" "$((RANDOM % 256))"
}


# Создание логов по дням
function create_log() {
    for day in {1..5}; do
        log_file="$day.log"
        touch "$log_file"
        num_records=$((RANDOM % 901 + 100))

        for ((record = 1; record <= num_records; record++)); do
            # Получаем все элементы одного лога
            ip=$(random_ip)
            response_code=${response_codes[$((RANDOM % ${#response_codes[@]}))]} 
            method=${methods[$((RANDOM % ${#methods[@]}))]}
            url=${urls[$((RANDOM % ${#urls[@]}))]}
            timestamp=$(date -u -d "2023-04-$day $((RANDOM % 24)):$((RANDOM % 60)):$((RANDOM % 60))" +[%d/%b/%Y:%H:%M:%S\ %z])
            agent=${agents[$((RANDOM % ${#agents[@]}))]}

            # Записываем все элементы в файл
            echo "$ip - - $timestamp \"$method $url HTTP/1.1\" $response_code 512 \"$url\" \"$agent\"" >> "$log_file"
        done

        # Сортировка логов по дате и времени
        sort -k 4 -o "$log_file" "$log_file"

    done
}