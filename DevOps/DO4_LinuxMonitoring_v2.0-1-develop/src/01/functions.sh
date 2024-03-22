#!/bin/bash


# Возвращает название папки
function generate_DIR_name(){
    local result="$1"
    local num=$2
    local last_char=${result: -1}

    for ((i=0; i<$num; i++)); do
        result="${result}$last_char"
    done
    
    result="${result}_${current_date}"
    echo $result
}

# Возвращает название файла
function generate_FL_name(){
    local filename=$1
    local num=$2
    local name="${filename%.*}"
    local ext="${filename##*.}"
    local last_char="${name: -1}"
    for ((i=0; i<$num; i++)); do
        name="${name}$last_char"
    done

    name="${name}_${current_date}.${ext}"
    echo $name
}

# Создает директорию
function genetane_DIR() {
    local DIR_PATH=$1
    local DIR_NAME=$2

    if [ ! -d "${DIR_PATH}/${DIR_NAME}" ]; then
        mkdir "${DIR_PATH}/${DIR_NAME}"
        echo -e "${DIR_PATH}/${DIR_NAME} ${current_date}" >> $LOG_FILE
        return 0
    else
        return 1
    fi
}

# Создает файл
function generate_FILE() {
    local FL_PATH=$1
    local FL_NAME=$2
    local FL_SIZE=$3

    if [ ! -f "${FL_PATH}/${FL_NAME}" ]; then
        touch "${FL_PATH}/${FL_NAME}"
        fallocate -l $FL_SIZE "${FL_PATH}/${FL_NAME}"
        echo -e "${FL_PATH}/${FL_NAME} ${current_date} $FL_SIZE" >> $LOG_FILE
        return 0
    else
        return 1
    fi
}

# создание всех файлов
function generate_FILES() {
    local FL_PATH=$1
    local FL_NUM=$2
    local FL_APL=$3
    local FL_SIZE=$4
    local FL_NAME

    for ((j=0; j<$FL_NUM; j++)); do
        FREE_SPACE=$(df -k / | awk '{print $4}' | tail -n 1)
        
        if [[ $FREE_SPACE -le 1048576 ]]; then
            echo "Ошибка: свободного места меньше 1 гигабайта"
            exit 1
        else

            FL_NAME=$(echo $(generate_FL_name $FL_ALP $j))
            generate_FILE ${FL_PATH} ${FL_NAME} "$FL_SIZE"
            if [ $? -eq 1 ]; then 
                ((FL_NUM++))
            fi
        fi
    done
}

#Главная функция создания
function generate() {
    local DIR_PATH=$1
    local DIR_NUM=$2
    local DIR_ALP=$3
    local FL_NUM=$4
    local FL_ALP=$5
    local FL_SIZE=$6
    local DIR_NAME
    
    for ((i=0; i<$DIR_NUM; i++)); do
        FREE_SPACE=$(df -k / | awk '{print $4}' | tail -n 1)
        
        if [[ $FREE_SPACE -le 1048576 ]]; then
            echo "Ошибка: свободного места меньше 1 гигабайта"
            exit 1
        else
            DIR_NAME=$(echo $(generate_DIR_name $DIR_ALP $i))
            genetane_DIR $DIR_PATH $DIR_NAME
            if [ $? -eq 1 ]; then 
                ((DIR_NUM++))
                continue
            fi
            generate_FILES "${DIR_PATH}/${DIR_NAME}" $FL_NUM $FL_ALP $FL_SIZE


        fi
    done
}