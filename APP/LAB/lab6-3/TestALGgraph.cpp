//
// Created by cherry on 2021/12/12.
//
#include <iostream>
#include "ALGraph.h"

using namespace std;

int main() {
    GraphType t = dinetwork;
    ALGraph<int>graph(t, "../graph.txt");
    cout << "DFS：";
    graph.DFSTraverse();
    cout << endl << "拓扑排序：";
    graph.TopoSort();
    return 0;
}