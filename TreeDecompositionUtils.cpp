//
// Created by Tomnof on 12/22/2017.
//

#include "TreeDecompositionUtils.h"
#include "dflat/solver/default_join/Solver.h"
#include <stack>
#include <ctime>
using namespace std;

double calculateTDRuntime(ITreeDecomposition* treeDecomposition, double maxTime){

    // transform the ITreeDecomposition to DecompositionPtr to send to DFLAT solver
    // TODO: make sure that t passes with all its values. Does c++ creates a new object t when passing it to the next function?
    DecompositionPtr decompositionPtr = transformTD(treeDecomposition);
    clock_t startTime = clock();

    // measure how much time does the solver computation takes
    // TODO: add time limit on the solver's run
//    decompositionPtr->getSolver().compute();

    solver::default_join::Solver defaultJoinSolver = new solver::default_join::Solver(true);
    defaultJoinSolver.compute(decompositionPtr);

    clock_t  endTime = clock();
    double durationSecs = (endTime - startTime)/ (double) CLOCKS_PER_SEC;
}

//DecompositionPtr transformTd(ITreeDecomposition& decomposition, const Application& app)
DecompositionPtr transformTD(ITreeDecomposition* decomposition)
{
    // we assume that the ITreeDecomposition we received is valid

    DecompositionNode::Bag rootBag(decomposition->bagContent(decomposition->root()));
//    DecompositionPtr result{new Decomposition{rootBag, app.getSolverFactory()}};
    DecompositionPtr result{new Decomposition{rootBag}};

    // If root is a join node, maybe add post join node
    DecompositionPtr rootOrPostJoinNode = result;

    // Simulate recursion on htd's generated TD
    stack<pair<Node, DecompositionPtr>> stack;
    stack.push({decomposition->root(), rootOrPostJoinNode});

    while(stack.empty() == false) {
        Node TDparent = stack.top().first;
        DecompositionPtr parent = stack.top().second;
        stack.pop();
        for (auto TDChild : decomposition->childrenOfNode(TDparent)) {
            DecompositionNode::Bag childBag(decomposition->bagContent(TDChild));
            // Add post join node if necessary
            Decomposition* parentOrPostJoinNode = parent.get();

//            DecompositionPtr child{new Decomposition{childBag, app.getSolverFactory()}};
            DecompositionPtr child{new Decomposition{childBag}};
            parentOrPostJoinNode->addChild(child);
            stack.push({TDChild, child});
        }
    }

    return result;
}

//TODO: Dvir's implementation
vector<ITreeDecomposition> generateTDsPerGraph(Graph g, int numOfTrees){
    return vector<ITreeDecomposition>();
}

//TODO: implement
vector<double> extractTDFeatures(ITreeDecomposition* t){
    return vector<double>();
}