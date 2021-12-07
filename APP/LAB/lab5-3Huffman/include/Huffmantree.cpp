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
    vector<int> code;       // �� i �����ŵı�������
    int p = i;
    int parent = huffTree[i].parent;
    while (parent != -1) {
        if(huffTree[parent].leftChild == p) {
            code.insert(code.begin(), 0);       // �ڱ��������ײ����� 0
        } else {
            code.insert(code.begin(), 1);       // �ڱ����ײ�����1
        }
        p = parent;
        parent = huffTree[parent].parent;       // �ظ�ָ������
    }
    return code;
}

string HuffmanTree::Decode(vector<char> &source) {
    string target = "";     // �����Ŀ�꣺ԭ��Ϣ���Ŵ�
    int root = huffTree.size() - 1;
    int p = root;
    for(int i : source) {
        if(i == '0') {
            p = huffTree[p].leftChild;      // �� 0 ����������
        } else {
            p = huffTree[p].rightChild;     // �� 1 ���Һ�������
        }
        if(huffTree[p].leftChild == -1 && huffTree[p].rightChild == -1) {
            target += huffTree[p].data;     // ��Ŀ��ĩβ�찡���������
            p = root;
        }
    }
    return target;
}

void HuffmanTree::printCode() {
    for (int i = 0; i < (huffTree.size() + 1) / 2; ++i) {
        cout << "���� " << huffTree[i].data << " �Ĺ���������Ϊ��" ;
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