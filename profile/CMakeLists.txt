cmake_minimum_required(VERSION 3.14)

project(ProfileApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable AUTOMOC
set(CMAKE_AUTOMOC ON)

# Qt modules
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql)

# Sources
set(SOURCES
    main.cpp
    ProfileWindow.cpp
)

set(HEADERS
    ProfileWindow.h
)

add_executable(ProfileApp ${SOURCES} ${HEADERS})

target_link_libraries(ProfileApp
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Sql
)
