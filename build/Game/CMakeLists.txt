cmake_minimum_required(VERSION 3.10)
project(Game)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_C_STANDARD 90)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -static-libgcc -static-libstdc++")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG")
include_directories(
  "C:/Users/2230090/source/repos/project 1/Engin/includes"
)
set(SOURCE_FILES
  "C:/Users/2230090/source/repos/project 1/Game/Source/main.cpp"
)
add_executable(Game ${SOURCE_FILES})
target_link_libraries(Game
  ./sdl/lib/SDL2
  ./sdl/lib/SDL2main
  ./sdl/lib/SDL2_image
)
