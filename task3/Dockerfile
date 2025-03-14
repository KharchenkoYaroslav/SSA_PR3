FROM debian:latest

RUN apt-get update && apt-get install -y \
    gcc \
    make \
    libc6-dev 

WORKDIR /app

COPY . .  

RUN mkdir -p output  

RUN gcc -o dice_roll dice_roll.c  

ENTRYPOINT ["./dice_roll"]



