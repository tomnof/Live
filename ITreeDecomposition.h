#include "Graph.h"
using namespace tdenum;

#include "dflat/DecompositionNode.h"

class ITreeDecomposition {
public:
    // get the TD's root index
    virtual Node root() = 0;

    // Access the bag content of a specific node in the TD
    // BagElement is a string representing a vertex in the original graph
    virtual const set<DecompositionNode::BagElement> & bagContent(Node Node) const = 0;

    // Access all the children of a node in the TD
    virtual vector<Node> childrenOfNode(Node) = 0;
};