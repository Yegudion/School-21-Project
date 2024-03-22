FROM nginx
WORKDIR /home/
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./mini_server.c .
COPY ./run_miniserver.sh .
RUN apt update && apt install -y gcc spawn-fcgi libfcgi-dev
ENTRYPOINT ["sh", "./run_miniserver.sh"]

