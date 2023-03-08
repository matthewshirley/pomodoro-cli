cmake_minimum_required(VERSION 3.2)

set(POMODORO_PROJECT_NAME        "pomodoro")
set(POMODORO_PROJECT_DESCRIPTION "a simple pomodoro timer for your terminal")
set(POMODORO_AUTHOR_DOMAIN       "https://github.com/matthewshirley/pomodoro-cli")
set(POMODORO_AUTHOR_MAINTAINER   "mattshirley@hey.com")
set(POMODORO_VERSION_MAJOR       "0")
set(POMODORO_VERSION_MINOR       "0")
set(POMODORO_VERSION_PATCH       "1")
set(POMODORO_VERSION             "${POMODORO_VERSION_MAJOR}.${POMODORO_VERSION_MINOR}.${POMODORO_VERSION_PATCH}")
set(POMODORO_NAME_VERSION        "${POMODORO_PROJECT_NAME} v${POMODORO_VERSION} (${POMODORO_VERSION_REVISION})")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

########################################################################################################################
### DECLARE PROJECT
########################################################################################################################

project(${POMODORO_PROJECT_NAME})

set(POMODORO_SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(POMODORO_INC_DIR ${PROJECT_SOURCE_DIR}/include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_DEBUG_POSTFIX d)

add_subdirectory(src)

