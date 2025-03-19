# стадия 1 сборка Google Test
FROM ubuntu:22.04 AS gtest-builder

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

RUN git clone https://github.com/google/googletest.git && \
    mkdir -p googletest/build && \
    cd googletest/build && \
    cmake .. && \
    make && \
    make install

# стадия 2 сборка основного проекта
FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

COPY --from=gtest-builder /usr/local/lib /usr/local/lib
COPY --from=gtest-builder /usr/local/include /usr/local/include

RUN mkdir -p build && cd build && \
    cmake .. && \
    make

RUN mkdir -p build-tests && cd build-tests && \
    cmake ../tests && \
    make

RUN cd build-tests && ctest --output-on-failure

CMD ["./build/main"]