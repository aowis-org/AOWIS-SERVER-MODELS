cmake_minimum_required(VERSION 3.21)

project(
    AOWIS_SERVER_MODEL
    VERSION 0.1.0
    DESCRIPTION "Shared AOWIS server data models, structs, and enums"
    LANGUAGES CXX
)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(aowis-server-model INTERFACE)
add_library(AOWIS::ServerModel ALIAS aowis-server-model)
add_library(AOWIS::Model ALIAS aowis-server-model)

target_sources(
    aowis-server-model
    PRIVATE
        include/aowis/model/project.h
        include/aowis/model/hydraulic/epanet_status.h
        include/aowis/model/hydraulic/simulation_request.h
        include/aowis/model/hydraulic/simulation_result.h
)

target_link_libraries(
    aowis-server-model
    INTERFACE
        Qt6::Core
)

target_compile_features(
    aowis-server-model
    INTERFACE
        cxx_std_20
)

target_include_directories(
    aowis-server-model
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)

install(
    TARGETS aowis-server-model
    EXPORT AOWISServerModelTargets
)

install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    EXPORT AOWISServerModelTargets
    FILE AOWISServerModelTargets.cmake
    NAMESPACE AOWIS::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/AOWISServerModel
)
