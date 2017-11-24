cmake_minimum_required(VERSION 3.6)

project(Live)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(GMP_INCLUDE_DIR "C:/Users/Naama/Dropbox/school/benny/gmp-6.1.2")
set(GMP_LIBRARIES "C:/Users/Naama/Dropbox/school/benny/gmp-6.1.2")
include_directories(${GMP_INCLUDE_DIR})

set(SOURCE_FILES main.cpp TreeVector.h ITreeDecompositionUtils.h Tree.h Graph.h Running.h Solver.h ItemTree.h ItemTreeNode.h
        DirectedAcyclicGraph.h)
add_executable(Live ${SOURCE_FILES})
target_link_libraries(Live ${GMP_LIBRARIES})

