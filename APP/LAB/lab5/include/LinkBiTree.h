//
// Created by 20190408ZSH on 2021/11/02
// ��ʽ�������ĸ���ʵ��
// ���� ������ ��Ϊ�ݹ�� �������е�����ĸ���
//

#ifndef DATASTRUCTURES_LINKBITREE_H
#define DATASTRUCTURES_LINKBITREE_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// ��������ṹ
template<class T>
struct BiNode {
    T data;     // �������
//    BiNode<T> *parent;
    BiNode<T> *leftChild;
    BiNode<T> *rightChild;
};

// �Զ�������ṹ ������ģ��
template<class T>
class BiTree {
private:
    BiNode<T> * root;       // ��ָ��
    BiNode<T> * createByPre(vector<T> &pre, int &i);        // �����������й���������й�
    BiNode<T> * createByPreMid(vector<T> &pre, vector<T> &mid, int ipre, int imid, int n);  // ����������������й���������й�
    BiNode<T> * copy(BiNode<T> *p);     // �뿽������������й�
    void free(BiNode<T> *p);        // �����������й�
    void preOrder(BiNode<T> *p);    // ����������й�
    void inOrder(BiNode<T> *p);     // ����������й�
    void postOrder(BiNode<T> *p);       // ���������й�
    int count(BiNode<T> *p);        // ����������������й�
    int hight(BiNode<T> *p);        // �����������߶��й�
    BiNode<T> * search(BiNode<T> *p, T e);   // ���ڸ���ֵ e ���ҽ��
    BiNode<T> * searchParent(BiNode<T> *p, BiNode<T> *child);   // ���ڲ���ָ�����ĸ����
    void swapClild(BiNode<T> *p);        // �뽻��ÿ���ڵ�����Һ������
    void pathToLeaf(BiNode<T> *p, string &path);      // ��������ڵ㵽ÿ��Ҷ�ڵ��·���й�
    int leafCount(BiNode<T> *p);       // ��ͳ�� Ҷ�ӽڵ��� ���
    int singleBranchCount(BiNode<T> *p);        // ��ͳ�� ����֧�ڵ���Ŀ�й�
    int doubleBranchCount(BiNode<T> *p);        // ��ͳ�� ˫��֧�ڵ���Ŀ�й�
public:
    BiTree();
    explicit BiTree(vector<T> &pre);     // ���������й��������
    BiTree(vector<T> &pre, vector<T> &mid);     // �������������й��������
    BiTree(BiTree<T> &tree);    // �������캯��
    ~BiTree();  // ��������
    void preOrder();        // �������
    void inOrder();     // �������
    void postOrder();       // �������
    void levelOrder();      // �������
    int count();    // ͳ�ƽ�����
    int hight();    // ����������߶�
    BiNode<T> * search(T e);        // ����ֵ e ���ҽ��
    BiNode<T> * searchParent(BiNode<T> *child);     // ����ָ�����ĸ����
    void swapClild();    // ����ÿ���ڵ�����Һ���
    void pathToLeaf();      // ������ڵ㵽ÿ��Ҷ�ڵ��·��
    int leafCount();        // ��ȡҶ�ӽڵ���Ŀ
    int singleBranchCount();        // ��ȡ����֧�ڵ���Ŀ
    int doubleBranchCount();        // ��ȡ˫���ӽڵ���Ŀ�й�
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
    T e = pre[i];       // ��ȡ��ǰ����
    i++;
    if(e == '*')
        return NULL;
    auto *p = new BiNode<T>;   // �����½��
    p->data = e;
    p->leftChild = createByPre(pre, i);     // ����������
    p->rightChild = createByPre(pre,i);     // ����������
    return p;
}

template<class T>
BiTree<T>::BiTree() {
    // ����
    root = nullptr;
}

