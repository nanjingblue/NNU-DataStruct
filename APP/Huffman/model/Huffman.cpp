#include <limits.h>
#include "Huffman.h"

HuffmanTree::HuffmanTree() {
    n = 0;
}

void HuffmanTree::selectSmall(int &least, int &less, int p) {
    huffTree[p].weight = INT_MAX;
    for(int i = 0; i < p; ++i) {
        if(huffTree[i].parent == -1) {
            if(huffTree[i].weight < huffTree[least].weight) {
                less = least;
                least = i;
            } else if(huffTree[i].weight < huffTree[less].weight) {
                less = i;
            }
        }
    }
}

HuffmanTree::HuffmanTree(vector<HuffmanNode> & leafs) {
    int least, less;
    huffTree = leafs;
    n = leafs.size();
    huffTree.resize(2 * n - 1);
    for (int i = n; i < 2 * n -1; ++i) {
        least = less = i;
        selectSmall(least, less, i);
        huffTree[least].parent = i;
        huffTree[less].parent = i;
        huffTree[i].weight = huffTree[least].weight + huffTree[less].weight;
        huffTree[i].leftChild = least;
        huffTree[i].rightChild = less;
        huffTree[i].parent = -1;
    }
}

void HuffmanTree::getCode() {
    for (int i = 0; i < (huffTree.size() + 1) / 2; ++i) {
        int parent = huffTree[i].parent;
        int temp = i;
        while (parent != -1)
        {
            if (huffTree[parent].leftChild == temp)
                huffTree[i].code.insert(huffTree[i].code.begin(), '0');
            else
                huffTree[i].code.insert(huffTree[i].code.begin(), '1');
            temp = parent;
            parent = huffTree[parent].parent;
        }
    }
}

void HuffmanTree::showTreeNode() {
    cout << "huffTree size: " << huffTree.size() << endl;
    // cout << "字节种类   权重    标记    双亲下标    左孩子下标  右孩子下标" << endl;
    for (int i = 0; i < (huffTree.size() + 1) / 2; ++i) {
        cout <<"序号：" << i+1 << "\t字节：" << i << "\t权重" << huffTree[i].weight << "\t编码：";
        for (int j = 0; j < huffTree[i].code.size(); ++j) {
            cout << huffTree[i].code[j];
        }
        cout << "\t父结点：" << huffTree[i].parent << "\t左孩子：" << huffTree[i].leftChild << "\t右孩子：" << huffTree[i].rightChild << endl;
    }
}

void HuffmanTree::showThatNode(int index) {
    cout << "字符：" << huffTree[index].data << "的编码为：";
    cout << "huffTree[index].code.size()" << huffTree[index].code.size() << endl;
    for (int i = 0; i < huffTree[index].code.size(); ++i) {
        cout << huffTree[index].code[i] << " ";
    }
    cout << endl;
}