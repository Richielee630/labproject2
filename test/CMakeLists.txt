include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicTests
        part1_tests.cpp
        part2_tests.cpp
        part3_tests.cpp)

add_subdirectory(gtest-1.7.0)

target_link_libraries(runBasicTests gtest gtest_main)
target_link_libraries(runBasicTests part2_lib part3_lib)