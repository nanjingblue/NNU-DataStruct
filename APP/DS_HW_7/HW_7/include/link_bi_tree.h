//
// Created by 20190408ZSH on 2021/11/02
// 链式二叉树的各种实现
//

#ifndef HW_7_LINK_BI_TREE_H
#define HW_7_LINK_BI_TREE_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <ctime>
#include <cmath>
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
    BiNode<T> * createByPost(vector<T> &post, int &i);        // 与由后序序列构造二叉树有关
    BiNode<T> * createByPreMid(vector<T> &pre, vector<T> &mid, int ipre, int imid, int n);  // 与由先序和中序序列构造二叉树有关
    BiNode<T> * createByMidPost(vector<T> &mid, vector<T> &post, int imid, int ipost, int n);  // 与由中序和后序序列构造二叉树有关
    BiNode<T> * copy(BiNode<T> *p);     // 与拷贝构造二叉树有关
    void free(BiNode<T> *p);        // 与析构函数有关
    void preOrder(BiNode<T> *p);    // 与先序遍历有关
    void inOrder(BiNode<T> *p);     // 与中序遍历有关
    void postOrder(BiNode<T> *p);       // 与后序遍历有关
    int count(BiNode<T> *p);        // 与计算二叉树结点数有关
    int hight(BiNode<T> *p);        // 与计算二叉树高度有关
    BiNode<T> * search(BiNode<T> *p, T e);   // 关于根据值 e 查找结点
    BiNode<T> * searchParent(BiNode<T> *p, BiNode<T> *child);   // 关于查找指定结点的父结点
    void swapChild(BiNode<T> *p);        // 与交换每个节点的左右孩子相关
    void pathToLeaf(BiNode<T> *p, string path);      // 与输出根节点到每个叶节点的路径有关
    int leafCount(BiNode<T> *p);       // 与统计 叶子节点数 相关
    int singleBranchCount(BiNode<T> *p);        // 与统计 单分支节点数目有关
    int doubleBranchCount(BiNode<T> *p);        // 与统计 双分支节点数目有关 方法一
    void doubleBranchCount(BiNode<T> *p, int &cnt);     // 与统计双分子节点数目有关 方法二
    int balanceFactor(BiNode<T> *p);        // 与统计 各节点平衡因子 相关
    void leafCountOfLevel(BiNode<T> *p, int k, int level, int &cnt);        // 与统计 第 k 层叶子节点个数有关
    int leafCountOfLevel_l2(int k);     // 与统计 第 k 层叶子节点个数有关 版本2
    BiNode<T> * lowestCommonAncestor(BiNode<T> *p, BiNode<T> *x, BiNode<T> *y);     // 与最近公共祖先有关
    void allAncestorOfX(BiNode<T> *p, T x, string path, string &res); // 与获取 x 节点的所有祖先有关
    void getLeafTable(BiNode<T> *p, BiNode<T> *&head, BiNode<T> *&rear);        // 与叶节点链表有关
    int width(BiNode<T> *p);        // 与获取二叉树的宽度有关
public:
    BiTree();
    explicit BiTree(vector<T> &pre);     // 由先序序列构造二叉树
    BiTree(vector<T> &post, string type);   // 由后序序列构造二叉树
    BiTree(vector<T> &pre, vector<T> &mid);     // 由先序、中序序列构造二叉树
    BiTree(vector<T> &mid, vector<T> &post, const string& type);    // 由中序、后序序列构造二叉树
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
    void swapChild();    // 交换每个节点的左右孩子
    void pathToLeaf();      // 输出根节点到每个叶节点的路径
    int leafCount();        // 获取叶子节点数目
    int singleBranchCount();        // 获取单分支节点数目
    int doubleBranchCount();        // 获取双分子节点数目
    void balanceFactor();        //  输出各节点的平衡因子
    int leafCountOfLevel(int k);        // 获取 第 k 层 的叶子数目
    int leafCountOfLevel_2(int k);     // 统计 第 k 层叶子节点个数 版本2
    BiNode<T> * lowestCommonAncestor(BiNode<T> * x, BiNode<T> * y);     // 获取最近公共祖先
    string allAncestorOfX(T x);       // 输出 x 节点的所有祖先
    bool isCompleteBiTree();        //判断是否为完全二叉树
    bool isCompleteBiTree_2();      // 判断是否为完全二叉树 版本二
    BiNode<T> *getLeafTable();      //  从左到右的叶子链表
    int width();        // 获取二叉树的宽度
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
    if(root == nullptr)
        return;
    queue<BiNode<T> *> Q;
    Q.push(root);
    while (!Q.empty()) {
        BiNode<T> *p = Q.front();
        Q.pop();
        cout << p->data;
        if(p->leftChild != nullptr)
            Q.push(p->leftChild);
        if(p->rightChild != nullptr)
            Q.push(p->rightChild);
    }
}

