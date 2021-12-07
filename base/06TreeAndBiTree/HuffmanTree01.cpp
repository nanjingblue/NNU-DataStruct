//
// Created by cherry on 2021/9/2.
//
#include <iostream>
#include "HuffmanTree.h"
using namespace std;

int main() {
    int n;
    HuffmanNode node;
    vector<HuffmanNode> leafs;
    while (1) {
        cout << "������һ���������������Լ�Ȩ�أ����� @ ���������� ���� 0 �˳���" << endl;
        cin >> node.data;
        if (node.data == '0')
            exit(0);
        while (node.data != '@') {
            cin >> node.weight;
            node.parent = node.leftChild = node.rightChild = -1;
            leafs.push_back(node);
            cin >> node.data;
        }
        cout << "�������" << endl;
        HuffmanTree tree(leafs);
        tree.showTree();
        tree.GetCode();
        cout << "������ɣ�" << endl;
        tree.printCode();
        while (1) {
            cout << "������һ�� 01 ���н������룺" << endl;
            string str;
            int i = 0;
            cin >> str;
            vector<char> code;
            while (i < str.length()) {
                code.push_back(str[i]);
                ++i;
            }
            cout << tree.Decode(code) << endl;
            code.clear();
            int x;
            cout << "-------�� 1 �������� 0 �˳�--------" << endl;
            cin >> x;
            if (x == 0)
                break;
        }
        leafs.clear();
    }
    return 0;
}