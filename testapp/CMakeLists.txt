cmake_minimum_required(VERSION 3.21)
project(qtlinktest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network Svg Concurrent)

add_executable(qtlinktest main.cpp)
target_link_libraries(qtlinktest PRIVATE
    Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network Qt6::Svg Qt6::Concurrent)
