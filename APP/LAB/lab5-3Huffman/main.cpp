//
// Created by Tang to Child
//
#include <iostream>
#include <vector>
#include "HuffmanTree.h"

using namespace std;

int main() {
    string str;
    double code[256] = {0};
    vector<HuffmanNode> leaves;
    cout << "�������ַ�����";
    cin >> str;
    for (int i = 0; i < str.length(); ++i) {
        code[(char)str[i]]++;
    }
    for (int i = 0; i < 256; ++i) {
        code[i] /= 256.0;
        if (code[i] > 0) {
            HuffmanNode node{(char)i, (double )code[i], -1, -1, -1};
            leaves.push_back(node);
        }
    }
    HuffmanTree tree(leaves);
    tree.showTree();
    tree.GetCode();
    cout << "������ɣ�" << endl;
    tree.printCode();
    while (1) {
        cout << "������01 �������룺" << endl;
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
        cout << "1 ���� 0 �˳�" << endl;
        cin >> x;
        if (x == 0)
            break;
    }
    leaves.clear();
    return 0;
}