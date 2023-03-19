cmake_minimum_required(VERSION 3.23)
project(CLionProjects C)

set(CMAKE_C_STANDARD 11)

include_directories(funktions)
include_directories(vendingMachineV4)

add_executable(CLionProjects
        funktions/main.c
        vendingMachineV4/main.c)
