cmake_minimum_required(VERSION 3.0.0)
project(asysy VERSION 0.0.0)

include(CTest)
enable_testing()

set (CMAKE_CXX_STANDARD 11)

add_executable(asysy main.cc)
target_link_libraries(asysy czmq)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
