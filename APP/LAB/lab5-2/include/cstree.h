//
// Created by cherry on 2021/11/11.
//

#ifndef LAB5_2_CSTREE_H
#define LAB5_2_CSTREE_H

#include <vector>
#include <iostream>
#include <stack>

template<typename T>
struct Coupe {
    T parent;
    T child;
};


template<typename T>
struct CSNode {
    T data;
    int degree;
    CSNode<T> * firstChild, * nextSibling;
};

template<typename T>
class CSTree {
private:
    CSNode<T> * root;   // 树的根节点
    CSNode<T> * createByPre(std::vector<T> &pre, int &i);
    void insertNode(Coupe<T> &p);
    CSNode<T> * Search(CSNode<T> * p, T e);
    void free(CSNode<T> * p);
    void preOrder(CSNode<T> * p);
    void postOrder(CSNode<T> * p);
    void Degree(CSNode<T> * p);
    int Height(CSNode<T> * p);
    void pathToLeaves(CSNode<T> * p, std::stack<T> s);
public:
    CSTree();
    explicit CSTree(std::vector<Coupe<T>> &ps);
    CSTree(std::vector<T> &pre, std::string type);
    ~CSTree();
    void preOrder();
    void postOrder();
    void Degree();
    int Height();
    void pathToLeaves();
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
CSTree<T>::CSTree(std::vector<T> &pre, std::string type) {
    int i = 0;
    root = createByPre(pre, i);
}

template<typename T>
CSTree<T>::CSTree(std::vector<Coupe<T>> &ps) {
    if (ps.empty()) {
        root = nullptr;
        return;
    }
    // 创建根节点
    root = new CSNode<T>;
    root->data = ps[0].parent;
    root->firstChild = root->nextSibling = nullptr;
    // 向树中添加每个序偶对应的节点和关系
    for (int i = 0; i < ps.size(); ++i) {
        insertNode(ps[i]);
    }
}

template<typename T>
void CSTree<T>::insertNode(Coupe<T> &p) {
    // 创建新节点
    CSNode<T> * child = new CSNode<T>;
    child->data = p.child;
    child->firstChild = child->nextSibling = nullptr;
    // 查找值为p.parent的节点
    CSNode<T> * parent = Search(root, p.parent);
    if (parent->firstChild == nullptr) {
        parent->firstChild = child;
    } else {
        parent = parent->firstChild;
        while (parent->nextSibling != nullptr) {
            parent = parent->nextSibling;
        }
        parent->nextSibling = child;
    }
}

template<typename T>
CSNode<T> * CSTree<T>::Search(CSNode<T> *p, T e) {
    if (p == nullptr)
        return nullptr;
    if (p->data == e)
        return p;
    CSNode<T> * q = Search(p->firstChild, e);
    if (q != nullptr)
        return  q;
    return Search(p->nextSibling, e);
}

template<typename T>
CSTree<T>::~CSTree() {
    free(root);
}

template<typename T>
void CSTree<T>::free(CSNode<T> *p) {
    if (p == nullptr) return;
    free(p->firstChild);
    free(p->nextSibling);
    delete p;
}

template<typename T>
void CSTree<T>::preOrder(CSNode<T> * p) {
    if (p == nullptr) return;
    std::cout << p->data << " " << p->degree << std::endl;
    preOrder(p->firstChild);
    preOrder(p->nextSibling);
}

template<typename T>
void CSTree<T>::preOrder() {
    preOrder(root);
}

template<typename T>
void CSTree<T>::postOrder() {
    postOrder(root);
}

template<typename T>
void CSTree<T>::postOrder(CSNode<T> *p) {
    if (p == nullptr) return;
    postOrder(p->firstChild);
    std::cout << p->data;
    postOrder(p->nextSibling);
}

template<typename T>
void CSTree<T>::Degree(CSNode<T> * p) {
    if (p == nullptr) return;
    p->degree == 0;
    for (CSNode<T> * child  = p->firstChild; child; child = child->nextSibling)
        p->degree++;
    Degree(p->firstChild);
    Degree(p->nextSibling);
}

template<typename T>
void CSTree<T>::Degree() {
    Degree(root);
}

template<typename T>
int CSTree<T>::Height(CSNode<T> * p) {
    if (p == nullptr) return 0;
    int maxHeight = 0;
    for (p = p->firstChild; p; p->nextSibling) {
        int height = Height(p);
        if (height > maxHeight)
            maxHeight = height;
    }
    return maxHeight + 1;
}

template<typename T>
int CSTree<T>::Height() {
    Height(root);
}

/*
 *  pathToLeaves 孩子兄弟表示法 根到节点的路径
 *  孩子兄弟法判断是叶节点：firstChild == nullptr
 */
template<typename T>
void CSTree<T>::pathToLeaves(CSNode<T> *p, std::stack<T> s) {
    if (p == nullptr) return;
    s.push(p->data);
    if (p->firstChild == nullptr) {
        std::string path;
        s.pop();
        while (s.size()) {
            path = s.top() + path;
            s.pop();
        }
        std::cout << path << p->data;
        std::cout << std::endl;
    } else {
        for (CSNode<T> * child = p->firstChild; child; child = child->nextSibling) {
            pathToLeaves(child, s);
        }
    }
    s.pop();
}

template<typename T>
void CSTree<T>::pathToLeaves() {
    std::stack<T> s;
    pathToLeaves(root, s);
}

#endif //LAB5_2_CSTREE_H
