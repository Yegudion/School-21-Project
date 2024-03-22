# Simple Docker


## Part 1. Готовый докер
![Simple Docker](Part_1/01_01.png) 
Скриншот 1 - Взят официальный докер образ с **nginx** и выкачай его при помощи `docker pull`"
#
![Simple Docker](Part_1/01_02.png) 
Скриншот 2 - Проверка наличия докер образа через `docker images`"
#
![Simple Docker](Part_1/01_04.png) 
Скриншот 3 - Запуск докер образа через `docker run -d [image_id|repository]`
#
![Simple Docker](Part_1/01_04.png) 
Скриншот 4 - Проверка, что образ запустился через `docker ps`
#
![Simple Docker](Part_1/01_06.png) 
Скриншот 5 - Посмотр информации о контейнере через `docker inspect [container_id|container_name]`
#
![Simple Docker](Part_1/01_07.png) 
Скриншот 6 - Размер контейнера
#
![Simple Docker](Part_1/01_08.png) 
Скриншот 7 - Список замапленных портов
#
![Simple Docker](Part_1/01_09.png) 
Скриншот 8 -  ip контейнера
#
![Simple Docker](Part_1/01_10.png) 
Скриншот 9 - Остановка докер образ через `docker stop [container_id|container_name]`
#
![Simple Docker](Part_1/01_11.png) 
Скриншот 10 - Проверка, что образ остановился через `docker ps`
#
![Simple Docker](Part_1/01_12.png) 
Скриншот 11 - Запуск докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду *run*
#
![Simple Docker](Part_1/01_13.png) 
Скриншот 12 - Проверка, что в браузере по адресу *localhost:80* доступна стартовая страница **nginx**
#
![Simple Docker](Part_1/01_14.png) 
Скриншот 13 - Перезапуск докер контейнер через `docker restart [container_id|container_name]`
#
![Simple Docker](Part_1/01_15.png) 
Скриншот 14 - Проверка любым способом, что контейнер запустился

## Part 2. Операции с контейнером
![Simple Docker](Part_2/02_01.png) 
Скриншот 15 - Прочитать конфигурационный файл *nginx.conf* внутри докер контейнера через команду *exec*
#
![Simple Docker](Part_2/02_02.png) 
![Simple Docker](Part_2/02_03.png) 
Скриншот 16 - 17 - Создан на локальной машине файл *nginx.
#
![Simple Docker](Part_2/02_04.png) 
Скриншот 18 - Настройка в нем по пути */status* отдачу страницы статуса сервера **nginx**
#
![Simple Docker](Part_2/02_05.png) 
Скриншот 19 - Скопирован созданный файл *nginx.conf* внутрь докер образа через команду `docker cp`
#
![Simple Docker](Part_2/02_06.png) 
Скриншот 20 - Перезапуск **nginx** внутри докер образа через команду *exec*
#
![Simple Docker](Part_2/02_07.png) 
Скриншот 21 - Проверь, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**
#
![Simple Docker](Part_2/02_08.png) 
Скриншот 22 - Экспорт контейнера в файл *container.tar* через команду *export*
#
![Simple Docker](Part_2/02_09.png) 
Скриншот 23 -   Остановка контейнер
#
![Simple Docker](Part_2/02_10.png) 
Скриншот 24 - Удали образ через `docker rmi [image_id|repository]`, не удаляя перед этим контейнеры
#
![Simple Docker](Part_2/02_11.png) 
Скриншот 25 - Удалиение остановленного контейнера
#
![Simple Docker](Part_2/02_12.png) 
Скриншот 26 - Импортирт контейнера обратно через команду *import*
#
![Simple Docker](Part_2/02_13.png) 
Скриншот 27 - Запуск импортированного контейнера
#
![Simple Docker](Part_2/02_14.png) 
Скриншот 28 - Проверка что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**
#

## Part 3. Мини веб-сервер
![Simple Docker](Part_3/03_01.png) 
Скриншот 29 - Код для вывода Hellow World!
#
![Simple Docker](Part_3/03_02.png) 
Скриншот 30 - Создан на локальной машине файл *nginx.
#
![Simple Docker](Part_3/03_03.png) 
Скриншот 31 - Запуск докера с портом 81
#
![Simple Docker](Part_3/03_05.png) 
Скриншот 33 - Копирование файлов на докер
#
![Simple Docker](Part_3/03_055.png) 
Скриншот 34 - Вход внутрь докера
#
![Simple Docker](Part_3/03_06.png) 
Скриншот 35 - Компиляция и запуск кода
#
![Simple Docker](Part_3/03_07.png) 
Скриншот 36 - Вывод порат 81 на localhost
#
![Simple Docker](Part_3/03_08.png) 
Скриншот 37 - Положи файл *nginx.conf* по пути *./nginx/nginx.conf* (это понадобится позже)
#

## Part 4. Свой докер
- Написать свой докер образ, который:
##### 1) собирает исходники мини сервера на FastCgi из [Части 3](#part-3-мини-веб-сервер)
##### 2) запускает его на 8080 порту
##### 3) копирует внутрь образа написанный *./nginx/nginx.conf*
##### 4) запускает **nginx**.

![Simple Docker](Part_4/04_01.png) 
<!-- Скриншот 38 - Код для вывода Hellow World! -->
![Simple Docker](Part_4/04_02.png) 
<!-- Скриншот 39 - Создан на локальной машине файл *nginx. -->
![Simple Docker](Part_4/04_03.png) 
Скриншот 38 - 40 - Подготовка файлов для создания docker образа
#
![Simple Docker](Part_4/04_04.png) 
Скриншот 41 - Сборка написанного докер образ через `docker build` при этом указав имя и тег
#
![Simple Docker](Part_4/04_05.png) 
Скриншот 42 - Проверка через `docker images`, что все собралось корректно
![Simple Docker](Part_4/04_07.png) 
Скриншот 43 - Запуск собранного докер образ с маппингом 81 порта на 80 на локальной машине и маппингом папки *./nginx* внутрь контейнера по адресу, где лежат конфигурационные файлы **nginx**'а
#
![Simple Docker](Part_4/04_08.png) 
Скриншот 44 - Перезапуск докер образ
#
![Simple Docker](Part_4/04_06.png) 
Скриншот 44 - Вывод localhost/status
#

## Part 5. **Dockle**
![Simple Docker](Part_5/05_01.png) 
Скриншот 45 - Сканирование образа из предыдущего задания через `dockle [image_id|repository]`
#
![Simple Docker](Part_5/05_06.png) 
Скриншот 46 - Исправление ошибок
#
![Simple Docker](Part_5/05_02.png) 
Скриншот 47 - Повторная сборка образа
![Simple Docker](Part_5/05_05.png) 
Скриншот 48 - Успех, ошибок не найдено!
#

## Part 6. Базовый **Docker Compose**
![Simple Docker](Part_6/06_01.png) 
Скриншот 49 - Проверка рабочих docker серверов
#
![Simple Docker](Part_6/06_02.png) 

![Simple Docker](Part_6/06_03.png) 
Скриншот 50-51 - Сбор и запуск проекта с помощью команд `docker-compose build` и `docker-compose up`
##### Проверь, что в браузере по *localhost:80* отдается написанная тобой страничка, как и ранее
![Simple Docker](Part_6/06_04.png) \
Скриншот 52 - Успех!
#

