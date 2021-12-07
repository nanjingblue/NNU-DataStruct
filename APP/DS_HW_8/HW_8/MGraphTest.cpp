//
// Created by cherry on 2021/12/3.
//
#include <iostream>
#include "MGraph.h"

using namespace std;

int main() {
    GraphType t = dinetwork;

    int a[] = {0, 1, 2, 3, 4, 5};
    MGraph<int> graph(t, a, 6, 10);
    graph.DFSTraverse();
    cout << endl;
    graph.BFSTraverse();
    cout << endl;
    graph.Prim(0);
    cout << endl;
    vector<EdgeType<int>> tree;
    graph.Kruskal(tree);
    printSubTree(graph, tree);
}