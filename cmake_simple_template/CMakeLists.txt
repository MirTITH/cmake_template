cmake_minimum_required(VERSION 3.12)

project(simple_project) # 项目名称

# 编译器参数
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_C_STANDARD 11) #使用c11标准
set(CMAKE_CXX_STANDARD 11) #使用c++11标准

# 对 MSVC 开启 utf-8 支持
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

# #文件目录
# include_directories(include) # 在 include 文件夹搜索头文件

# 搜索所有的 .c .cpp 文件，并将列表赋给 src_list（需要最低3.12版本）
file(GLOB src_list CONFIGURE_DEPENDS "*.c" "*.cpp")
add_executable(cpp_project ${src_list})
