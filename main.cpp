#include <iostream>
#include "Graph.h"
#include "Running.h"

using tdenum::Graph;
int main() {
    std::cout << "Hello, World!" << std::endl;

    // Constructs a graph that is a tree with 4 nodes: 0-->1-->2-->3
    Graph g = Graph(4);
    // add edges
    set<Node> nodes = g.getNodes();
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
//    g.print();

    vector<Graph> graphs;
    graphs.push_back(g);

    createTrainingData(graphs,1);
    std::cout << "Finished!" << std::endl;
    return 0;
}