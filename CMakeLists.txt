cmake_minimum_required(VERSION 3.22)
project(AirlineTicketSales)

set(CMAKE_CXX_STANDARD 17)

# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

set(SOURCE_FILES main.cpp check_num.h

        data/tickets.cpp data/tickets.h
        data/airplane.cpp data/airplane.h
        data/date.cpp data/date.h
        data/flight.cpp data/flight.h

        password/password.cpp password/password.h
        password/sha256.cpp password/sha256.h

        data/ticket_purchase.cpp data/ticket_purchase.h
        data/validation_data.cpp data/validation_data.h

        reader/reader.cpp

        user_accounts/user.cpp user_accounts/user.h
        user_accounts/admin_functional.cpp user_accounts/admin_functional.h


        core.cpp core.h

        appearance/menues.cpp appearance/menues.h
        appearance/width.h appearance/width.cpp
        appearance/colors.h appearance/colors.cpp

        )

add_executable(AirlineTicketSales ${SOURCE_FILES})

