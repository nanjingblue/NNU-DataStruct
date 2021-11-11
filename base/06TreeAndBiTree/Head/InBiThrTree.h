//
// Created by cherry on 2021/8/25.
// 线索二叉树
//

#ifndef DATASTRUCTURES_INBITHRTREE_H
#define DATASTRUCTURES_INBITHRTREE_H
#include <iostream>
#include <vector>
using namespace std;

enum BiThrNodeType{LINK, THREAD};

template<class T>
struct BiThrNode {
    BiThrNodeType leftType, rightType;
    T data;
    BiThrNode<T> * leftChild, * rightChild;
};

// 线索二叉树的存储结构
template<class T>
class InBiThrTree {
private:
    BiThrNode<T> * root;
    BiThrNode<T> * prenode;
    void InThreaded(BiThrNode<T> *&p);
public:
    InBiThrTree();
    InBiThrTree(vector<T> &pre);        // 根据先序序列创建二叉树
    void InThreaded();      // 中序线索化
    ~InBiThrTree();     // 析构函数
    BiThrNode<T> * GetNext(BiThrNode<T> * p);       // 求中序遍历中的后续结点
    BiThrNode<T> * GetPrev(BiThrNode<T> * p);       // 求中序遍历的前驱结点
    void Travese();     // 利用线索进行中序遍历
    BiThrNode<T> * GetParent(BiThrNode<T> * p );        // 求父结点地址
};


template<class T>
void InBiThrTree<T>::InThreaded(BiThrNode<T> *&p) {
    /*
     * 中序线索化
     * 关于这里传递的参数 Node *&p
     * p 是 Node 指针的引用类型，因为涉及到指针的修改，但传递一级指针是不够的相当于指针的按值传递。
     */
    if(p == NULL)
        return;
    InThreaded(p->leftChild);
    if(p->leftChild == NULL) {
        p->leftType = THREAD;
        p->leftChild = prenode;
    }
    if(p->rightChild == NULL) {
        p->rightType = THREAD;
    }
    if(prenode != NULL) {
        if(prenode->rightType == THREAD)
            prenode->rightChild = p;
    }
    prenode = p;
    InThreaded(p->rightChild);
}

template<class T>
void InBiThrTree<T>::InThreaded() {
    InThreaded(root);
}

template<class T>
BiThrNode<T> *InBiThrTree<T>::GetNext(BiThrNode<T> *p) {
    if(p->rightType == THREAD)
        return p->rightChild;
    p = p->rightChild;
    while (p->leftType == LINK)
        p = p->leftChild;
    return p;
}

template<class T>
BiThrNode<T> *InBiThrTree<T>::GetPrev(BiThrNode<T> *p) {
    if(p->leftType == THREAD)
        return p->leftChild;
    p = p->leftChild;
    while (p->rightType == LINK) {
        p = p->rightChild;
    }
    return p;
}

template<class T>
void InBiThrTree<T>::Travese() {
    BiThrNode<T> * p = root;
    while (p->leftType == LINK) {
        // 找到中序遍历的起点
        p = p->leftChild;
    }
    while (p != NULL) {
        cout << p->data << " ";
        p = GetNext(p);
    }
}

template<class T>
BiThrNode<T> *InBiThrTree<T>::GetParent(BiThrNode<T> *p) {
    if(p == NULL)
        return NULL;
    BiThrNode<T> * parent;
    // 左孩子情况
    parent = p;
    while (parent->rightType == LINK)
        parent = parent->rightChild;
    parent = parent->leftChild;
    if(parent != NULL && parent->leftType)
        return parent;
    // 右孩子情况
    parent = p;
    while (parent->rightType == LINK) {
        parent = parent->rightChild;
    }
    parent = parent->rightChild;
    return parent;
}


#endif //DATASTRUCTURES_INBITHRTREE_H
