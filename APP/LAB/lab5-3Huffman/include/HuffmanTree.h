//
// Created by cherry on 2021/9/2.
//

#ifndef DATASTRUCTURES_HUFFMANTREE_H
#define DATASTRUCTURES_HUFFMANTREE_H

#include <iostream>
#include <vector>
using namespace std;

struct HuffmanNode {
    char data;      // 待编码的符号
    double weight;      // 符号出现的频率
    int parent, leftChild, rightChild;      // 父结点，左孩子，右孩子结点的位置
    vector<char> code;
};

class HuffmanTree {
private:
    vector<HuffmanNode> huffTree;       // 树中所有节点的存储空间
    int n;      // 叶子节点数
    void SelectSmall(int &least, int &less, int p);
public:
    explicit HuffmanTree(vector<HuffmanNode> &leafs);
    void GetCode();     // 取编码
    vector<int> GetCode(int i);     // 取第 i 个字符编码
    string Decode(vector<char> &source);      // 译码
    void printCode();
    void showTree();
};
#endif //DATASTRUCTURES_HUFFMANTREE_H
