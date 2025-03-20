#!/bin/bash

check_command() {
    if ! command -v $1 &> /dev/null; then
        echo -e "\033[91mОшибка: Команда '$1' не найдена. Убедитесь, что она установлена.\033[0m"
        exit 1
    fi
}

local_build_and_run() {
    echo -e "\033[95mСборка основного проекта...\033[0m"
    mkdir -p build
    cd build
    cmake ..
    make
    echo -e "\033[95mРезультат выполнения программы:\033[0m"
    ./main
    cd ..

    echo -e "\033[95mСборка тестов...\033[0m"
    mkdir -p build-tests
    cd build-tests
    cmake ../tests
    make
    echo -e "\033[95mРезультат тестов:\033[0m"
    ./run_tests
    cd ..
}

docker_build_and_run() {
    echo -e "\033[95mСборка Docker-образа...\033[0m"
    docker build -t my_cpp_project .

    echo -e "\033[95mЗапуск основного приложения в Docker...\033[0m"
    docker run -it --rm my_cpp_project ./build/main

    echo -e "\033[95mЗапуск тестов в Docker...\033[0m"
    docker run -it --rm my_cpp_project ./build-tests/run_tests
}

clean_build() {
    echo -e "\033[95mОчистка папок build и build-tests...\033[0m"
    rm -rf build build-tests
    echo -e "\033[92mОчистка завершена.\033[0m"
}

if [ "$1" == "docker" ]; then
    check_command docker  
    docker_build_and_run
elif [ "$1" == "clean" ]; then
    clean_build
else
    check_command cmake 
    local_build_and_run
fi
