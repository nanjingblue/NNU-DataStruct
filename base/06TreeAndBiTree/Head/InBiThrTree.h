//
// Created by cherry on 2021/8/25.
// ����������
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

// �����������Ĵ洢�ṹ
template<class T>
class InBiThrTree {
private:
    BiThrNode<T> * root;
    BiThrNode<T> * prenode;
    void InThreaded(BiThrNode<T> *&p);
public:
    InBiThrTree();
    InBiThrTree(vector<T> &pre);        // �����������д���������
    void InThreaded();      // ����������
    ~InBiThrTree();     // ��������
    BiThrNode<T> * GetNext(BiThrNode<T> * p);       // ����������еĺ������
    BiThrNode<T> * GetPrev(BiThrNode<T> * p);       // �����������ǰ�����
    void Travese();     // �������������������
    BiThrNode<T> * GetParent(BiThrNode<T> * p );        // �󸸽���ַ
};


template<class T>
void InBiThrTree<T>::InThreaded(BiThrNode<T> *&p) {
    /*
     * ����������
     * �������ﴫ�ݵĲ��� Node *&p
     * p �� Node ָ����������ͣ���Ϊ�漰��ָ����޸ģ�������һ��ָ���ǲ������൱��ָ��İ�ֵ���ݡ�
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
        // �ҵ�������������
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
    // �������
    parent = p;
    while (parent->rightType == LINK)
        parent = parent->rightChild;
    parent = parent->leftChild;
    if(parent != NULL && parent->leftType)
        return parent;
    // �Һ������
    parent = p;
    while (parent->rightType == LINK) {
        parent = parent->rightChild;
    }
    parent = parent->rightChild;
    return parent;
}


#endif //DATASTRUCTURES_INBITHRTREE_H
