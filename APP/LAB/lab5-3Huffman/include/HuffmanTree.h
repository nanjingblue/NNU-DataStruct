//
// Created by cherry on 2021/9/2.
//

#ifndef DATASTRUCTURES_HUFFMANTREE_H
#define DATASTRUCTURES_HUFFMANTREE_H

#include <iostream>
#include <vector>
using namespace std;

struct HuffmanNode {
    char data;      // ������ķ���
    double weight;      // ���ų��ֵ�Ƶ��
    int parent, leftChild, rightChild;      // ����㣬���ӣ��Һ��ӽ���λ��
    vector<char> code;
};

class HuffmanTree {
private:
    vector<HuffmanNode> huffTree;       // �������нڵ�Ĵ洢�ռ�
    int n;      // Ҷ�ӽڵ���
    void SelectSmall(int &least, int &less, int p);
public:
    explicit HuffmanTree(vector<HuffmanNode> &leafs);
    void GetCode();     // ȡ����
    vector<int> GetCode(int i);     // ȡ�� i ���ַ�����
    string Decode(vector<char> &source);      // ����
    void printCode();
    void showTree();
};
#endif //DATASTRUCTURES_HUFFMANTREE_H
