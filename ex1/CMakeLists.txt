cmake_minimum_required( VERSION 3.10 )
project( complex )
add_executable( ${PROJECT_NAME} complex.h complex.cpp main.cpp )
add_executable( ${PROJECT_NAME}_archive complex.h complex.cpp main_archivo.cpp )

