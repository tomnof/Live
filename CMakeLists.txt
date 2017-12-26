cmake_minimum_required(VERSION 3.6)

project(Live)

#set(GMP_INCLUDE_DIR "gmp")
#set(GMP_LIBRARIES "gmp")
#set(GMP_INCLUDE_DIR "C:/Users/tomnof/Desktop/git/gmp-6.1.2")
#set(GMP_LIBRARIES "C:/Users/tomnof/Desktop/git/gmp-6.1.2/.libs")

#include_directories(${GMP_INCLUDE_DIR})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp TreeVector.h
        Graph.h Graph.cpp DataStructures.h DataStructures.cpp
        ITreeDecomposition.h TreeDecomposition.h TreeDecomposition.cpp
        Running.h Running.cpp
        TreeDecompositionUtils.h TreeDecompositionUtils.cpp
        dflat/DecompositionNode.h dflat/DecompositionNode.cpp
        dflat/Decomposition.h dflat/Decomposition.cpp
        dflat/DirectedAcyclicGraph.h
        dflat/ItemTree.h dflat/ItemTree.cpp
        dflat/ItemTreeNode.h dflat/ItemTreeNode.cpp
        dflat/ExtensionIterator.h dflat/ExtensionIterator.cpp
        dflat/solver/default_join/Solver.h dflat/solver/default_join/Solver.cpp
        )
add_executable(Live ${SOURCE_FILES})

target_link_libraries(Live ${GMP_LIBRARIES})

#set(CMAKE_CXX_FLAGS "-lgmp -lgmxx")




