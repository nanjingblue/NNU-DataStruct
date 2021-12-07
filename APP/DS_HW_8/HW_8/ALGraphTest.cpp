#include <iostream>
#include "ALGraph.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    GraphType t = undinetwork;
    int v[] = {0, 1, 2, 3, 4, 5};
    ALGraph<int> g(t, v, 6, 10);
    cout << "DFS: ";
    g.DFSTraverse();
    cout << endl << "BFS: ";
    g.BFSTraverse();
    cout << endl;
    g.isExistPathK(0,4,3);
    return 0;
}
