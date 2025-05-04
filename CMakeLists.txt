cmake_minimum_required(VERSION 3.16)
project(BinPacking)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Include paths
include_directories(
    external/PhysX/physx/include
    external/PhysX/pxshared/include
    include
)

# Define static lib usage
add_definitions(-DPX_PHYSX_STATIC_LIB)

# Debug/Release macro
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-D_DEBUG)
else()
    add_definitions(-DNDEBUG)
endif()

# Link directories
link_directories("external/PhysX/physx/bin/mac.x86_64/debug")

# Add subdirectories for external dependencies
add_subdirectory(external/pybind11)
add_subdirectory(external/googletest)

# Add library for BinPackingEnv
add_library(binpacking_env src/BinPackingEnv.cpp)

# Link PhysX libraries
target_link_libraries(binpacking_env
    PhysXExtensions_static_64
    PhysX_static_64
    PhysXPvdSDK_static_64
    PhysXCommon_static_64
    PhysXFoundation_static_64
    pthread
    dl
)

# Tests
enable_testing()
add_executable(run_tests tests/test_BinPackingEnv.cpp)
target_link_libraries(run_tests PRIVATE binpacking_env gtest gtest_main)
add_test(NAME BinPackingTests COMMAND run_tests)

# Python bindings
pybind11_add_module(py_binpacking bindings/py_binpacking.cpp)
target_link_libraries(py_binpacking PRIVATE binpacking_env)
