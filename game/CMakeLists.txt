project(game)

include_directories(include)

add_library(libgame STATIC
    src/Collisions.cpp
    src/FrameRate.cpp
    src/Game.cpp
    src/GameObjects.cpp
    src/InputComponent.cpp
    src/MoveComponent.cpp
    src/Player.cpp
    src/Projectile.cpp
    src/SDLDisplay.cpp
    src/Texture.cpp
    src/Zombie.cpp)

add_executable(game src/main.cpp)
target_link_libraries(game libgame ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
target_include_directories(libgame PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
install(TARGETS game RUNTIME DESTINATION ${BIN_DIR})
