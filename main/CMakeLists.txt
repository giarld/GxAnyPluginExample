cmake_minimum_required(VERSION 3.20)

project(ExampleApp)

# Dynamic load
add_executable(dynamic-load-app
        src/dynamic_load.cpp
)
target_link_libraries(dynamic-load-app gany-core)
# Do not link
add_dependencies(dynamic-load-app test-plug)

# Shared link
add_executable(shared-link-app
        src/link_load.cpp
)
target_link_libraries(shared-link-app gany-core test-plug)

# Static link
add_executable(static-link-app
        src/link_load.cpp
)
target_link_libraries(static-link-app gany-core test-plug-static)
