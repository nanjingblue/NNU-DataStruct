//
// Created by cherry on 2021/8/23.
//

#ifndef DATASTRUCTURES_LINKBITREE_H
#define DATASTRUCTURES_LINKBITREE_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 二叉链表结构
template<class T>
struct BiNode {
    T data;     // 结点数据
//    BiNode<T> *parent;
    BiNode<T> *leftChild;
    BiNode<T> *rightChild;
};

// 以二叉链表结构 构建类模板
template<class T>
class BiTree {
private:
    BiNode<T> * root;       // 根指针
    BiNode<T> * createByPre(vector<T> &pre, int &i);        // 与由先序序列构造二叉树有关
    BiNode<T> * createByPreMid(vector<T> &pre, vector<T> &mid, int ipre, int imid, int n);  // 与由先序和中序序列构造二叉树有关
    BiNode<T> * copy(BiNode<T> *p);     // 与拷贝构造二叉树有关
    void free(BiNode<T> *p);        // 与析构函数有关
    void preOrder(BiNode<T> *p);    // 与先序遍历有关
    void inOrder(BiNode<T> *p);     // 与中序遍历有关
    void postOrder(BiNode<T> *p);       // 与后序遍历有关
    int count(BiNode<T> *p);        // 与计算二叉树结点数有关
    int hight(BiNode<T> *p);        // 与计算二叉树高度有关
    BiNode<T> * search(BiNode<T> *p, T e);   // 关于根据值 e 查找结点
    BiNode<T> * searchParent(BiNode<T> *p, BiNode<T> *child);   // 关于查找指定结点的父结点
public:
    BiTree();
    explicit BiTree(vector<T> &pre);     // 由先序序列构造二叉树
    BiTree(vector<T> &pre, vector<T> &mid);     // 由先序、中序序列构造二叉树
    BiTree(BiTree<T> &tree);    // 拷贝构造函数
    ~BiTree();  // 析构函数
    void preOrder();        // 先序遍历
    void inOrder();     // 中序遍历
    void postOrder();       // 后序遍历
    void levelOrder();      // 层序遍历
    int count();    // 统计结点个数
    int hight();    // 计算二叉树高度
    BiNode<T> * search(T e);        // 根据值 e 查找结点
    BiNode<T> * searchParent(BiNode<T> *child);     // 查找指定结点的父结点
};

template<class T>
void BiTree<T>::preOrder(BiNode<T> *p) {
    if(p == NULL)
        return;
    cout << p->data;
    preOrder(p->leftChild);
    preOrder(p->rightChild);
}

template<class T>
void BiTree<T>::preOrder() {
    preOrder(root);
}

template<class T>
void BiTree<T>::inOrder(BiNode<T> *p) {
    if(p == NULL)
        return;
    inOrder(p->leftChild);
    cout << p->data << " ";
    inOrder(p->rightChild);
}

template<class T>
void BiTree<T>::inOrder() {
    inOrder(root);
}

template<class T>
void BiTree<T>::postOrder(BiNode<T> *p) {
    if(p == NULL)
        return;
    postOrder(p->leftChild);
    postOrder(p->rightChild);
    cout << p->data << " ";
}

template<class T>
void BiTree<T>::postOrder() {
    postOrder(root);
}

template<class T>
void BiTree<T>::levelOrder() {
    if(root == NULL)
        return;
    queue<BiNode<T> *> Q;
    Q.push(root);
    while (!Q.empty()) {
        BiNode<T> *p = Q.front();
        Q.pop();
        cout << p->data << " ";
        if(p->leftChild != NULL)
            Q.push(p->leftChild);
        if(p->rightChild != NULL)
            Q.push(p->rightChild);
    }
}

template<class T>
BiNode<T> *BiTree<T>::createByPre(vector<T> &pre, int &i) {
    cout << "start" << endl;
    T e = pre[i];       // 提取当前数据
    i++;
    if(e == '*')
        return NULL;
    auto *p = new BiNode<T>;   // 创建新结点
    p->data = e;
    p->leftChild = createByPre(pre, i);     // 创建左子树
    p->rightChild = createByPre(pre,i);     // 创建右子树
    return p;
}

template<class T>
BiTree<T>::BiTree() {
    // 空树
    root = NULL;
}

template<class T>
BiTree<T>::BiTree(vector<T> &pre) {
    // 由带空指针标记的先序序列构造二叉树
    // 否则仅仅通过一个序列无法唯一确定一个二叉树
    // abd**e**cf***
    int i = 0;
    root = createByPre(pre, i);
}

template<class T>
BiNode<T> *BiTree<T>::createByPreMid(vector<T> &pre, vector<T> &mid, int ipre, int imid, int n) {
    if(n == 0)
        return NULL;
    auto *p = new BiNode<T>;
    p -> data = pre[ipre];
    int i;
    for (i = 0; i < n; ++i) {       // 在中序序列中定位根节点
        if(pre[ipre] == mid[imid + i])
            break;
    }
    p->leftChild = createByPreMid(pre, mid, ipre+1, imid, i);
    p->rightChild = createByPreMid(pre, mid, ipre, imid+i+1, n-i-1);
    return p;
}

template<class T>
BiTree<T>::BiTree(vector<T> &pre, vector<T> &mid) {
    int n = pre.size();
    root = createByPreMid(pre, mid, 0,0,n);
}

template<class T>
BiTree<T>::BiTree(BiTree<T> &tree) {
    root = copy(tree.root);
}

template<class T>
BiNode<T> *BiTree<T>::copy(BiNode<T> *p) {
    if(p == NULL)
        return NULL;
    auto * newp = new BiNode<T>;
    newp->data = p->data;
    newp->leftChild = copy(p->leftChild);
    newp->rightChild = copy(p->rightChild);
    return newp;
}

template<class T>
void BiTree<T>::free(BiNode<T> *p) {
    if(p == NULL)
        return;
    free(p->leftChild);
    free(p->rightChild);
    delete p;
}

template<class T>
BiTree<T>::~BiTree() {
    free(root);
}

template<class T>
int BiTree<T>::count(BiNode<T> *p) {
    if(p == NULL)
        return 0;
    int left = count(p->leftChild);
    int right = count(p->rightChild);
    return 1+left+right;
}

template<class T>
int BiTree<T>::count() {
    return count(root);
}

template<class T>
int BiTree<T>::hight(BiNode<T> *p) {
    if(p == NULL)
        return 0;
    int left = hight(p->leftChild);
    int right = hight(p->rightChild);
    return max(left, right) + 1;
}

template<class T>
int BiTree<T>::hight() {
    return hight(root);
}

template<class T>
BiNode<T> *BiTree<T>::search(BiNode<T> *p, T e) {
    if(p == NULL)
        return NULL;
    if(p->data == e)
        return p;
    BiNode<T> * q = search(p->leftChild, e);    // 先在左子树中查找
    if(q != NULL)
        return q;
    return search(p->rightChild, e);    // 左子树为查到在右子树查
}

template<class T>
BiNode<T> *BiTree<T>::search(T e) {
    return search(root, e);
}

template<class T>
BiNode<T> *BiTree<T>::searchParent(BiNode<T> *p, BiNode<T> *child) {
    if(p == NULL || child == NULL)
        return NULL;
    if(p->leftChild == child || p->rightChild == child)
        return p;
    BiNode<T> * q = searchParent(p->leftChild, child);
    if(q != NULL)
        return q;
    return searchParent(p->rightChild, child);
}

template<class T>
BiNode<T> *BiTree<T>::searchParent(BiNode<T> *child) {
    return searchParent(root, child);
}

#endif //DATASTRUCTURES_LINKBITREE_H
