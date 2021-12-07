//
// Created by cherry on 2021/11/29.
//
#include "Huffmantree.h"

void HuffmanTree::SelectSmall(int &least, int &less, int p) {
    huffTree[p].weight = 100;
    for (int i = 0; i < p; i++) {
        if (huffTree[i].parent == -1) {
            if (huffTree[i].weight < huffTree[least].weight) {
                less = least;
                least = i;
            } else if (huffTree[i].weight < huffTree[less].weight)
                less = i;
        }
    }
}

HuffmanTree::HuffmanTree(vector <HuffmanNode> &leafs) {
    int least, less;
    huffTree = leafs;
    n = leafs.size();
    huffTree.resize(2 * n - 1);
    for (int i = n; i < 2 * n - 1; i++)
    {
        least = less = i;
        SelectSmall(least, less, i);
        huffTree[least].parent = i;
        huffTree[less].parent = i;
        huffTree[i].weight = huffTree[least].weight + huffTree[less].weight;
        huffTree[i].leftChild = least;
        huffTree[i].rightChild = less;
        huffTree[i].parent = -1;
    }
}

void HuffmanTree::GetCode() {
    for (int i = 0; i < (huffTree.size() + 1) / 2; ++i) {
        int parent = huffTree[i].parent;
        int temp = i;
        while (parent != -1) {
            if(huffTree[parent].leftChild == temp)
                huffTree[i].code.insert(huffTree[i].code.begin(), '0');
            else
                huffTree[i].code.insert(huffTree[i].code.begin(), '1');
            temp = parent;
            parent = huffTree[parent].parent;
        }
    }
}

vector<int> HuffmanTree::GetCode(int i) {
    vector<int> code;       // 第 i 个符号的编码向量
    int p = i;
    int parent = huffTree[i].parent;
    while (parent != -1) {
        if(huffTree[parent].leftChild == p) {
            code.insert(code.begin(), 0);       // 在编码向量首部插入 0
        } else {
            code.insert(code.begin(), 1);       // 在编码首部插入1
        }
        p = parent;
        parent = huffTree[parent].parent;       // 沿父指针上溯
    }
    return code;
}

string HuffmanTree::Decode(vector<char> &source) {
    string target = "";     // 译码的目标：原信息符号串
    int root = huffTree.size() - 1;
    int p = root;
    for(int i : source) {
        if(i == '0') {
            p = huffTree[p].leftChild;      // 逢 0 向左孩子下行
        } else {
            p = huffTree[p].rightChild;     // 逢 1 向右孩子下行
        }
        if(huffTree[p].leftChild == -1 && huffTree[p].rightChild == -1) {
            target += huffTree[p].data;     // 在目标末尾天啊及译码符号
            p = root;
        }
    }
    return target;
}

void HuffmanTree::printCode() {
    for (int i = 0; i < (huffTree.size() + 1) / 2; ++i) {
        cout << "符号 " << huffTree[i].data << " 的哈夫曼编码为：" ;
        for (char j : huffTree[i].code)
            cout << j;
        cout << endl;
    }
}

void HuffmanTree::showTree() {
    for (int i = 0; i < (huffTree.size() + 1) / 2; ++i) {
        cout << huffTree[i].data << " " << huffTree[i].weight << " " << huffTree[i].parent << endl;
    }
}