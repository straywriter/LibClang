cmake_minimum_required(VERSION 3.15)

project(libclang)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")

if(MSVC)
  add_compile_options($<$<CONFIG:>:/MT> 
                      $<$<CONFIG:Debug>:/MT>
                      $<$<CONFIG:Release>:/MT>)
endif()


set(LibClangIncludeDir ${CMAKE_CURRENT_SOURCE_DIR}/Include/ CACHE STRING "" FORCE)

if(NOT (MSVC OR APPLE OR UNIX))
  message(FATAL_ERROR "This build currenly works only with macOS, Microsoft Visual Studio and Linux.")
endif()
if(APPLE OR UNIX)
  find_program(CMAKE_LIBTOOL libtool)
  if(NOT CMAKE_LIBTOOL)
    message(FATAL_ERROR "'libtool' is necessary for building static archives")
  endif()
  include(LinuxMacosBuild)
else()
  include(MSVCBuild)
endif()

add_subdirectory(Example)

# add_executable(001PrintEnum Example/001PrintEnum/001PrintEnum.cpp)
# target_link_libraries(001PrintEnum PUBLIC libclang )
# target_compile_definitions(001PrintEnum PUBLIC -D_CINDEX_LIB_ )