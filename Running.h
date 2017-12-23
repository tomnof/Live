//
// Created by Tomnof on 11/21/2017.
//

#ifndef LIVE_RUNNING_H
#define LIVE_RUNNING_H

#include <map>
#include "TreeVector.h"
#include "ITreeDecomposition.h"
#include "Graph.h"
#include "TreeDecompositionUtils.h"

using namespace std;

// This function will receive Graphs, and will return it's training data a.k.a features vectors per TD that represent the
// graph. This will return the features vectors for all the TDs created from the different graphs.
// input: graphs,
//	    isTraining: will indicate if this is for training ML model, hence we need to compute the real runningTime of
//                  each TD, or if this is not for training and there's no need for that.
// output: key: tree index
//				value: TreeVector containing the features vector and runningTime (if isTraining=0, runningTime=0)
map<int, TreeVector> createTrainingData(vector<Graph> graphs, int numberOfTDs);

// This function will get a Graph, and will return it's TreeVector
// input: graph,
//		isTraining: will indicate if this is for trining ML model, hence we need to compute the real runningTime of
//                  each TD, or if this is not for traiing and there's no need for that.
// output: vector of TreeVector containing the features vector and runningTime (if isTraining=0, runningTime=0)
vector<TreeVector> createTreeVectorsPerGraph(Graph g, bool isTraining, int numberOfTDs);

// the function will recieve traingingData, and will learn what is the best weighted vector
// input: traingingData
// output: weitghted vector
// todo: move this to be an interface for learning algorithem
vector<double> getWeightVectorML(map<int, TreeVector> traingingData);

#endif //LIVE_RUNNING_H
