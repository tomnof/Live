//
// Created by Tomnof on 12/23/2017.
//

#ifndef LIVE_TREEDECOMPOSITION_H
#define LIVE_TREEDECOMPOSITION_H


#include "ITreeDecomposition.h"

class TreeDecomposition : public ITreeDecomposition{
public:

    // get the TD's root index
    bagId root() override ;

    // Access the bag content of a specific node in the TD
    // BagElement is a string representing a vertex in the original graph
    const set<DecompositionNode::BagElement> bagContent(bagId id) const override ;

    // Access all the children of a node in the TD
    const vector<bagId> childrenOfNode(bagId id) override ;
};


#endif //LIVE_TREEDECOMPOSITION_H
