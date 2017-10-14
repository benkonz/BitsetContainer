enable_testing()
find_package(GTest REQUIRED)

file(GLOB_RECURSE TEST_FILES tests/*.cpp)
add_executable(runBitsetContainerTests main.cpp ${TEST_FILES})

target_link_libraries(runBitsetContainerTests GTest::GTest GTest::Main BitsetContainer)

add_test(UnitTests runBitsetContainerTests)