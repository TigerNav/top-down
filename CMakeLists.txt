cmake_minimum_required(VERSION 3.0.0)
project(game VERSION 0.1.0)

include(CTest)
enable_testing()


file(GLOB TARGET_SRC "./src/*.cpp")
file(GLOB GAME_SRC "./src/Game/*.cpp")
file(GLOB ENTITY_SRC "./src/Game/Entities/*.cpp")
file(GLOB MAP_SRC "./src/Map/*.cpp")
file(GLOB MENU_SRC "./src/Menu/*.cpp")
file(GLOB PAUSE_SRC "./src/Pause/*.cpp")
file(GLOB UTILS_SRC "./src/Utils/*.cpp")

add_executable(main ${TARGET_SRC} ${GAME_SRC} ${ENTITY_SRC} ${MAP_SRC} ${MENU_SRC} ${PAUSE_SRC} ${UTILS_SRC})
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/include/)  

target_link_libraries(main ${CMAKE_SOURCE_DIR}/external-libraries/libs/sfml/libsfml-graphics.so 
                            ${CMAKE_SOURCE_DIR}/external-libraries/libs/sfml/libsfml-window.so
                            ${CMAKE_SOURCE_DIR}/external-libraries/libs/sfml/libsfml-system.so
                            ${CMAKE_SOURCE_DIR}/external-libraries/libs/sfml/libsfml-audio.so
                            ${CMAKE_SOURCE_DIR}/external-libraries/libs/tmx/libtmx-loader.so
                            ${CMAKE_SOURCE_DIR}/external-libraries/libs/tmx/libpugi.so)

 
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/external-libraries/includes/)



