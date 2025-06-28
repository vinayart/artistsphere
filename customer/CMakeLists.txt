cmake_minimum_required(VERSION 3.14)

project(CustomerApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt packages
find_package(Qt5 REQUIRED COMPONENTS Widgets Sql)

# Add your source files
set(SOURCES
    main.cpp
    CustomerWindow.cpp
    Trie.cpp
)

# Add your header files (optional for IDEs)
set(HEADERS
    CustomerWindow.h
    Trie.h
)

# Add the executable
add_executable(customer ${SOURCES} ${HEADERS})

# Link Qt libraries
target_link_libraries(customer
    Qt5::Widgets
    Qt5::Sql
)
