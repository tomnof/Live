//
// Created by Tomnof on 11/21/2017.
//

#ifndef LIVE_ITREEDECOMPOSITIONUTILS_H
#define LIVE_ITREEDECOMPOSITIONUTILS_H

#include "Tree.h"
#include "Graph.h"
#include <vector>
using std::vector

class ITreeDecompositionUtils{
public:
    // pure virtual function - this functhion will provide a list of TDs, based on a given Graph
    // input: graph, numOfTrees is the number of TD to generate
    // output: list of decomposition trees
    // todo: make sure how to return a list from function (refernce?). how do we represent a graph?
    // restrict by running time + no restriction at all
    virtual vector<Tree> generateTDs(Graph g,int numOfTrees) = 0;

    // pure virtual function - this function will run the problem on the given tree. Solver ?
    // input: tree decomposition,
    // maxTime is the max time we are willing to give the tree to run. when reaching this number, running will stop and -1 will be returnd as a result. in minutes.
    // output: the runtime of the problem on the given TD.
    // todo: extract solvers from DFLAT (use only the solvers, not the TD generation)
    // ther's no Tree implementation - check what DFLAT needs. ****** this is the most important part for now ******
    virtual double calculateTDRuntime(Tree t, double maxTime) = 0;

    // pure virtual function - this function will decide which features to use, and will extract them from the given tree
    // input: tree decomposition
    // output: a vector of the Tree features
    virtual vector extractTDFeatures(Tree t);
};


#endif //LIVE_ITREEDECOMPOSITIONUTILS_H
