cmake_minimum_required(VERSION 3.31)
project(bibliography C)

set(CMAKE_C_STANDARD 11)

add_executable(bibliography main.c
        fileHandling.h
        fileHandling.c
        MenuOperation.h)
