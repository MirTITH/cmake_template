cmake_minimum_required(VERSION 3.17)

project(example_exe
    VERSION 1.0.0
    DESCRIPTION "A simple C++ project to demonstrate creating executables and libraries in CMake"
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# add the library target and create an alias
add_executable(${PROJECT_NAME})

# set properties for the target. VERSION set the library version to the project
# version * SOVERSION set the compatibility  version for the library to the
# major number of the version
set_target_properties(${PROJECT_NAME} 
    PROPERTIES
        VERSION ${PROJECT_VERSION} # Example: 1.2.3
        SOVERSION ${PROJECT_VERSION_MAJOR} # Example: 1
)

# add sources to the library target
target_sources(${PROJECT_NAME}
    PRIVATE
        src/main.cpp
)

# define the C++ standard needed to compile this library and make it visible to
# dependers
target_compile_features(${PROJECT_NAME}
    PUBLIC cxx_std_17
)

# set the include directories
# target_include_directories(${PROJECT_NAME}
#     PRIVATE src
#     PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#     $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
# )

# include the GNUInstallDirs module to get the canonical install paths defined
include(GNUInstallDirs)

# Install the library and export the CMake targets
install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # for shared libraries
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} # for static libraries
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # for executables
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} # for headers
)

# configure the CMake package file so the libray can be included with find_package() later
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${PROJECT_NAME}ConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion)

configure_package_config_file(
    "${CMAKE_CURRENT_LIST_DIR}/cmake/TemplateConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/${PROJECT_NAME}
)

# install the CMake targets
install(
    EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/${PROJECT_NAME}
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/${PROJECT_NAME}
)