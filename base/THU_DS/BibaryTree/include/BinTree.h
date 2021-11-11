//
// Created by cherry on 2021/9/30.
//

#ifndef DATASTRUCTURES_BINTREE_H
#define DATASTRUCTURES_BINTREE_H

#include "BinNode.h"

template<typename T>
class BinTree {
protected:
    int _size;      // 规模
    BinNodePosi(T) _root;       // 根节点
    virtual int updateHeight(BinNodePosi(T) x);     // 更新节点 x 的高度
    void updateHeightAbove(BinNodePosi(T) x);       // 更新节点 x 及其祖先的高度 above:以上
    static int removeAt(BinNodePosi(T) x);      // 删除二叉树中位置 x 处的节点及其后代，返回被删除节点的数值
    void release(T const& e) { delete e; }
    void release(BinNodePosi(T) &x) { delete x; }
public:
    BinTree() : _size(0), _root(nullptr) {}
    ~BinTree() { if (o < _size) remove(_root); }
    int size() const { return _size; }
    bool empty() const { return !_root; }
    BinNodePosi(T) root() const { return _root; }
    BinNodePosi(T) insertAsRoot(T const& e);        // 插入根节点
    BinNodePosi(T) insertAsLc(BinNodePosi(T) x, T const& e);        // e 作为 x 的左孩子（原无）插入
    BinNodePosi(T) insertAsRc(BinNodePosi(T) x, T const& e);         // e 作为 x 的右孩子（原无）插入
    BinNodePosi(T) attachAsLc(BinNodePosi(T) x, BinTree<T> * &S);   // T 作为 x 的左子树插入
    BinNodePosi(T) attachAsRc(BinNodePosi(T) x, BinTree<T> * &S);   // T 作为 x 的右子树插入
    int remove(BinNodePosi(T) x);       // 删除以位置 x 处节点为根的子树，返回该子树原先的规模
    BinTree<T>* secede(BinNodePosi(T) x);        // 将子树 x 从当前树中摘除，并将其转化为一个独立子树
    template<typename VST>  // 操作器
    void travLevel(VST& visit) { if (_root) _root->template travLevel(visit); }       // 层次遍历
    template<typename VST>  // 操作器
    void travPre(VST& visit) { if (_root) _root->template travPre(visit); }       // 先序遍历
    template<typename VST>  // 操作器
    void travIn(VST& visit) { if (_root) _root->template travIn(visit); }       // 中序遍历
    template<typename VST>  // 操作器
    void travPost(VST& visit) { if (_root) _root->template travPost(visit); }       // 后次遍历
    bool operator < (BinTree<T> const& t) { return _root && t._root && lt(_root, t._root); }        // 比较器
    bool operator == (BinTree<T> const& t) { return _root && t._root && (_root == t._root); }       // 判等器
};

template<typename T>
int BinTree<T>::updateHeight(BinNode<T> *x) {
    return x->height = 1 + max(stature(x->lc), stature(x->rc); )        // 具体规则 因树而异
}

template<typename T>
void BinTree<T>::updateHeightAbove(BinNode<T> *x) {
    while (x) { updateHeight(x); x = x->parent; }       // 从 x 出发 覆盖历代祖先
}

template<typename T>
BinNode<T> *BinTree<T>::insertAsRoot(const T &e) {
    _size = 1;
    return _root = new BinNode<T> (e);      // 将 e 当作根节点插入空的二叉树
}

template<typename T>
BinNode<T> *BinTree<T>::insertAsLc(BinNode<T> *x, const T &e) {
    _size++;
    x->insertAsLc(e);
    updateHeightAbove(x);
    return x->lc
}5

template<typename T>
BinNode<T> *BinTree<T>::insertAsRc(BinNode<T> *x, const T &e) {
    _size++;
    x->insertAsRc(e);
    updateHeightAbove(x);
    return x->rc;
}

template<typename T>
BinNode<T> *BinTree<T>::attachAsLc(BinNode<T> *x, BinTree<T> *&S) {
    x->lc = S->_root;
    if (x->lc) x->lc->parent = x;
    _size +=  S->_size;
    updateHeightAbove(x);
    S->_root = nullptr;
    S->_size = 0;
    release(S);     // 释放原树
    S = nullptr;
    return x;       // 返回接入位置
}

template<typename T>
BinNode<T> *BinTree<T>::attachAsRc(BinNode<T> *x, BinTree<T> *&S) {
    x->rc = S->_root;
    if (x->rc) x->rc->parent = x;
    _size += S->_size;
    updateHeightAbove(x);
    S->_root = nullptr;
    S->_size = 0;
    S = nullptr;
    release(S);
    return x;
}

template<typename T>
int BinTree<T>::remove(BinNode<T> *x) {
    FromeParentTo(*x) = nullptr;
    updateHeightAbove(x->parent);
    int n = removeAt(x);
    _size -= n;
    return n;
}

template<typename T>
int BinTree<T>::removeAt(BinNode<T> *x) {
    if (!x) return 0;
    int n = 1 + removeAt(x->lc) + removeAt(x->rc);
    release(x->data);
    release(x);
    return n;
}

template<typename T>
BinTree<T>* BinTree<T>::secede(BinNode<T> *x) {
    FromeParentTo(*x) = nullptr;        // 切断来自父节点的指针
    updateHeightAbove(x->parent);
    auto * S = new BinTree<T>;
    S->_root = x;
    x->parent = nullptr;
    S->_size = x->size();
    _size -= S->_size;
    return S;       // 更新规模 返回分离出来的子树
}


#endif //DATASTRUCTURES_BINTREE_