template<class T>
BiNode<T> *BiTree<T>::createByPre(vector<T> &pre, int &i) {
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
BiNode<T> *BiTree<T>::createByPost(vector<T> &post, int &i) {
    T e = post[i];       // 提取当前数据
    i--;
    if(e == '*')
        return NULL;
    auto *p = new BiNode<T>;   // 创建新结点
    p->data = e;
    p->rightChild = createByPost(post, i);     // 创建右子树
    p->leftChild = createByPost(post,i);     // 创建左子树
    return p;
}


template<class T>
BiTree<T>::BiTree() {
    // 空树
    root = nullptr;
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
BiTree<T>::BiTree(vector<T> &post, string type) {
    int n = post.size() - 2;
    root = createByPost(post, n);
}

template<class T>
BiNode<T> *BiTree<T>::createByPreMid(vector<T> &pre, vector<T> &mid, int ipre, int imid, int n) {
    if(n == 0)
        return nullptr;
    auto *p = new BiNode<T>;
    p -> data = pre[ipre];
    int i;
    for (i = 0; i < n; ++i) {       // 在中序序列中定位根节点
        if(pre[ipre] == mid[imid + i])
            break;
    }
    p->leftChild = createByPreMid(pre, mid, ipre + 1, imid, i);
    p->rightChild = createByPreMid(pre, mid, ipre + i + 1, imid + i + 1, n - i - 1);
    return p;
}

template<class T>
BiNode<T> *BiTree<T>::createByMidPost(vector<T> &mid, vector<T> &post, int imid, int ipost, int n) {
    if (0 == n) return nullptr;
    auto *p = new BiNode<T>;
    p->data = post[ipost];   // 后序序列的根节点在最后一位
    int i;
    for (i = 0; i < n; ++i) {   // // 在中序序列中定位根节点
        if (post[ipost] == mid[imid + i]) break;
    }
    p->leftChild = createByMidPost(mid, post, imid, ipost - n + i, i);
    p->rightChild = createByMidPost(mid, post, imid + i + 1, ipost - 1, n - i - 1);
    return p;
}

template<class T>
BiTree<T>::BiTree(vector<T> &mid, vector<T> &post, const string& type) {
    int n = mid.size() - 1;
    root = createByMidPost(mid, post, 0, n - 1, n);
}

template<class T>
BiTree<T>::BiTree(vector<T> &pre, vector<T> &mid) {
    int n = pre.size() - 1;
    root = createByPreMid(pre, mid, 0,0, n);
}

template<class T>
BiTree<T>::BiTree(BiTree<T> &tree) {
    root = copy(tree.root);
}

template<class T>
BiNode<T> *BiTree<T>::copy(BiNode<T> *p) {
    if(p == nullptr)
        return nullptr;
    auto * newp = new BiNode<T>;
    newp->data = p->data;
    newp->leftChild = copy(p->leftChild);
    newp->rightChild = copy(p->rightChild);
    return newp;
}

template<class T>
void BiTree<T>::free(BiNode<T> *p) {
    if(p == nullptr)
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
    if(p == nullptr)
        return 0;
    int left = count(p->leftChild);     // 左子树的节点数
    int right = count(p->rightChild);       // 右子树的节点数
    return 1 + left + right;
}

template<class T>
int BiTree<T>::count() {
    return count(root);
}

template<class T>
int BiTree<T>::hight(BiNode<T> *p) {
    if(p == nullptr)
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

template<class T>
void BiTree<T>::swapChild(BiNode<T> *p) {
    if (p == nullptr) {
        return;
    }
    // 如果当前节点的左孩子和右孩子有一个存在 就需要进行交换
    if (p->leftChild || p->rightChild) {
        BiNode<T> * temp;       // 利用第三变量 来完成交换
        temp = p->leftChild;
        p->leftChild = p->rightChild;
        p->rightChild = temp;
    }
    swapChild(p->leftChild);    // 当前节点的左右孩子交换完毕 进入左子树 继续交换
    swapChild(p->rightChild);   // 进入左子树 继续交换 进入右孩子继续交换
}

template<class T>
void BiTree<T>::swapChild() {
    swapChild(root);
}

/*
 *  pathToLeaf 输出根节点到所有叶节点的路径
 *  DFS（深度优先搜索）的思路
 *  这里并没有对路径进行保存 只使用了一个 string类型的 path变量，通过回溯来保持 path 的更新
 *  边搜索边输出 遇到叶节点就输出
 */
template<class T>
void BiTree<T>::pathToLeaf(BiNode<T> *p, string path) {
    if (p == nullptr) return;
    if (p->leftChild == nullptr && p->rightChild == nullptr) {  // 是叶节点  输出路径 并返回
        cout << path << endl;
        return;
    }
    path += " -> ";     // 说明当前节点至少有一个孩子  "->" 指向下一个节点
    // 因为节点可能只有一个孩子 所以要先判断某个孩子存不存在
    if (p->leftChild) {     // 如果左孩子存在 进入左子树
        path += p->leftChild->data;
        pathToLeaf(p->leftChild, path);
        path.pop_back();        // 回溯  恢复到没有走这条路径的情况
    }
    if (p->rightChild) {    // 如果右孩子存在 进入右子树
        path += p->rightChild->data;
        pathToLeaf(p->rightChild, path);
        path.pop_back();     // 回溯
    }
}

template<class T>
void BiTree<T>::pathToLeaf() {
    string path;
    path += root->data;
    pathToLeaf(root, path);
}

/*
 *  leafCount 获取叶子节点个数递归版
 *  对于一颗树的根节点，叶子数目 = 左子树叶子数 + 右子树叶子数目
 *  如果是叶子就返回 1 不是叶子就返回 0 + 子树的叶子数
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
 * singleBranchCount 获取单分支节点数目
 * 原理同 获取叶子节点数目 只是条件变成 左右孩子只有一个存在才加 1
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
 *  doubleBranchCount 获取双分支节点数目
 *  原理同 求叶子节点数目 只是条件变成 左右孩子都存在才加1
 */
template<class T>
int BiTree<T>::doubleBranchCount(BiNode<T> *p) {
    if (p == nullptr) {
        return 0;
    }
    int left = doubleBranchCount(p->leftChild);
    int right = doubleBranchCount(p->rightChild);
    return left + right + ( (p->leftChild && p->rightChild) ? 1 : 0);
}

template<class T>
int BiTree<T>::doubleBranchCount() {
    srand(time(nullptr));
    int a = rand() % 10;
    if (a < 5) {
        return doubleBranchCount(root);
    }
    int count = 0;
    doubleBranchCount(root, count);
    return count;
}

template<class T>
void BiTree<T>::doubleBranchCount(BiNode<T> *p, int &cnt) {
    if (p) {
        if (p->leftChild && p->rightChild) {
            cnt++;
        }
        doubleBranchCount(p->leftChild, cnt);
        doubleBranchCount(p->rightChild, cnt);
    }
}

template<class T>
int BiTree<T>::balanceFactor(BiNode<T> *p) {
    if (p == nullptr) {
        return 0;
    }
    int left = balanceFactor(p->leftChild);
    int right = balanceFactor(p->rightChild);
    cout << p->data << "：" << abs(left - right) << endl;
    return max(left, right) + 1;
}

template<class T>
void BiTree<T>::balanceFactor() {
    balanceFactor(root);
}

/*
 * leafCountOfLevel 获取第 k 层叶子节点个数 方法一 递归版
 * 与获取双分支节点个数方法二 类似
 * 通过传递参数引用的方式，记录当前的层次与数目
 */
template<class T>
void BiTree<T>::leafCountOfLevel(BiNode<T> *p, int k, int level, int &cnt) {
    if (p == nullptr) {
        return;
    }
    if(level == k) {
        if (!p->leftChild && !p->rightChild)
            cnt++;
        return; // 已经到达第 k 层了 没有必要再深入下去
    }
    leafCountOfLevel(p->leftChild, k, level + 1, cnt);
    leafCountOfLevel(p->rightChild, k, level + 1, cnt);
}

template<class T>
int BiTree<T>::leafCountOfLevel(int k) {
    int cnt = 0;
    leafCountOfLevel(root, k, 1, cnt);
    return cnt;
}

template<class T>
BiNode<T> *BiTree<T>::lowestCommonAncestor(BiNode<T> *p, BiNode<T> *x, BiNode<T> *y) {
    if (p == nullptr) {
        return nullptr;
    }
    if (p == x || p == y) {
        return p;
    }
    BiNode<T> *left = lowestCommonAncestor(p->leftChild, x, y);     // 在左子树中查找
    BiNode<T> *right = lowestCommonAncestor(p->rightChild, x, y);  // 在右子树中查找
    if(left != nullptr && right != nullptr){
        return p;    // x, y 节点 分别在两个子树中 返回当前的根节点
    }
    if(left == nullptr && right == nullptr){
        return nullptr; // x, y 均不在两个子树中 返回 null
    }
    return left == nullptr ? right : left;  // 在一边有一边没有 到有的一边
}

template<class T>
BiNode<T> *BiTree<T>::lowestCommonAncestor(BiNode<T> *x, BiNode<T> *y) {
    return lowestCommonAncestor(root, x, y);
}

/*
 * leafCountOfLevel_l2 有点问题 留个坑
 * 利用层次遍历 获取第 k 层叶子节点数目
 * 添加判断条件 到达第 k 层后就不在继续遍历 k+1 层
 */
template<class T>
int BiTree<T>::leafCountOfLevel_l2(int k) {
    int level = 1, cnt = 0;
    if(root == nullptr)
        return 0;
    queue<BiNode<T> *> Q;
    Q.push(root);
    while (!Q.empty()) {

        BiNode<T> *p = Q.front();
        Q.pop();
        if (level == k) {
            if (!p->leftChild && !p->rightChild)    // 到达第 k 层 且为叶子节点
                cnt++;
            continue;   // 到达第 k 层后 没有必要再深入下去，保持第 k 层直到全部出队
        }
        if(p->leftChild != nullptr)
            Q.push(p->leftChild);
        if(p->rightChild != nullptr)
            Q.push(p->rightChild);
        level++;
    }
    return cnt;     // 返回结果
}

template <typename T>
int BiTree<T>::leafCountOfLevel_2(int k) {
    return leafCountOfLevel_l2( k);
}

template<class T>
void BiTree<T>::allAncestorOfX(BiNode<T> *p, T x, string path, string &res) {
    if (p == nullptr) return;
    if (p->data == x) {
        path.pop_back();    // 定义自己不是自己的祖先
        res = path;     // 把结果赋给引用传递出去
        return; // 无需深入
    }
    path += " ";
    if (p->leftChild) {     // 左子树存在进入左子树
        path += p->leftChild->data;
        allAncestorOfX(p->leftChild, x, path, res);
        path.pop_back();    // 回溯
    }
    if (p->rightChild) {    // 右子树存在进入右子树
        path += p->rightChild->data;
        allAncestorOfX(p->rightChild, x, path, res);
        path.pop_back();    // 回溯
    }
}

template<class T>
string BiTree<T>::allAncestorOfX(T x) {
    string res, path;
    if (root) {
        path += root->data;
    } else {
        return "";
    }
    allAncestorOfX(root, x, path, res);
    return res;
}

/*
 * isCompleteBiTree_2 判断是否为完全二叉树 版本1
 * 方法：层次遍历
 * 思路：完全二叉树 倒数第二层往上一定都是满二叉树 对于最后一层  若一节点存在 则其层次遍历上的前驱一定存在
 * 也就是说 若当前节点不存在 往后再出现节点存在 就不可能是完全二叉树
 */
template<class T>
bool BiTree<T>::isCompleteBiTree() {
    if(root == nullptr) return true;
    bool leaf = false;
    queue <BiNode<T> *> q;
    q.push(root);
    while (!q.empty()) {
        BiNode<T> *t = q.front();
        q.pop();
        if((leaf && (t->leftChild != nullptr || t->rightChild != nullptr )) || (t->leftChild == nullptr && t->rightChild != nullptr) )
            return false ;
        if(t->leftChild != nullptr)   //左孩子不为空，加入到队列中去
            q.push(t->leftChild);
        if(t->rightChild != nullptr)  //右孩子不为空，加入到队列中去
            q.push(t->rightChild);
        if((t->leftChild != nullptr && t->rightChild == nullptr ) || (t->leftChild == nullptr && t->rightChild == nullptr) )
            leaf = true;
    }
    return true;
}

/*
 * isCompleteBiTree_2 判断是否为完全二叉树 版本2
 * 思路：完全二叉树 倒数第二层往上一定都是满二叉树 对于最后一层  若一节点存在 则其层次遍历上的前驱一定存在
 * 也就是说 若当前节点不存在 往后再出现节点存在 就不可能是完全二叉树
 */
template<class T>
bool BiTree<T>::isCompleteBiTree_2() {
    if (root == nullptr) return true;       // 空树也是完全二叉树
    queue<BiNode<T> *> queue;
    bool flag = false;  // 状态变量 记录是否遇到为 nullptr 的节点
    queue.push(root);
    while (!queue.empty()) {
        BiNode<T> * p = queue.front();
        if (p != nullptr) {
            if (flag) {
                return false;
            }
            // 无论有没有左右孩子都入队 为判断状态做准备
            queue.push(p->leftChild);
            queue.push(p->rightChild);
        } else {
            flag = true;
        }
        queue.pop();
    }
    return true;
}

/*
 *getLeafTable 获得一个单链表 将所有叶子节点利用右孩子指针从左到右链接起来
 * 方法：深度优先搜索左子树实现叶节点的从左到有顺序
 * 参数说明：    head：叶子链表的头指针       rear：始终指向叶子链表的尾部
 * 为什么 head 和 rear 形参引用传递：因为涉及到指针指向的修改
 */
template<typename T>
void BiTree<T>::getLeafTable(BiNode<T> *p, BiNode<T> *&head, BiNode<T> *&rear) {
    if (p == nullptr) return;
    if (!p->leftChild && !p->rightChild) {  // 如果是叶节点
        if (rear) { // 叶子链表不为空
            rear->rightChild = p;
            rear = p;
            rear->rightChild = nullptr;
        } else {    // 叶子链表为空 定义头结点
            head = rear = p;
        }
    }
    getLeafTable(p->leftChild, head, rear); // 从左到右 左孩子优先
    getLeafTable(p->rightChild, head, rear);
}

template<typename T>
BiNode<T> * BiTree<T>::getLeafTable() {
    BiNode<T> * head = nullptr, * temp = nullptr;
    getLeafTable(root, head, temp);
    return head;
}

template<class T>
int BiTree<T>::width(BiNode<T> *p) {
    if (p == nullptr) return 0;
    queue<BiNode<T> *> queue;
    queue.push(p);
    int width = 1;
    int len;    // 记录每一层的个数
    while (!queue.empty()) {
        len = queue.size();
        while (len) {
            BiNode<T> * t = queue.front();
            queue.pop();
            // 下一层入队
            if (t->leftChild) queue.push(t->leftChild);
            if (t->rightChild) queue.push(t->rightChild);
            len--;
        }
        width = max(width, (int)queue.size());
    }
    return width;
}

template<class T>
int BiTree<T>::width() {
    return width(root);
}

#endif //HW_7_LINK_BI_TREE_H