FROM debian:latest

RUN apt-get update && apt-get install -y \
    gcc \
    make \
    libc6-dev \
    coreutils  # Для команди timeout

WORKDIR /app

COPY . .

RUN gcc -o lottery lottery.c

ENTRYPOINT ["./lottery"]




