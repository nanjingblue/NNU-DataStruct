#include <iostream>
#include <vector>
#include "cstree.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    Coupe<char> a[] = {
            {'A', 'B'},
            {'B', 'E'},
            {'A', 'C'},
            {'B', 'F'},
            {'A', 'D'},
            {'C', 'H'},
            {'C', 'G'}
    };
    vector<Coupe<char>> v(a, a + 7);
    CSTree<char> tree(v);
    tree.preOrder();
    cout << endl;
    tree.pathToLeaves();
    cout << "计算顶点度数：" << endl;
    tree.Degree();
    tree.preOrder();
    return 0;
}
