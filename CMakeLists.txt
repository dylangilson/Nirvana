cmake_minimum_required(VERSION 3.20)
project(Nirvana LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    add_compile_options(
        /W4
        /WX
    )

    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
else()
    add_compile_options(
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
endif()

include_directories(headers)

include(FetchContent)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG latest
)
FetchContent_MakeAvailable(glfw)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES}) # build executible to open with terminal
# add_executable(${PROJECT_NAME} WIN32 ${SOURCES}) # build executible to open without terminal

set_source_files_properties(
    ${CMAKE_SOURCE_DIR}/src/engine/stb_image.cpp
    PROPERTIES
        COMPILE_FLAGS "/W0"
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/res
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/../res
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/src/shaders
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders
)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw opengl32)
else()
    find_package(OpenGL REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw ${OPENGL_LIBRARIES} dl)
endif()
