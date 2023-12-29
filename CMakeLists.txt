cmake_minimum_required(VERSION 3.27)
project(libmumble_server VERSION 0.0.1)

# Use libc++ instead of libstdc++ (Clang only)
if (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
    option(USE_LIBCPP "Use libc++ as C++ standard library" OFF)
    if (USE_LIBCPP)
        add_compile_options(-stdlib=libc++)
    endif ()
endif ()

include(GNUInstallDirs)

set(BOOST_REQUIRED_VERSION 1.71)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(mumble_protocol)

add_subdirectory(library)

add_subdirectory(app)

enable_testing()
add_subdirectory(test)
