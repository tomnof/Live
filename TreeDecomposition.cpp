//
// Created by Naama on 25/12/2017.
//

// this is a dummy treeDecomposition implementation that suits to the graph 0-->1-->2-->3
#include "TreeDecomposition.h"
#include <string>

// get the TD's root index
bagId TreeDecomposition::root() {
    return 0;
}

// a bag will be an original vertex in the graph
const set<DecompositionNode::BagElement> TreeDecomposition::bagContent(bagId id) const {
    set<DecompositionNode::BagElement> content;
    content.insert(std::to_string(id));
    return content;
}

// Access all the children of a node in the TD
const vector<bagId> TreeDecomposition::childrenOfNode(bagId id){
    vector<bagId> children;
    if (id != 3) {
        children.push_back(id+1);
    }
    return children;
}
