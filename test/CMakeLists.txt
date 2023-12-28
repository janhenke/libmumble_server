find_package(Catch2 3 REQUIRED)

# These tests can use the Catch2-provided main
add_executable(
        mumble_server_tests
        dummy.cpp
)

target_link_libraries(
        mumble_server_tests
        PRIVATE mumble_server
        PRIVATE Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(mumble_server_tests)
