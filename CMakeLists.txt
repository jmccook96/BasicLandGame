cmake_minimum_required(VERSION 3.29)
project(LandGameDemo)

set(CMAKE_CXX_STANDARD 20)

add_executable(LandGameDemo main.cpp
        CardEffects.cpp
        CardEffects.h
        Card.cpp
        Card.h
        Player.cpp
        Player.h
        GameRuleDefs.h
        LandGame.cpp
        LandGame.h)
