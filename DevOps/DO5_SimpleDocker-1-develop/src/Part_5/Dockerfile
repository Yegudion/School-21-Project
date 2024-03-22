FROM nginx
WORKDIR /home/
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./mini_server.c .
COPY ./run_miniserver.sh .


RUN apt-get update && apt-get install -y gcc spawn-fcgi libfcgi-dev; \
    rm -rf /var/lib/apt/lists
USER nginx
ENTRYPOINT ["sh", "./run_miniserver.sh"]

