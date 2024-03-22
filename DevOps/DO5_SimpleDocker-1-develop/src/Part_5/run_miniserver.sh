#!/bin/bash

ggc -o mini_server mini_server.c -lfcgi
spawn-fcgi -p 8080 ./mini_server
service nginx start
/bin/bash