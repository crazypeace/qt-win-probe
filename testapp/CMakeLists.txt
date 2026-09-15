cmake_minimum_required(VERSION 3.21)
project(qtlinktest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network Svg Concurrent)

# Static Qt built with -debug-and-release -force-debug-info exports only
# Debug;RelWithDebInfo. windeployqt is imported without a location for the
# active config — point it at the installed exe (same fix tdesktop needs).
if(TARGET Qt6::windeployqt)
  get_filename_component(_qt_root "${Qt6_DIR}/../../.." ABSOLUTE)
  set_property(TARGET Qt6::windeployqt PROPERTY IMPORTED_LOCATION "${_qt_root}/bin/windeployqt.exe")
  set_property(TARGET Qt6::windeployqt PROPERTY IMPORTED_LOCATION_RELWITHDEBINFO "${_qt_root}/bin/windeployqt.exe")
  set_property(TARGET Qt6::windeployqt PROPERTY IMPORTED_LOCATION_DEBUG "${_qt_root}/bin/windeployqt.exe")
endif()
set(CMAKE_MAP_IMPORTED_CONFIG_RELEASE "RelWithDebInfo;")

add_executable(qtlinktest main.cpp)
target_link_libraries(qtlinktest PRIVATE
    Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network Qt6::Svg Qt6::Concurrent)
