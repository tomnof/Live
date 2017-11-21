#make_minimum_required(VERSION 3.8)
project(Live)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp TreeVector.h ITreeDecompositionUtils.h Tree.h Graph.h Running.h Solver.h ItemTree.h ItemTreeNode.h
        DirectedAcyclicGraph.h)
add_executable(Live ${SOURCE_FILES})