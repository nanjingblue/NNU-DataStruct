#include <iostream>
#include <vector>
#include "MGraph.h"

using namespace std;

int main() {
    vector<EdgeType<int>> tree;
    char vertex[] = "abcdef";
    GraphType t = undinetwork;
    MGraph<char> mGraph(t, "../graph.txt");
    cout << "BFS: ";
    mGraph.BFSTraverse();
    cout << endl << "DFS: ";
    mGraph.DFSTraverse();
    cout << endl << "PRIM: " << endl;
    mGraph.Prim(0);
    cout << endl << "KRUSKAL: " << endl;
    mGraph.Kruskal(tree);
    printSubTree(mGraph, tree);
    return 0;
}
