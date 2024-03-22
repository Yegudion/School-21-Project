#!/bin/bash


function get_timezone() {
    timezone=$(timedatectl | grep "Time zone")
    timezone=${timezone/Time zone: /}

    timezone1=$(echo $timezone | awk '{print $1}' )
    timezone2=$(echo $timezone | awk '{print $3}' )

    timezone2=${timezone2/'00)'/}
    if [ "$(echo $timezone2 | grep -e '+0' -e '-0')" != "" ]; then
        timezone2=${timezone2/'0'/}
    fi

    timezone_res="$timezone1 UTS $timezone2"
    echo $timezone_res
}


function get_os_name() {
  if [ -f /etc/os-release ]; then
    # Используем /etc/os-release, если он есть
    source /etc/os-release
    echo $PRETTY_NAME
  elif [ -f /etc/lsb-release ]; then
    # Используем /etc/lsb-release если первого файла не существует
    source /etc/lsb-release
    echo $DISTRIB_DESCRIPTION
  else
    echo "Unknown"
  fi
}



function get_ip(){ 
  ip_addr=$(ip a | grep -e "scope global" | awk '{print $2}')
  ip_addr=${ip_addr/'/'/ }
  echo $ip_addr | awk '{print $1}'
}


function get_mask() {
  ip_addr=$(ip a | grep -e "scope global" | awk '{print $2}')
  echo $(ipcalc $ip_addr | grep -e "Netmask:" | awk '{print $2}')
}

function get_gateway() {
  local gateway=$(ip route show default | awk '/default/{print $3}')
  echo "${gateway}"
}


function get_ram_gb() {
  local ram_kb=$(grep -i 'memtotal' /proc/meminfo | awk '{print $2}')
  local ram_gb=$(echo "scale=3; $ram_kb/1024/1024")
  echo "$ram_gb GB"
}


function get_ram_used() {
  local ram_used=$(free | awk '/Mem:/ {printf("%.3f", $3/1024/1024);}')
  echo "${ram_used} GB"
}

function get_ram_free() {
  local ram_free=$(free | awk '/Mem:/ {printf("%.3f", $4/1024/1024);}')
  echo "${ram_free} GB"
}

function get_space_root() {
  local space_root=$(df -BM / | awk 'NR==2{print $2}' | sed 's/M//')
  echo "${space_root} MB"
}

function get_space_root_used() {
  local space_root_used=$(df -BM / | awk 'NR==2{print $3}' | sed 's/M//')
  echo "${space_root_used} MB"
}

function get_space_root_free() {
  local space_root_free=$(df -BM / | awk 'NR==2{print $4}' | sed 's/M//')
  echo "${space_root_free} MB"
}