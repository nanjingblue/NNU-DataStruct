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
    cout << "请输入字符串：";
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
    cout << "编译完成：" << endl;
    tree.printCode();
    while (1) {
        cout << "请输入一个 01 序列进行译码：" << endl;
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
        cout << "-------按 1 继续，按 0 退出--------" << endl;
        cin >> x;
        if (x == 0)
            break;
    }
    leaves.clear();
    return 0;
}