//
// Created by Tomnof on 12/22/2017.
//

#include "TreeDecompositionUtils.h"
#include <stack>
#include <ctime>
using namespace std;

double calculateTDRuntime(ITreeDecomposition t, double maxTime){

    // transform the ITreeDecomposition to DecompositionPtr to send to DFLAT solver
    DecompositionPtr decompositionPtr = transformTd(t, app);
    clock_t startTime = clock();

    // measure how much time does the solver computation takes
    // TODO: add time limit on the solver's run
    decompositionPtr->getSolver().compute();
    clock_t  endTime = clock();
    double durationSecs = (endTime - startTime)/ (double) CLOCKS_PER_SEC;
}

DecompositionPtr transformTd(ITreeDecomposition& decomposition, const Application& app)
{
    // we assume that the ITreeDecomposition we received is valid

    DecompositionNode::Bag rootBag(decomposition.bagContent(decomposition.root()));
    DecompositionPtr result{new Decomposition{rootBag, app.getSolverFactory()}};

    // If root is a join node, maybe add post join node
    DecompositionPtr rootOrPostJoinNode = result;

    // Simulate recursion on htd's generated TD
    stack<pair<Node, DecompositionPtr>> stack;
    stack.push({decomposition.root(), rootOrPostJoinNode});

    while(stack.empty() == false) {
        Node TDparent = stack.top().first;
        DecompositionPtr parent = stack.top().second;
        stack.pop();
        for (auto TDChild : decomposition.childrenOfNode(TDparent)) {
            DecompositionNode::Bag childBag(decomposition.bagContent(TDChild));
            // Add post join node if necessary
            Decomposition* parentOrPostJoinNode = parent.get();

            DecompositionPtr child{new Decomposition{childBag, app.getSolverFactory()}};
            parentOrPostJoinNode->addChild(child);
            stack.push({TDChild, child});
        }
    }

    return result;
}