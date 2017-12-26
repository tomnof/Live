//
// Created by Tomnof on 11/21/2017.
//

#ifndef LIVE_ITREEDECOMPOSITIONUTILS_H
#define LIVE_ITREEDECOMPOSITIONUTILS_H

#include "TreeDecomposition.h"
#include "Graph.h"
#include "dflat/Decomposition.h"
#include <vector>
using namespace std;
using namespace tdenum;


// virtual function - this functhion will provide a list of TDs, based on a given Graph
// input: graph, numOfTrees is the number of TD to generate
// output: list of decomposition trees
// todo: make sure how to return a list from function (refernce?).
// restrict by running time + no restriction at all
const vector<TreeDecomposition> generateTDsPerGraph(Graph g, int numOfTrees);

// virtual function - this function will run the problem on the given tree. Solver ?
// input: tree decomposition,
// maxTime is the max time we are willing to give the tree to run. when reaching this number, running will stop and -1 will be returnd as a result. in minutes.
// output: the runtime of the problem on the given TD.
// todo: extract solvers from DFLAT (use only the solvers, not the TD generation)
// ther's no Tree implementation - check what DFLAT needs. ****** this is the most important part for now ******
double calculateTDRuntime(TreeDecomposition* t, double maxTime);

// virtual function - this function will decide which features to use, and will extract them from the given tree
// input: tree decomposition
// output: a vector of the Tree features
vector<double> extractTDFeatures(TreeDecomposition* t);

//DecompositionPtr transformTD(ITreeDecomposition& decomposition, const Application& app);
DecompositionPtr transformTD(TreeDecomposition* decomposition);



#endif //LIVE_ITREEDECOMPOSITIONUTILS_H