template<class T>
BiTree<T>::BiTree(vector<T> &pre) {
    // �ɴ���ָ���ǵ��������й��������
    // �������ͨ��һ�������޷�Ψһȷ��һ��������
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
    for (i = 0; i < n; ++i) {       // �����������ж�λ���ڵ�
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
    int left = count(p->leftChild);     // �������Ľڵ���
    int right = count(p->rightChild);       // �������Ľڵ���
    return 1 + left + right;
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
    BiNode<T> * q = search(p->leftChild, e);    // �����������в���
    if(q != NULL)
        return q;
    return search(p->rightChild, e);    // ������Ϊ�鵽����������
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

template<class T>
void BiTree<T>::swapClild(BiNode<T> *p) {
    if (p == nullptr) {
        return;
    }
    // �����ǰ�ڵ�����Ӻ��Һ�����һ������ ����Ҫ���н���
    if (p->leftChild || p->rightChild) {
        BiNode<T> * temp;       // ���õ������� ����ɽ���
        temp = p->leftChild;
        p->leftChild = p->rightChild;
        p->rightChild = temp;
    }
    swapClild(p->leftChild);    // ��ǰ�ڵ�����Һ��ӽ������ ���������� ��������
    swapClild(p->rightChild);   // ���������� �������� �����Һ��Ӽ�������
}

template<class T>
void BiTree<T>::swapClild() {
    swapClild(root);
}

/*
 *  pathToLeaf ������ڵ㵽����Ҷ�ڵ��·��
 *  DFS�����������������˼·
 *  ���ﲢû�ж�·�����б��� ֻʹ����һ�� string���͵� path������ͨ������������ path �ĸ���
 *  ����������� ����Ҷ�ڵ�����
 */
template<class T>
void BiTree<T>::pathToLeaf(BiNode<T> *p, string &path) {
    if (p == nullptr) return;
    if (p->leftChild == nullptr && p->rightChild == nullptr) {  // ��Ҷ�ڵ�  ���·�� ������
        cout << path << endl;
        return;
    }
    path += " -> ";     // ˵����ǰ�ڵ�������һ������  "->" ָ����һ���ڵ�
    // ��Ϊ�ڵ����ֻ��һ������ ����Ҫ���ж�ĳ�����Ӵ治����
    if (p->leftChild) {     // ������Ӵ��� ����������
        path += p->leftChild->data;
        pathToLeaf(p->leftChild, path);
        path.pop_back();        // ����  �ָ���û��������·�������
    }
    if (p->rightChild) {    // ����Һ��Ӵ��� �����Һ���
        path += p->rightChild->data;
        pathToLeaf(p->rightChild, path);
        path.pop_back();     // ����
    }
}

template<class T>
void BiTree<T>::pathToLeaf() {
    string path;
    path += root->data;
    pathToLeaf(root, path);
}

/*
 *  leafCount ��ȡҶ�ӽڵ�����ݹ��
 *  ����һ�����ĸ��ڵ㣬Ҷ����Ŀ = ������Ҷ���� + ������Ҷ����Ŀ
 *  �����Ҷ�Ӿͷ��� 1 ����Ҷ�Ӿͷ��� 0 + ������Ҷ����
 */
template<class T>
int BiTree<T>::leafCount(BiNode<T> *p) {
    if (p == nullptr) {
        return 0;
    }
    int left = leafCount(p->leftChild);
    int right = leafCount(p->rightChild);
    return left + right + ( (p->leftChild == nullptr && p->rightChild == nullptr)  ? 1 : 0 );
}

template<class T>
int BiTree<T>::leafCount() {
    return leafCount(root);
}

/*
 * singleBranchCount ��ȡ����֧�ڵ���Ŀ
 * ԭ��ͬ ��ȡҶ�ӽڵ���Ŀ ֻ��������� ���Һ���ֻ��һ�����ڲż� 1
 */
template<class T>
int BiTree<T>::singleBranchCount(BiNode<T> *p) {
    if (p == nullptr) {
        return 0;
    }
    int left = singleBranchCount(p->leftChild);
    int right = singleBranchCount(p->rightChild);
    return left + right + ( (p->leftChild == nullptr && p->rightChild != nullptr) || (p->leftChild != nullptr && p->rightChild == nullptr) ? 1 : 0);
}

template<class T>
int BiTree<T>::singleBranchCount() {
    return singleBranchCount(root);
}

/*
 *  doubleBranchCount ��ȡ˫��֧�ڵ���Ŀ
 *  ԭ��ͬ ��Ҷ�ӽڵ���Ŀ ֻ��������� ���Һ��Ӷ����ڲż�1
 */
template<class T>
int BiTree<T>::doubleBranchCount(BiNode<T> *p) {
    if (p == nullptr) {
        return 0;
    }
    int left = singleBranchCount(p->leftChild);
    int right = singleBranchCount(p->rightChild);
    return left + right + ( (p->leftChild != nullptr && p->rightChild != nullptr) ? 1 : 0);
}

template<class T>
int BiTree<T>::doubleBranchCount() {
    return doubleBranchCount(root);
}

#endif //DATASTRUCTURES_LINKBITREE_H
