cmake_minimum_required(VERSION 4.0)
project(Proiect_poo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proiect_poo
        cppfiles/main.cpp
        cppfiles/Masina.cpp
        cppfiles/Customer.cpp
        cppfiles/App.cpp
        cppfiles/MasinaSport.cpp
        cppfiles/MasinaSUV.cpp
        cppfiles/MasinaElectrica.cpp
        Headers/Masina.h
        Headers/Customer.h
        Headers/App.h
        Headers/MasinaSport.h
        Headers/Exceptions.h)


