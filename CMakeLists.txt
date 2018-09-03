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
        sts_queue.c
        sts_queue.h
        portScan.h watchFile.c watchFile.h detected.c detected.h consoleUtilities.c consoleUtilities.h)

include(FindPkgConfig)
find_package(Pcap REQUIRED)
include_directories(${PCAP_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${PCAP_LIBRARY})