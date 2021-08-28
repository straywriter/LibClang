
add_executable(001PrintEnum 001PrintEnum.cpp)
target_link_libraries(001PrintEnum PUBLIC libclang_static )
target_compile_definitions(001PrintEnum PUBLIC -D_CINDEX_LIB_ )

add_custom_command(
  TARGET 001PrintEnum
  POST_BUILD
  COMMAND
    ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/sample.h
    $<TARGET_FILE_DIR:001PrintEnum>)
