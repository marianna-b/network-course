cmake_minimum_required(VERSION 3.6)
project(nets)

find_package(Boost 1.63 REQUIRED COMPONENTS thread system)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp dns.cpp dns.h consumer.cpp consumer.h producer.cpp producer.h utils.h utils.cpp dns_entry.cpp dns_entry.h executor.cpp executor.h executor_client.cpp executor_client.h)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(nets ${SOURCE_FILES})
    target_link_libraries(nets ${Boost_LIBRARIES})
endif()