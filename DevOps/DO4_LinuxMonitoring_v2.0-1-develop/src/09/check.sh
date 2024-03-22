#!/bin/bash

function check() {
    if [ $# != 0 ]
    then
        echo "Ошибка: неверное количество аргументов." >&2
        exit 1
    fi
}
