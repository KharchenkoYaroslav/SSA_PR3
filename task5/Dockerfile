FROM debian:latest

RUN apt-get update && apt-get install -y \
    gcc \
    make \
    libc6-dev 

WORKDIR /app

COPY . .

RUN gcc -o copy copy.c

ENTRYPOINT ["/app/entrypoint.sh"]




