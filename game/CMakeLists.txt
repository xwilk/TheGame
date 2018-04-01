project(game)

include_directories(include)

add_executable(game src/main.cpp src/Game.cpp src/Texture.cpp)
target_link_libraries(game ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
install(TARGETS game RUNTIME DESTINATION ${BIN_DIR})
