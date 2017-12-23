//
// Created by Tomnof on 12/23/2017.
//

#ifndef LIVE_TREEDECOMPOSITION_H
#define LIVE_TREEDECOMPOSITION_H


#include "ITreeDecomposition.h"

class TreeDecomposition :: ITreeDecomposition{
public:

    // get the TD's root index
    Node root() ;

    // Access the bag content of a specific node in the TD
    // BagElement is a string representing a vertex in the original graph
    const set<DecompositionNode::BagElement> & bagContent(Node Node) const;

    // Access all the children of a node in the TD
    const vector<Node> childrenOfNode(Node);

};


#endif //LIVE_TREEDECOMPOSITION_H
