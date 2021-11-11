//
// Created by cherry on 2021/8/26.
//

#ifndef DATASTRUCTURES_CHILDBROTHERTREE_H
#define DATASTRUCTURES_CHILDBROTHERTREE_H

#include <iostream>
#include <vector>

template<class T>
struct ChildBroNode {
    T data;
    int degree;
    ChildBroNode<T> * firstChild, * nextSibling;
};

template<class T>
struct Couple {
    T parent;
    T child;
};

template<class T>
class ChildBroTree {
    ChildBroNode<T> * root;
    ChildBroNode<T> * Search(ChildBroNode<T> *p, T x);
    int Height(ChildBroNode<T> * p);
    void Degree(ChildBroNode<T> *p);
public:
    ChildBroTree() {
        root = NULL;
    }
    ChildBroTree(vector< Couple<T> > &ps);
    void InsertNode(Couple<T> &p);
    int Height();
    void Degree();
    ChildBroNode<T> * Search(T x);
//    ~ChildBroTree();
};

template<class T>
ChildBroTree<T>::ChildBroTree(vector<Couple<T>> &ps) {
    if(ps.empty()) {
        root = NULL;
        return;
    }
    root = new ChildBroNode<T>;
    root->data = ps[0].parent;
    root->firstChild = root->nextSibling = NULL;
    for (int i = 0; i < ps.size(); ++i) {
        InsertNode(ps[i]);
    }
}

template<class T>
void ChildBroTree<T>::InsertNode(Couple<T> &p) {
    auto * child = new ChildBroNode<T>;
    child->firstChild = child->nextSibling = NULL;
    ChildBroNode<T> * parent = Search(p.parent);
    if(parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        parent = parent->firstChild;
        while (parent->nextSibling != NULL) {
            parent = parent->nextSibling;
        }
        parent->nextSibling = child;
    }
}

template<class T>
ChildBroNode<T> *ChildBroTree<T>::Search(ChildBroNode<T> *p, T x) {
    if(p == NULL)
        return NULL;
    if(p->data == x)
        return p;
    ChildBroNode<T> * q = search(p->firstChild, x);
    if(q != NULL)
        return q;
    return search(p->nextSibling, x);

}

template<class T>
ChildBroNode<T> *ChildBroTree<T>::Search(T x) {
    return Search(root, x);
}

template<class T>
int ChildBroTree<T>::Height(ChildBroNode<T> *p) {
    if(p == NULL)
        return 0;
    int maxHeight = 0;
    for(p = p->firstChild; p; p = p->nextSibling) {
        int height = Height(p);     // 计算各个子树的高度
        if(height > maxHeight) {
            maxHeight = height;
        }
    }
    return maxHeight + 1;
}

template<class T>
int ChildBroTree<T>::Height() {
    return Height(root);
}

template<class T>
void ChildBroTree<T>::Degree(ChildBroNode<T> *p) {
    if(p == NULL)
        return;
    p->degree = 0;
    for(ChildBroNode<T> *child = p->firstChild; child != NULL; child =child->nextSibling)
        p->degree++;
    Degree(p->firstChild);
    Degree(p->nextSibling);
}

template<class T>
void ChildBroTree<T>::Degree() {
    Degree(root);
}


#endif //DATASTRUCTURES_CHILDBROTHERTREE_H
