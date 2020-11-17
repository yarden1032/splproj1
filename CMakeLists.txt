
project(splproj1)

set(CMAKE_CXX_STANDARD 11)

add_executable(splproj1 src/main.cpp src/Graph.cpp src/Session.cpp src/Agent.cpp src/Tree.cpp Tests/Tests.cpp Tests/Tests.h)