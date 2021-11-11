//
// Created by cherry on 2021/9/29.
//
#include <stack>


#ifndef DATASTRUCTURES_BINNODE_H
#define DATASTRUCTURES_BINNODE_H

#define BinNodePosi(T) BinNode<T> * // 节点位置
#define stature(p) ((p) ? (p)->height : -1)     // 节点高度（与“空树高度为 -1 ”的约定相统一
#define IsRoot(x) (!(x).parent)
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lc))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!HasChild(x))
// 与 BinNode 具有特定关系的节点及指针
#define sibling(p) (IsLChild(*(p)) ? (p)->parent->rc : (p)->parent->lc)     // 兄弟
#define uncle(p) (IsLChild(*((x)->parent)) ? (x)->parent->parent->rc : (x)->parent->parent->lc)
#define FromeParentTo(x) (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent-lc : (x)->parent->rc))  // 来自父亲的引用
typedef enum { RB_RED, RB_BLACK } RBColor;      // 节点颜色

template<typename T>
struct BinNode {
    T data;
    BinNodePosi(T) parent;
    BinNodePosi(T) lc;
    BinNodePosi(T) rc;
    int height;     // 高度（通用）
    int npl;        // Null Path Length (左式堆，也可以直接用 height 代替)
    RBColor color;      // 颜色（红黑树）
    // 构造函数
    BinNode(): parent(nullptr), lc(nullptr), rc(nullptr), height(0), npl(1), color(RB_RED) {}
    explicit BinNode(T e, BinNodePosi(T) p = nullptr, BinNodePosi(T) lc = nullptr, BinNodePosi(T) rc = nullptr, int h = 0, int l = 1, RBColor c = RB_RED)
    : data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}
    // 操作接口
    int size(); // 统计当前节点后代总数，亦即以其为根的子树规模
    BinNodePosi(T) insertAsLc(T const& e) { return lc = new BinNode<T>(e, this); }      // 作为当前节点的左孩子插入新节点
    BinNodePosi(T) insertAsRc(T const& e) { return rc = new BinNode<T>(e, this); }       // 作为当前节点的右孩子插入新节点
    BinNodePosi(T) succ();      // 取当前节点的直接后继
    // 遍历算法接口
    template<typename VST> void travLevel(VST&);        // 子树层次遍历
    template<typename VST> void travPre(VST&);      // 子树先序遍历
    template<typename VST> void travIn(VST&);       // 子树中序遍历
    template<typename VST> void travPost(VST&);     // 子树的后序遍历
    // 比较器 判等器
    bool operator < (BinNode<T> const& bn) { return data < bn.data; }      // 小于
    bool operator > (BinNode<T> const& bn) { return data > bn.data; }      // 大于
    bool operator == (BinNode<T> const& bn) { return data == bn.data; }     // 等于
    // 遍历方法
    template<typename VST> void travPre_R(BinNodePosi(T) x, VST& visit);
    template<typename VST> void travIn_R(BinNodePosi(T) x, VST& visit);
    template<typename VST> void travPost_R(BinNodePosi(T) x, VST& visit);
    template<typename VST> static void visitAlongLeftBranch(BinNodePosi(T) x, VST &visit, std::stack<BinNodePosi(T)> &s);
    template<typename VST> void travPre_I2(BinNodePosi(T) x, VST &visit);
    static void goAlongLeftBranch(BinNodePosi(T) x, std::stack<BinNodePosi(T)> &S);
    template<typename VST> void travIn_I1(BinNodePosi(T) x, VST &visit);
    template<typename VST> void travIn_I2(BinNodePosi(T) x, VST &visit);
    template<typename VST> void travIn_I3(BinNodePosi(T) x, VST &visit);
    static void gotoHLVFL(std::stack<BinNodePosi(T)> &S);
    template<typename VST> void travPost_I(BinNodePosi(T) x, VST &visit);
};

