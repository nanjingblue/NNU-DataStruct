//
// Created by cherry on 2021/11/11.
//

#ifndef LAB5_2_CSTREE_H
#define LAB5_2_CSTREE_H

#include <vector>

template<typename T>
struct CSNode {
    T data;
    CSNode<T> * firstChild, * nextSibling;
};

template<typename T>
class CSTree {
private:
    CSNode<T> * root;   // 树的根节点
    CSNode<T> * createByPre(std::vector<T> &pre, int &i);
public:
    CSTree();
    CSTree(std::vector<T> &pre);
    ~CSTree();
};

template<typename T>
CSTree<T>::CSTree() {
    root = nullptr;
}

template<typename T>
CSNode<T> *CSTree<T>::createByPre(std::vector<T> &pre, int &i) {
    T e = pre[i];
    i++;
    if (e == "*") return nullptr;
    auto p = new CSNode<T>;
    p->data = e;
    p->firstChild = createByPre(pre, i);
    p->nextSibling = createByPre(pre, i);
    return p;
}

template<typename T>
CSTree<T>::CSTree(std::vector<T> &pre) {
    int i = 0;
    root = createByPre(pre, i);
}

#endif //LAB5_2_CSTREE_H
