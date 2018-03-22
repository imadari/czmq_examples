cmake_minimum_required(VERSION 3.0.0)
project(scapnp VERSION 0.0.0)

include(CTest)
enable_testing()

set (CMAKE_CXX_STANDARD 11)

add_executable(scapnp main.cc)
target_link_libraries(scapnp czmq)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
