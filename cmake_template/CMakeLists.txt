cmake_minimum_required(VERSION 3.12)

project(cmake_project) # 项目名称

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_EXTENSIONS false)
set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS false)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 可执行文件输出路径
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# .c .cpp 目录
	set(SRC_DIRS 
		src
	)

	# 在 SRC_DIRS 中递归搜索源文件
	foreach(_DIR ${SRC_DIRS})
		file(GLOB_RECURSE temp_list ${_DIR}/*.cpp ${_DIR}/*.c)
		list(APPEND SRC_LIST ${temp_list})
	endforeach()

	add_executable(${PROJECT_NAME} ${SRC_LIST})

target_include_directories(${PROJECT_NAME} PRIVATE
	inc
)

target_compile_options(${PROJECT_NAME} PRIVATE 
	-Wall
	-Wextra

	# 对 MSVC 开启 utf-8 支持
	"$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>"
	"$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>"
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
)

target_link_options(${PROJECT_NAME} PRIVATE 
	# -static
)
