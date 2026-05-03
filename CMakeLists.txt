cmake_minimum_required(VERSION 4.0)
project(Real_State_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(Real_State_system main.cpp
        admin.cpp
        user.cpp
        User.h
        Listings.cpp
        Listings.h
        menues.cpp)
