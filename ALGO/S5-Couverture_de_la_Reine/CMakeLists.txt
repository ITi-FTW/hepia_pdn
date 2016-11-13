cmake_minimum_required(VERSION 3.5)
project(S5_Couverture_de_la_Reine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main
    main.c
        )

add_executable(S5_Couverture_de_la_Reine ${SOURCE_FILES})
