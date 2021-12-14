#include <iostream>
#include "MGraph.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    GraphType t = dinetwork;
    MGraph<int>graph(t, "../graph2.txt");
    cout << "DFS£º";
    graph.DFSTraverse();
    cout << endl << "BFS: ";
    graph.BFSTraverse();
    cout << endl << "DIJKSTRA: ";
    graph.Dijkstra(0);
    cout << endl << "FLOYD:" << endl;
    graph.Floyd();
    return 0;
}
