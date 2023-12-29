find_package(Boost ${BOOST_REQUIRED_VERSION} REQUIRED COMPONENTS program_options)

add_executable(
        mumble_server_app
        main.cpp
)

set_target_properties(
        mumble_server_app
        PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)

target_include_directories(
        mumble_server_app
        PRIVATE mumble_server
)

find_package(libpqxx CONFIG REQUIRED)

target_link_libraries(
        mumble_server_app
        PRIVATE mumble_server
        PRIVATE Boost::boost
        PRIVATE Boost::program_options
        PRIVATE libpqxx::pqxx
)
