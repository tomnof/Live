#ifndef LIVE_ITreeDecomposition_H
#define LIVE_ITreeDecomposition_H

#include "dflat/DecompositionNode.h"
#include <vector>

typedef int bagId;
class ITreeDecomposition {
public:

//    ITreeDecomposition();
//    ~ITreeDecomposition();

    // get the TD's root index
    virtual bagId root() = 0;

    // Access the bag content of a specific node in the TD
    // BagElement is a string representing a vertex in the original graph
    virtual const set<DecompositionNode::BagElement> bagContent(bagId id) const = 0;

    // Access all the children of a node in the TD
    virtual const vector<bagId> childrenOfNode(bagId id) = 0;
};

#endif // LIVE_ITreeDecomposition_H