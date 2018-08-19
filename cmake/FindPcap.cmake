set(FIND_PCAP_PATHS
        /usr/include/pcap)

find_path(PCAP_INCLUDE_DIR pcap.h
        PATH_SUFFIXES include
        PATHS ${FIND_PCAP_PATHS})

find_library(PCAP_LIBRARY
        NAMES pcap
        PATH_SUFFIXES lib
        PATHS ${FIND_PCAP_PATHS})