# 1. 指定需要的 CMake 最低版本
cmake_minimum_required(VERSION 3.10)

# 2. 声明项目名称及使用的语言
project(hello_world VERSION 1.0 LANGUAGES CXX)

# 3. 设置 C++ 标准（等同于 g++ 的 -std=c++17）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4. 指定头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include)

# 5. 编译库文件（静态库和动态库的区别可以自行搜索）
add_library(hello SHARED src/hello.cpp)
# add_library(hello STATIC src/hello.cpp)

# 6. 创建主程序
add_executable(main_app main.cpp)

# 7. 将 hello 库链接到主程序（等同于 g++ 的 -l）
target_link_libraries(main_app PRIVATE hello)