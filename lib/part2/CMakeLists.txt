set(HEADER_FILES inc/calculator.h inc/node.h inc/queue.h inc/stack.h)

set(SOURCE_FILES src/calculator.cpp src/queue.cpp src/stack.cpp)

include_directories(inc)

add_library(part2_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})