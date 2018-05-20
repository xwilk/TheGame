project(unittest)

include_directories(include)

add_executable(unittest src/test.cpp)
target_link_libraries(unittest libgame)

add_test(NAME unittest COMMAND unittest)
