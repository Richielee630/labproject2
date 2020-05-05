set(HEADER_FILES
        inc/data_structure.h
        )

set(SOURCE_FILES
        src/data_structure.cpp
        )
include_directories(inc)
add_library(part3_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})