cmake_minimum_required(VERSION 3.26)
project(1040_CH5_PracticeProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(1040_CH5_PracticeProject main.cpp
        Airport/Airport.cpp
        Airport/Airport.h
        Flight/Flight.cpp
        Flight/Flight.h
        Crew/Pilot/Pilot.cpp
        Crew/Pilot/Pilot.h
        Crew/Crew.cpp
        Crew/Crew.h
        Crew/Attendant/Attendant.cpp
        Crew/Attendant/Attendant.h
)
