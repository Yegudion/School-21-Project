#!/bin/bash

source ./functions.sh

export response_codes=(
    "200" # OK
    "201" # CREATED
    "400" # BAD_REQUEST
    "401" # UNAUTHORIZED
    "403" # FORBIDDEN
    "404" # NOT_FOUND
    "500" # INTERNAL_SERVER_ERROR
    "501" # NOT_IMPLEMENTED
    "502" # BAD_GATEWAY
    "503" # SERVICE_UNAVAILABLE
)


# Список методов
export methods=("GET" "POST" "PUT" "PATCH" "DELETE")

# Список URL запросов
export urls=("/" "/login" "/logout" "/profile" "/register" "/api/data" "/api/info" "/private")

# Список агентов
export agents=(
    "Mozilla"
    "Google Chrome"
    "Opera"
    "Safari"
    "Internet Explorer"
    "Microsoft Edge"
    "Crawler and bot"
    "Library and net tool"
)

create_log