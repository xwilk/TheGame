project(game)

include_directories(include)

aux_source_directory(src SRC_LIST)
add_executable(game ${SRC_LIST})
target_link_libraries(game ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
install(TARGETS game RUNTIME DESTINATION ${BIN_DIR})
