//
// Created by Tomnof on 11/21/2017.
//

#ifndef LIVE_RUNNING_H
#define LIVE_RUNNING_H

#include <map>
#include "TreeVector.h"
#include "Graph.h"
#include "Tree.h"
#include "ITreeDecompositionUtils.h"

using ITreeDecompositionUtils
//#include "ITreeDecompositionUtils.h"

//using ITreeDecompositionUtils

using std::map

// This function will get a Graph, and will return it's tringing data a.k.a features vector per TD that represent the graph.
// input: graph,
//				isTraining: will indicate if this is for trining ML model, hence we need to compute the real runningTime of each TD, or if this is not for traiing and there's no need for that.
// output: key: tree index
//				value: TreeVector containg the features vector and runningTime (if isTraining=0, runningTime=0)
map<int, TreeVector> getTraingingData(Graph g, bool isTraining);
//{
//    int numberOfTDs = 40;
//    // building 40 decomposition trees for the given graph
//    vector<Tree> tds = generateTDs(g,numberOfTDs);
//
//        // extract features for each tree
//    map<int, TreeVector> tdsRepresentation;
//    for(int i=0; i<numberOfTDs; i++){
//        tdsRepresentation[i].features = extractTDFeatures(tds[i]);
//        // if we're on training mode - calculate the real rank of the tree by running  the solver.
//        if (isTraining){
//            tdsRepresentation[i].runningTime = calculateTDRuntime(tds[i], 20);
//        }else{
//            tdsRepresentation[i].runningTime = 0;
//        }
//    }
//}

// the function will recieve traingingData, and will learn what is the best weighted vector
// input: traingingData
// output: weitghted vector
// todo: move this to be an interface for learning algorithem
vector<double> getWeightVectorML(map<int, TreeVector> traingingData){

}

#endif //LIVE_RUNNING_H
