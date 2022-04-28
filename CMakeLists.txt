cmake_minimum_required(VERSION 3.22)
project(AirlineTicketSales)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp check_num.h

        data/tickets.cpp data/tickets.h
        data/airplane.cpp data/airplane.h
        data/date.cpp data/date.h
        data/flight.cpp data/flight.h

#        user/standard_user.cpp user/standard_user.h
#        user/admin.cpp user/admin.h
#        user/user.cpp user/user.h
#        user/validation_user.cpp user/validation_user.h

        password/password.cpp password/password.h
        password/sha256.cpp password/sha256.h

        data/ticket_purchase.cpp data/ticket_purchase.h
        data/validation_data.cpp data/validation_data.h

        reader/reader.cpp
        user_accounts/user.cpp user_accounts/user.h
        user_accounts/admin_functional.cpp user_accounts/admin_functional.h)

add_executable(AirlineTicketSales ${SOURCE_FILES})

