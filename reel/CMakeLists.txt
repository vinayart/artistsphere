cmake_minimum_required(VERSION 3.14)
project(reel_feed)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Multimedia MultimediaWidgets)

add_executable(reel_feed
    main.cpp
    ReelFeedWindow.cpp
    ReelFeedWindow.h
    ReelWidget.cpp
    ReelWidget.h
)

target_link_libraries(reel_feed
    Qt6::Core
    Qt6::Widgets
    Qt6::Multimedia
    Qt6::MultimediaWidgets
)
