cmake_minimum_required(VERSION 3.5)

project (oop_exercise_01)

set(SOURCES
    Complex.cpp
    main.cpp
)

add_executable(oop_exercise_01 ${SOURCES})

target_include_directories(oop_exercise_01
    PRIVATE 
        ${PROJECT_SOURCE_DIR}
)

