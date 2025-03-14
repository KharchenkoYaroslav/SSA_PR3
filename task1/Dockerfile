FROM debian:latest

RUN apt-get update && apt-get install -y \
    procps \
    util-linux \
    && rm -rf /var/lib/apt/lists/*

CMD ["/bin/bash"]