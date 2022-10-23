cmake_minimum_required(VERSION 3.21)
project(zzz_final C)

set(CMAKE_C_STANDARD 11)

include_directories(login)
include_directories(ques)

add_executable(zzz_final
        login/login.c
        login/login.h
        ques/ques.c
        ques/ques.h
        main.c)
