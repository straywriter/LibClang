
add_executable(001PrintEnum 001PrintEnum.cpp)
target_link_libraries(001PrintEnum PUBLIC libclang )
target_compile_definitions(001PrintEnum PUBLIC -D_CINDEX_LIB_ )