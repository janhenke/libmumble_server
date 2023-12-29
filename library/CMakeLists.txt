include(GenerateExportHeader)
include(CheckIPOSupported)
# check for LTO support in the compiler, raise a fatal error is unsupported
check_ipo_supported()

# libmumble_server
add_library(
        mumble_server
        SHARED
        pimpl.hpp
        pimpl_impl.hpp
        server.cpp
        server.hpp
)

generate_export_header(mumble_server)

set_target_properties(
        mumble_server
        PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        CXX_VISIBILITY_PRESET hidden
        COMPILE_WARNING_AS_ERROR ON
        VISIBILITY_INLINES_HIDDEN ON
        POSITION_INDEPENDENT_CODE ON
        INTERPROCEDURAL_OPTIMIZATION ON
        VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
        SOVERSION 0
)

target_include_directories(
        mumble_server
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
)

target_compile_definitions(
        mumble_server
        PUBLIC ASIO_NO_DEPRECATED
)

# enable extra warnings for our code
target_compile_options(
        mumble_server
        PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
)

find_package(asio CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Threads REQUIRED)

target_link_libraries(
        mumble_server
        PRIVATE mumble_protocol
        PRIVATE asio::asio
        PRIVATE OpenSSL::SSL
        PRIVATE OpenSSL::Crypto
        PRIVATE spdlog::spdlog
        PRIVATE Threads::Threads
)