template<typename T>
template<typename VST>
void BinNode<T>::travLevel(VST & visit) {
    switch (rand() % 5) {   // 随机选择以做测试，共5种
        case 1: travIn_I1(this, visit); break;        // 迭代版 1
        case 2: travIn_I2(this, visit); break;      // 迭代版 2
        case 3: travIn_I3(this, visit); break;      // 迭代版 3
        case 4: travIn_I4(this, visit); break;      // 迭代版 4
        default: travIn_R(this, visit); break;   // 递归版
    }
}

/*
 * travPre_R
 * 二叉树先序遍历算法 递归版
 */
template<typename T>
template<typename VST>
void BinNode<T>::travPre_R(BinNodePosi(T) x, VST &visit) {      // 二叉树先序遍历算法（递归版）
    if (!x) return;
    visit(x->data);
    travPre_R(x->lc, visit);
    travPre_R(x->rc, visit);
}

/*
 * travPost_R
 * 二叉树后序遍历 递归版
 */
template<typename T>
template<typename VST>
void BinNode<T>::travPost_R(BinNode<T> *x, VST &visit) {
    if (!x) return;
    travPre_R(x->lc, visit);
    travPre_R(x->rc, visit);
    visit(x->data);
}

/*
 * travIn_R
 * 二叉树中序遍历 递归版
 */
template<typename T>
template<typename VST>
void BinNode<T>::travIn_R(BinNode<T> *x, VST &visit) {
    if (!x) return;
    travIn_R(x->lc, visit);
    visit(x->data);
    travIn_R(x->rc, visit);
}

/*
 * visitAlongLeftBranch
 * 与迭代版先序遍历有关
 * 从当前节点出发，沿左分支不断深入，直至没有左分支的节点，沿途节点遇到后立即访问
 */
template<typename T, typename VST>
void BinNode<T>::visitAlongLeftBranch(BinNode<T> *x, VST &visit, std::stack<BinNode<T> *> &s) {
    while (x) {
        visit(x->data); // 访问当前节点
        if (HasRChild(x))
            s.push(x->rc);
        x = x->lc;  // 沿左分支深入一层
    }
}

/*
 *  travPre_I2
 *  二叉树先序遍历算法 迭代版 #2
 *  先调用 visitAlongLeftBranch() 自顶向下访问最左侧通路沿途的各个节点
 *  辅助栈 记录最左侧通路上的节点，以便确定其对应右子树自底而上的遍历次序。
 *
 *  原理：先序遍历序列可分解成两段：沿最左侧通路自顶向下访问各节点，以及自底向上遍历对应右子树。
 */
template<typename T>
template<typename VST>
void BinNode<T>::travPre_I2(BinNode<T> *x, VST &visit) {
    std::stack<BinNodePosi(T)> S;
    while (true) {
        visitAlongLeftBranch(x, visit, S);      // 从当前节点出发，逐批访问
        if (S.empty())
            break;
        x = S.pop();        // 当初下一批的起点
    }
}

/*
 *  goAlongLeftBranch
 *  从当前节点出发，沿左分支不断深入，直至没有左分支的节点
 */
template<typename T>
void BinNode<T>::goAlongLeftBranch(BinNode<T> *x, std::stack<BinNode<T> *> &S) {
    while (x) {
        S.push(x);
        x = x->lc;
    }
}

/*
 *  travIn_I1
 *  二叉树中序遍历 迭代版 #1
 *  原理：由先序遍历迭代版#2启发，顺着最左侧通路， 自底向上(借助栈)依次访问沿途各节点及其右子树
 */
template<typename T>
template<typename VST>
void BinNode<T>::travIn_I1(BinNode<T> *x, VST &visit) {
    std::stack<BinNodePosi(T)> S;   // 辅助栈
    while (true) {
        goAlongLeftBranch(x, S);        // 从当前节点出发， 逐批入栈
        if (S.empty())
            break;      // 直到所有节点处理完毕
        x = S.pop();        // 弹出栈顶节点并访问
        visit(x->data);
        x = x->rc;  // 转向右子树
    }
}

/*
 *  succ
 * 定位节点 v 在中序遍历的直接后继
 * 原理：若存在右孩子，则后继必是右子树的最左节点，否则，若存在后继，则为将当前节点包含于其左子树的最低祖先
 */
