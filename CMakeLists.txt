cmake_minimum_required(VERSION 4.2)
project(dos-app)

set(CMAKE_GENERATOR Ninja)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
add_compile_options(-Wall -std=gnu99 -save-temps)

file(GLOB sources CONFIGURE_DEPENDS "src/*.c" "src/*.cpp" "src/*.h" "src/**/*.c" "src/**/*.cpp" "src/**/*.h" )

add_executable(main ${sources})

target_link_directories(main PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/libs
)

target_link_libraries(main
    alleg
)

add_custom_target(assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/assets
    ${CMAKE_BINARY_DIR}/assets
)
add_dependencies(main assets)