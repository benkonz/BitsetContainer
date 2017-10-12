cmake_minimum_required(VERSION 3.2.2)
project(BitsetContainer)

set(CMAKE_CXX_STANDARD 11)

include(GNUInstallDirs)

set(SOURCE_FILES include/library.h)
include_directories(include/)

add_library(BitsetContainer INTERFACE)

target_sources(BitsetContainer INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/BitsetContainer/BitsetContainer.hpp>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/BitsetContainer/BitsetContainer.hpp>
)
target_include_directories(BitsetContainer INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(TARGETS BitsetContainer EXPORT BitsetContainerConfig)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT BitsetContainerConfig DESTINATION share/BitsetContainer/cmake)
export(TARGETS BitsetContainer FILE BitsetContainerConfig.cmake)

enable_testing()
add_subdirectory(test)