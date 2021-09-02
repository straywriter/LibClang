
add_executable(001PrintCursor 001PrintCursor.cpp)
target_link_libraries(001PrintCursor PUBLIC libclang_static )
target_compile_definitions(001PrintCursor PUBLIC -D_CINDEX_LIB_ )

add_custom_command(
  TARGET 001PrintCursor
  POST_BUILD
  COMMAND
    ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/001sample.h
    $<TARGET_FILE_DIR:001PrintCursor>)
