//
// Created by cherry on 2021/11/7.
//
#include <iostream>
#include <vector>
#include "link_bi_tree.h"

using namespace std;

int main() {
    char arrPre[] = "ABDECF";
//    char arrPre[] = "ab**cdef**g***hi**j**";
    char arrMid[] = "DBEAFC";
    char arrPost[] = "DEBFCA";
    int len = sizeof(arrPre) / sizeof(char);
    vector<char> pre(arrPre, arrPre + len);
    vector<char> mid(arrMid, arrMid + len);
    vector<char> post(arrPost, arrPost + len);
//    BiTree<char> bit(pre);
//    BiTree<char> bit(pre, mid);
    BiTree<char> bit(mid, post, "mid post");

    cout << "Hello world" << endl;

    cout << "ԭ�������У�";
    bit.preOrder();     // ��������
    cout << endl;

    cout << "���������";
    bit.levelOrder();
    cout << endl;

    cout << "�������Ŀ�ȣ�";
    cout << bit.width() << endl;

    cout << "�������Һ��Ӻ�";
    bit.swapChild();     // ��������
    bit.preOrder();
    bit.swapChild();    // �ٽ�����ȥ
    cout << endl << "�ٽ�����ȥ��";
    bit.preOrder();
    cout << endl;

    cout << "��������Ҷ�ӵ�·��: " << endl;
    bit.pathToLeaf();       // ��������Ҷ�ӵ�·��

    cout << "Ҷ�ӽڵ���Ŀ��" << bit.leafCount() << endl;
    cout<< "����֧�ڵ���Ŀ��" << bit.singleBranchCount() << endl;
    cout<< "˫��֧�ڵ���Ŀ��" << bit.doubleBranchCount() << endl;

    cout << "���ڵ��ƽ�����ӣ�" << endl;
    bit.balanceFactor();

    cout << "�� k ��Ҷ�ӽڵ���: " << bit.leafCountOfLevel(3) << endl;
    cout << "�� k ��Ҷ�ӽڵ���: " << bit.leafCountOfLevel_2(3) << endl;

    cout << "�ڵ� f ���������ȣ�" << bit.allAncestorOfX('f') << endl;
    cout << "�Ƿ�Ϊ��ȫ��������" << bit.isCompleteBiTree() << endl;
    cout << "�Ƿ�Ϊ��ȫ��������" << bit.isCompleteBiTree_2() << endl;
    cout << "��Ҷ�ڵ���ɵĵ����������ң�";
    auto head = bit.getLeafTable();
    while (head) {
        cout << head->data << " ";
        head = head->rightChild;
    }
    return 0;
}
