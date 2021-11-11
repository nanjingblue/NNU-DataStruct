#include <iostream>
#include <vector>
#include "LinkBiTree.h"

int main() {
    char arr[] = "abd**e**cf***";
    int len = sizeof(arr) / sizeof(char);
    vector<char> v1(arr, arr + len);
    BiTree<char> bit(v1);

    cout << "原先序序列：";
    bit.preOrder();     // 先序序列
    cout << endl;

    cout << "交换左右孩子后：";
    bit.swapClild();     // 交换孩子
    bit.preOrder();
    cout << endl;

    cout << "根到所有叶子的路径: " << endl;
    bit.pathToLeaf();       // 根到所有叶子的路径

    cout << "叶子节点数目：" << bit.leafCount() << endl;
    cout<< "单分支节点数目：" << bit.singleBranchCount() << endl;
    cout<< "双分支节点数目：" << bit.doubleBranchCount() << endl;
    return 0;
}
