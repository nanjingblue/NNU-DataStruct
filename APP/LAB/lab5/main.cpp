#include <iostream>
#include <vector>
#include "LinkBiTree.h"

int main() {
    char arr[] = "abd**e**cf***";
    int len = sizeof(arr) / sizeof(char);
    vector<char> v1(arr, arr + len);
    BiTree<char> bit(v1);

    cout << "ԭ�������У�";
    bit.preOrder();     // ��������
    cout << endl;

    cout << "�������Һ��Ӻ�";
    bit.swapClild();     // ��������
    bit.preOrder();
    cout << endl;

    cout << "��������Ҷ�ӵ�·��: " << endl;
    bit.pathToLeaf();       // ��������Ҷ�ӵ�·��

    cout << "Ҷ�ӽڵ���Ŀ��" << bit.leafCount() << endl;
    cout<< "����֧�ڵ���Ŀ��" << bit.singleBranchCount() << endl;
    cout<< "˫��֧�ڵ���Ŀ��" << bit.doubleBranchCount() << endl;
    return 0;
}
