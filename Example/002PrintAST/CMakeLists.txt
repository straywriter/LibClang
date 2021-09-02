
add_executable(002PrintAST 002PrintAST.cpp)
target_link_libraries(002PrintAST PUBLIC libclang_static )
target_compile_definitions(002PrintAST PUBLIC -D_CINDEX_LIB_ )

add_custom_command(
  TARGET 002PrintAST
  POST_BUILD
  COMMAND
    ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/002sample.cpp
    $<TARGET_FILE_DIR:002PrintAST>)
