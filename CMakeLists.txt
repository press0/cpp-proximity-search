project(main)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Search.cpp Parameters.cpp SearchFileReader.cpp ForwardSearchFifoQueue.cpp)

add_executable(main ${SOURCE_FILES})