cmake_minimum_required(VERSION 3.16)
project(todo CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(json)

add_executable(todo
  src/main.cpp
  src/TodoList.cpp
)
target_include_directories(todo PRIVATE src)
target_link_libraries(todo PRIVATE nlohmann_json::nlohmann_json)

target_compile_options(todo PRIVATE -Wall -Wextra -Wpedantic)