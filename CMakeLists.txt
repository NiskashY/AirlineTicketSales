cmake_minimum_required(VERSION 3.22)
project(AirlineTicketSales)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp

        data/tickets.cpp data/tickets.h
        data/airplane.cpp data/airplane.h
        data/date.cpp data/date.h
        data/flight.cpp data/flight.h

        user/standard_user.cpp user/standard_user.h
        user/admin.cpp user/admin.h user/user.cpp user/user.h)

add_executable(AirlineTicketSales ${SOURCE_FILES})

