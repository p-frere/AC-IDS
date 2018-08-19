cmake_minimum_required(VERSION 3.10)
project(acids C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_executable(acids
        cmake/FindPcap.cmake
        log.txt
        menu.c
        portScan.c
        processScan.c
        queueScan.c
        queueScan.h
        queuetest.c
        sts_queue.c
        sts_queue.h
        test.c)

include(FindPkgConfig)
find_package(Pcap REQUIRED)
include_directories(${PCAP_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${PCAP_LIBRARY})