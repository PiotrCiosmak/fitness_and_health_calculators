cmake_minimum_required(VERSION 3.22)
project(fitness_and_health_calculators)

set(CMAKE_CXX_STANDARD 23)

add_executable(fitness_and_health_calculators main.cpp Tperson.hpp Tperson.cpp Tmen.cpp Tmen.hpp Twomen.cpp Twomen.hpp Tmenu.cpp Tmenu.hpp)
