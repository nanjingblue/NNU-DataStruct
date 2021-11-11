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

    cout << "原先序序列：";
    bit.preOrder();     // 先序序列
    cout << endl;

    cout << "层序遍历：";
    bit.levelOrder();
    cout << endl;

    cout << "二叉树的宽度：";
    cout << bit.width() << endl;

    cout << "交换左右孩子后：";
    bit.swapChild();     // 交换孩子
    bit.preOrder();
    bit.swapChild();    // 再交换回去
    cout << endl << "再交换回去：";
    bit.preOrder();
    cout << endl;

    cout << "根到所有叶子的路径: " << endl;
    bit.pathToLeaf();       // 根到所有叶子的路径

    cout << "叶子节点数目：" << bit.leafCount() << endl;
    cout<< "单分支节点数目：" << bit.singleBranchCount() << endl;
    cout<< "双分支节点数目：" << bit.doubleBranchCount() << endl;

    cout << "各节点的平衡因子：" << endl;
    bit.balanceFactor();

    cout << "第 k 层叶子节点数: " << bit.leafCountOfLevel(3) << endl;
    cout << "第 k 层叶子节点数: " << bit.leafCountOfLevel_2(3) << endl;

    cout << "节点 f 的所有祖先：" << bit.allAncestorOfX('f') << endl;
    cout << "是否为完全二叉树：" << bit.isCompleteBiTree() << endl;
    cout << "是否为完全二叉树：" << bit.isCompleteBiTree_2() << endl;
    cout << "由叶节点组成的单链表，从左到右：";
    auto head = bit.getLeafTable();
    while (head) {
        cout << head->data << " ";
        head = head->rightChild;
    }
    return 0;
}
