cmake_minimum_required(VERSION 3.17)
project(Ejercicio_Gestion_Memoria)

set(CMAKE_CXX_STANDARD 11)

find_library(KERNEL32_LIBRARY kernel32)
find_library(USER32_LIBRARY user32)

if(NOT KERNEL32_LIBRARY)
    message(FATAL_ERROR "No se pudo encontrar la biblioteca kernel32")
endif()

if(NOT USER32_LIBRARY)
    message(FATAL_ERROR "No se pudo encontrar la biblioteca user32")
endif()

target_link_libraries(${Ejercicio_Gestion_Memoria} PRIVATE ${KERNEL32_LIBRARY} ${USER32_LIBRARY})

add_executable(${Ejercicio_Gestion_Memoria} main.cpp)


