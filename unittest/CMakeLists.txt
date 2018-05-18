project(unittest)

include_directories(include)

add_executable(unittest src/test.cpp)

add_test(NAME MyTests COMMAND unittest)