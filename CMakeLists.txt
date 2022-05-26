cmake_minimum_required(VERSION 3.0.0)
project(game VERSION 0.1.0)

include(CTest)
enable_testing()




file(GLOB TARGET_SRC "./src/*.cpp")


add_executable(main ${TARGET_SRC} ${TARGET_SRC2})
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/include/)  

target_link_libraries(main ${CMAKE_SOURCE_DIR}/external-libraries/libs/sfml/libsfml-graphics.so 
                            ${CMAKE_SOURCE_DIR}/external-libraries/libs/sfml/libsfml-window.so
                            ${CMAKE_SOURCE_DIR}/external-libraries/libs/sfml/libsfml-system.so)

 
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/external-libraries/includes/)



