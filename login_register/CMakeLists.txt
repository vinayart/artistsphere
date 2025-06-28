cmake_minimum_required(VERSION 3.16)
project(LoginApp)

set(CMAKE_CXX_STANDARD 17)

# 🔧 Add Sql module here
find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)

qt_standard_project_setup()

add_executable(LoginApp
    src/main.cpp
    src/LoginWindow.cpp
    src/LoginWindow.h
    src/LoginSignupWindow.cpp
    src/LoginSignupWindow.h
    src/SignUpWindow.cpp
    src/SignUpWindow.h
    src/DatabaseManager.cpp
    src/DatabaseManager.h
)

# 🔧 Link Qt6::Sql as well
target_link_libraries(LoginApp PRIVATE Qt6::Widgets Qt6::Sql)