template<typename T>
BinNode<T> *BinNode<T>::succ() {
    BinNodePosi(T) s = this;    // 记录后继的临时变量
    if (rc) {       // 若存在右孩子，则直接后继必在右子树中，具体地就是
        s = rc;     // 右子树中
        while (HasLChild(*s)) {
            s = s->lc;      // 最靠左(最小)的节点
        }
    } else {        // 否则，直接后继应该是 将当前节点包含于其左子树的最低祖先
        while (IsRChild(*s)) {      // 逆向地沿右向分支，不断朝左上方移动
            s = s->parent;
        }
        s = s->parent;      // 最后再朝右上角移动一步，即抵达直接后继（如果存在）
    }
    return s;
}

/*
 * travIn_I2
 * 二叉树遍历算法 迭代版 #2
 * #2 只是 #1 的等价形式，借助 #2 可便捷地设计 #3
 */
template<typename T>
template<typename VST>
void BinNode<T>::travIn_I2(BinNode<T> *x, VST &visit) {
    std::stack<BinNodePosi(T)> S;
    while (true) {
        if (x) {
            S.push(x);
            x = x->lc;
        } else if (!S.empty()) {
            x = S.pop();
            visit(x->data);
            x = x->rc;
        } else {
            break;      // 遍历完成
        }
    }
}

/*
 * travIn_I3
 *中序遍历 迭代版 #3
 * 不需要使用栈辅助存储完成自底向上，通过 succ 获得直接后继的方法，自底向上查找后继
 * 原理：每当抵达一个节点，借助backtrack标志即可判断此前是否做过自下而上的回溯，若不是，则按照中序遍历策略优先遍历左子树。
 *          反之，若刚刚发生回溯，意味着当前节点的左子树已经遍历完毕（等效左子树为空），则可访问当前节点，再深入其右子树继续遍历。
 */
template<typename T>
template<typename VST>
void BinNode<T>::travIn_I3(BinNode<T> *x, VST &visit) {
    bool backtrack = false;     // 前一步是否刚从右子树回溯——省去栈，仅用 O(1) 的空间
    while (true) {
        if (!backtrack && HasLChild(*x)) {      // 若有左子树且不是刚刚回溯
            x = x->lc;      // 则深入遍历左子树
        } else {        // 无左子树 或 刚刚回溯（由于是回溯，所以左子树已经遍历过，相当于无左子树）
            visit(x->data);     // 访问当前节点
            if (HasRChild(*x)) {        // 如果有右子树
                x = x->rc;      // 进入右子树遍历
                backtrack = false;      // 开启新的子树遍历，关闭回溯标志
            } else {
                if (!(x = x->succ())) break;        // 没有后继 退出 若有后继 则回溯到后继遍历其右子树/回溯到下一个后继
                backtrack = true;       // 没有右子树，且存在后继，则后继一定为祖先，所以打开回溯标志
            }
        }
    }
}

/*
 * gotoHLVFL
 * 在以S栈顶节点为根的子树中 找到最高左侧可见叶节点
 */
template<typename T>
void BinNode<T>::gotoHLVFL(std::stack<BinNode<T> *> &S) {
    while (BinNodePosi(T) x = S.top()) {
        if (HasLChild(*x)) {
            if (HasRChild(*x)) {
                S.push(x->rc);      // 若有右孩子 优先入栈
                S.push(x->lc);      // 然后才转到左孩子
            }
        } else {
            S.push(x->rc);
        }
    }
    S.pop();        // 返回之前 弹出栈顶的空节点
}

template<typename T>
template<typename VST>
void BinNode<T>::travPost_I(BinNode<T> *x, VST &visit) {
    std::stack<BinNodePosi(T)> S;
    if (x) {
        S.push(x);
    }
    while (!S.empty()) {
        if (S.top() != x->parent) {
            gotoHLVFL(S);
        }
        x = S.pop();
        visit(x->data);
    }
}


#endif //DATASTRUCTURES_BINNODE_H
