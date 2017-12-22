//
// Created by Tomnof on 11/21/2017.
//

#include "Running.h"

map<int, TreeVector> createTrainingData(vector<Graph> graphs, int numberOfTDs = 40){
    // for each graph, create the TD's. and its features + solver's running time if needed
    map<int, TreeVector> trainingData;
    int treeIndex=0;
    for(auto g : graphs){
        vector<TreeVector> trees = createTreeVectorsPerGraph(g, numberOfTDs);
        for(auto tree : trees){
            trainingData[treeIndex] = tree;
            treeIndex++;
        }
    }
    return trainingData;
}

vector<TreeVector> createTreeVectorsPerGraph(Graph g, int numberOfTDs = 40, bool isTraining = true)
{
    // building numberOfTDs decomposition trees for the given graph
    vector<ITreeDecomposition> tds = generateTDsPerGraph(g,numberOfTDs);

    // extract features for each tree
    vector<TreeVector> tdsRepresentation;
    for(int i=0; i<numberOfTDs; i++){
        tdsRepresentation[i].features = extractTDFeatures(tds[i]);
        // if we're on training mode - calculate the real rank of the tree by running  the solver.
        if (isTraining){
            tdsRepresentation[i].runningTime = calculateTDRuntime(tds[i], 20);
        }else{
            tdsRepresentation[i].runningTime = 0;
        }
    }

    // TODO: after we have all the Trees features, we have to normalize it to reduce dependencies between Tree-Graph

    return tdsRepresentation;
}

// the function will recieve traingingData, and will learn what is the best weighted vector
// input: traingingData
// output: weitghted vector
vector<double> getWeightVectorML(map<int, TreeVector> traingingData){

}
