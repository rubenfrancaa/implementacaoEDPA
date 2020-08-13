cmake_minimum_required(VERSION 3.17)
project(implementacaoEDPA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(implementacaoEDPA
        2723.c
        Definicoes_Implementacoes.md
        "EDPA - 1696.c"
        README.md)
