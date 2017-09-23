set(GOOGLE_TEST_SOURCE_DIR lib/googletest)

add_subdirectory(${GOOGLE_TEST_SOURCE_DIR})
include_directories(${GOOGLE_TEST_SOURCE_DIR}/googletest/include)
include_directories(${GOOGLE_TEST_SOURCE_DIR}/googlemock/include)

file(GLOB_RECURSE TEST_FILES tests/*.cpp)
add_executable(runBitsetContainerTests main.cpp ${TEST_FILES})

target_link_libraries(runBitsetContainerTests gtest gtest_main BitsetContainer)

add_test(UnitTests runBitsetContainerTests)