cmake_minimum_required(VERSION 3.17)

project(example_lib
    VERSION 1.0.0
    DESCRIPTION "A simple C++ project to demonstrate creating executables and libraries in CMake"
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# set the postfix "d" for the resulting .so or .dll files when building the
# library in debug mode
set(CMAKE_DEBUG_POSTFIX
    d
)

# add the library target and create an alias
add_library(${PROJECT_NAME})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

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
        src/hello.cpp
        src/internal.cpp
)

# define the C++ standard needed to compile this library and make it visible to
# dependers
target_compile_features(${PROJECT_NAME}
    PUBLIC cxx_std_17
)

# set the include directories
target_include_directories(${PROJECT_NAME}
    PRIVATE src
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# if using limited visibility, set CXX_VISIBILILTY_PRESET to "hidden"
include(GenerateExportHeader)
set_property(
    TARGET ${PROJECT_NAME}
    PROPERTY CXX_VISIBILITY_PRESET "hidden"
)
# Hide inlined functions by default, reducing the size of the library
set_property(
    TARGET ${PROJECT_NAME}
    PROPERTY VISIBILITY_INLINES_HIDDEN TRUE
)
# this command generates a header file in the CMAKE_CURRENT_BINARY_DIR which
# sets the visibility attributes according to the compiler settings
generate_export_header(${PROJECT_NAME}
    EXPORT_FILE_NAME export/${PROJECT_NAME}/export_${PROJECT_NAME}.hpp
)
# Add CMAKE_CURRENT_BINARY_DIR to the include path so the generated header can
# be found
target_include_directories(${PROJECT_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/export>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

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

# install the public headers
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# install the generated export header
install(
    DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/export/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/
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
