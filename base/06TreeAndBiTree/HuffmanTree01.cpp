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
        cout << "请输入一个哈夫曼树符号以及权重，输入 @ 结束，或者 输入 0 退出：" << endl;
        cin >> node.data;
        if (node.data == '0')
            exit(0);
        while (node.data != '@') {
            cin >> node.weight;
            node.parent = node.leftChild = node.rightChild = -1;
            leafs.push_back(node);
            cin >> node.data;
        }
        cout << "输入完毕" << endl;
        HuffmanTree tree(leafs);
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
        leafs.clear();
    }
    return 0;
}