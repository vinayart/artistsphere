cmake_minimum_required(VERSION 3.14)
project(artist_viewer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Sql Multimedia MultimediaWidgets)

set(SOURCES
    main.cpp
    ArtistViewerWindow.cpp
)

set(HEADERS
    ArtistViewerWindow.h
)

add_executable(artist ${SOURCES} ${HEADERS})

target_link_libraries(artist
    Qt6::Widgets
    Qt6::Sql
    Qt6::Multimedia
    Qt6::MultimediaWidgets
)
