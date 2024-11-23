cmake_minimum_required(VERSION 3.30)
project(asteroids)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/)

set(RAYLIB_PATH ${PROJECT_SOURCE_DIR}/ext/raylib-5.5/)
set(SOURCE_FILES)

include_directories(${PROJECT_SOURCE_DIR}/src/ ${RAYLIB_PATH}/include/)
add_executable(${PROJECT_NAME} src/main.cpp)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} ${RAYLIB_PATH}/lib/libraylib-mac.a
            "-framework CoreVideo"
            "-framework IOKit"
            "-framework Cocoa")
elseif (UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} ${RAYLIB_PATH}/lib/libraylib-lin.a)
else ()
    target_link_libraries(${PROJECT_NAME} ${RAYLIB_PATH}/lib/libraylib-win.lib
            gdi32.lib
            winmm.lib
            user32.lib
            shell32.lib)
endif ()

# file(COPY ${PROJECT_SOURCE_DIR}/res/ DESTINATION ${PROJECT_SOURCE_DIR}/bin/res/)