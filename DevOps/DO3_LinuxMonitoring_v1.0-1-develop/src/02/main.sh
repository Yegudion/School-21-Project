#!/bin/bash

source ./functions.sh


echo "HOSTNAME: $HOSTNAME"
echo "TIMEZONE: $(get_timezone)"
echo "USER: $(whoami)"
echo "OS: $(get_os_name)"
echo "DATE: $(date +"%d %b %Y %T")"
echo "UPTIME: $(uptime -p)"
echo "UPTIME_SEC: $(awk '{print int($1)}' /proc/uptime)"
echo "IP: $(get_ip)"
echo "MASK: $(get_mask)"
echo "GATEWAY: $(get_gateway)"
echo "RAM_TOTAL = $(get_ram_gb)"
echo "RAM_USED = $(get_ram_used)"
echo "RAM_FREE = $(get_ram_free)"
echo "SPACE_ROOT = $(get_space_root)"
echo "SPACE_ROOT_USED = $(get_space_root_used)"
echo "SPACE_ROOT_FREE = $(get_space_root_free)"

read -p "Хотите ли сохранить данные в файл?(Y/N)" choice

if [[ ${choice} =~ ^[Yy]$ ]]; then

  filename="$(date +'%d_%m_%y_%H_%M_%S').status"
  {
    echo "HOSTNAME: $HOSTNAME"
    echo "TIMEZONE: $(get_timezone)"
    echo "USER: $(whoami)"
    echo "OS: $(get_os_name)"
    echo "DATE: $(date +"%d %b %Y %T")"
    echo "UPTIME: $(uptime -p)"
    echo "UPTIME_SEC: $(awk '{print int($1)}' /proc/uptime)"
    echo "IP: $(get_ip)"
    echo "MASK: $(get_mask)"
    echo "GATEWAY: $(get_gateway)"
    echo "RAM_TOTAL = $(get_ram_gb)"
    echo "RAM_USED = $(get_ram_used)"
    echo "RAM_FREE = $(get_ram_free)"
    echo "SPACE_ROOT = $(get_space_root)"
    echo "SPACE_ROOT_USED = $(get_space_root_used)"
    echo "SPACE_ROOT_FREE = $(get_space_root_free)"
  } >"${filename}"
  echo "Данные сохранены в файл: ${filename}"
else
  echo "Данные не сохранены"
fi
