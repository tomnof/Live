cmake_minimum_required(VERSION 3.6)

project(Live)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(GMP_INCLUDE_DIR "gmp")
set(GMP_LIBRARIES "gmp")
#set(GMP_INCLUDE_DIR "C:/Users/tomnof/Desktop/git/gmp-6.1.2")
#set(GMP_LIBRARIES "C:/Users/tomnof/Desktop/git/gmp-6.1.2")
include_directories(${GMP_INCLUDE_DIR})

set(SOURCE_FILES main.cpp TreeVector.h TreeDecompositionUtils.h TreeDecompositionUtils.cpp Graph.h Running.h Running.cpp ITreeDecomposition.h
        dflat/DecompositionNode.h dflat/DecompositionNode.cpp dflat/Decomposition.h dflat/Decomposition.cpp
        dflat/DirectedAcyclicGraph.h dflat/Solver.h dflat/Solver.cpp dflat/ItemTree.h dflat/ItemTree.cpp
        dflat/ItemTreeNode.h dflat/ItemTreeNode.cpp dflat/ExtensionIterator.h dflat/ExtensionIterator.cpp TreeDecompositionUtils.cpp)
add_executable(Live ${SOURCE_FILES})


target_link_libraries(Live ${GMP_LIBRARIES})

