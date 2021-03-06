cmake_minimum_required(VERSION 3.12)

project(cmake_project VERSION 0.1.0) # 项目名称和版本

#版本控制
	configure_file(version.h.in version.h) # 根据 version.h.in 生成 version.h
	include_directories(${PROJECT_BINARY_DIR}) # 包含 version.h 所在目录

# 编译器参数
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
	set(CMAKE_C_STANDARD 11) #使用c11标准
	set(CMAKE_CXX_STANDARD 11) #使用c++11标准

	# 对 MSVC 开启 utf-8 支持
	add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>")
	add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

# 路径设置
	# 可执行文件输出路径
	# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

	# 包含目录
	include_directories(include) # 在 include 文件夹搜索头文件

	# .c .cpp 目录
	# 搜索所有的 .c .cpp 文件，并将列表赋给 src_list（需要最低3.12版本）
	file(GLOB src_list CONFIGURE_DEPENDS "src/*.c" "src/*.cpp")
	add_executable(${PROJECT_NAME} ${src_list})



# 单元测试
	# include(CTest)
	# enable_testing()

# 项目打包
	# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
	# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
	# include(CPack)
