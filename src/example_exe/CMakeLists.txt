cmake_minimum_required(VERSION 3.17)

# You can just change the project name here for your project
project(example_exe
    VERSION 1.0.0
    DESCRIPTION "A simple C++ project to demonstrate creating executables and libraries in CMake"
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# create the executable target
add_executable(${PROJECT_NAME})

# add the source files to the target
target_sources(${PROJECT_NAME} PRIVATE
    src/main.cpp
)

# set the include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    src
)

# define the C++ standard needed to compile this target
target_compile_features(${PROJECT_NAME}
    PUBLIC cxx_std_17
)

set_target_properties(${PROJECT_NAME}  PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

# include the GNUInstallDirs module to get the canonical install paths defined
include(GNUInstallDirs)

# Install the library and export the CMake targets
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # for shared libraries
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} # for static libraries
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # for executables
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} # for headers
)

# Install header files if needed
# install(FILES 
#     my_header.h 
#     DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
# )

# Install other data files if needed
# install(FILES 
#     config.txt 
#     DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME}
# )
