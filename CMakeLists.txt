cmake_minimum_required(VERSION 3.21.3)

set(VCPKG_ROOT "C:/Users/visitor.ATALENT.006/vcpkg")
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

project(GAK_Server)



# Libraries include
find_package(Crow CONFIG REQUIRED)

# Sources include
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_scripts/cmake_scripts.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/sources/sources.cmake)
get_sources(SOURCES_LIST ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(${PROJECT_NAME} ${SOURCES_LIST})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/sources)

# Libraries include
target_link_libraries(${PROJECT_NAME} PRIVATE Crow::Crow)

# Output file name settings
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/$<0:>)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX .exe)

#--------------------------------------------------------------------------------