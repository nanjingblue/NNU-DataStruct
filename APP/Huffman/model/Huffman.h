#ifndef DATASTRUCTURES_HUFFMANAPP
#define DATASTRUCTURES_HUFFMANAPP

#include <iostream>
#include <vector>
using namespace std;

struct HuffmanNode {
    char data;
    int weight;
    int parent, leftChild, rightChild;
    vector<char> code;
};

class HuffmanTree {
private:
    vector<HuffmanNode> huffTree; 
    int n;
    void selectSmall(int &least, int &less, int p);
public:
    HuffmanTree();
    explicit HuffmanTree(vector<HuffmanNode> & leafs);
    // void & operator=(HuffmanTree tree);
    void getCode();
    void showTreeNode();
    void showThatNode(int index);
};


#endif //DATASTRUCTURES_HUFFMANAPP
