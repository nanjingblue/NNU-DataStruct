#include "TreeCreator.h"
#include <vector>

namespace treeCreator {
    int weight[256] = {0};
    HuffmanNode node;
    HuffmanTree tree;
    vector<HuffmanNode> leafs;
    // 名字空间函数定义
    void initHuffmanTree(char fileName[]) {
        utils::getWeight(fileName, weight);
        // int len = sizeof(weight) / sizeof(int);
        // for (int i = 0; i < len; ++i) {
        //     node.data = i;
        //     node.weight = weight[i];
        //     node.parent = node.leftChild = node.rightChild = -1;
        //     leafs.push_back(node);
        // }
        // HuffmanTree temp(leafs);
        // tree = temp;
        // tree.getCode();
        // tree.showTreeNode();
    }
    void encode() {
        
    }
}