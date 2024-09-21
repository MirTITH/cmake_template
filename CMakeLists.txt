cmake_minimum_required(VERSION 3.17)

project(cmake_template_proj) # 项目名称

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_LIST_DIR}/install) # 安装路径

add_subdirectory(src/example_lib)
add_subdirectory(src/example_header_only_lib)
add_subdirectory(src/example_exe)