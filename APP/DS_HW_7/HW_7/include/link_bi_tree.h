//
// Created by 20190408ZSH on 2021/11/02
// ��ʽ�������ĸ���ʵ��
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
    BiNode<T> * createByPost(vector<T> &post, int &i);        // ���ɺ������й���������й�
    BiNode<T> * createByPreMid(vector<T> &pre, vector<T> &mid, int ipre, int imid, int n);  // ����������������й���������й�
    BiNode<T> * createByMidPost(vector<T> &mid, vector<T> &post, int imid, int ipost, int n);  // ��������ͺ������й���������й�
    BiNode<T> * copy(BiNode<T> *p);     // �뿽������������й�
    void free(BiNode<T> *p);        // �����������й�
    void preOrder(BiNode<T> *p);    // ����������й�
    void inOrder(BiNode<T> *p);     // ����������й�
    void postOrder(BiNode<T> *p);       // ���������й�
    int count(BiNode<T> *p);        // ����������������й�
    int hight(BiNode<T> *p);        // �����������߶��й�
    BiNode<T> * search(BiNode<T> *p, T e);   // ���ڸ���ֵ e ���ҽ��
    BiNode<T> * searchParent(BiNode<T> *p, BiNode<T> *child);   // ���ڲ���ָ�����ĸ����
    void swapChild(BiNode<T> *p);        // �뽻��ÿ���ڵ�����Һ������
    void pathToLeaf(BiNode<T> *p, string path);      // ��������ڵ㵽ÿ��Ҷ�ڵ��·���й�
    int leafCount(BiNode<T> *p);       // ��ͳ�� Ҷ�ӽڵ��� ���
    int singleBranchCount(BiNode<T> *p);        // ��ͳ�� ����֧�ڵ���Ŀ�й�
    int doubleBranchCount(BiNode<T> *p);        // ��ͳ�� ˫��֧�ڵ���Ŀ�й� ����һ
    void doubleBranchCount(BiNode<T> *p, int &cnt);     // ��ͳ��˫���ӽڵ���Ŀ�й� ������
    int balanceFactor(BiNode<T> *p);        // ��ͳ�� ���ڵ�ƽ������ ���
    void leafCountOfLevel(BiNode<T> *p, int k, int level, int &cnt);        // ��ͳ�� �� k ��Ҷ�ӽڵ�����й�
    int leafCountOfLevel_l2(int k);     // ��ͳ�� �� k ��Ҷ�ӽڵ�����й� �汾2
    BiNode<T> * lowestCommonAncestor(BiNode<T> *p, BiNode<T> *x, BiNode<T> *y);     // ��������������й�
    void allAncestorOfX(BiNode<T> *p, T x, string path, string &res); // ���ȡ x �ڵ�����������й�
    void getLeafTable(BiNode<T> *p, BiNode<T> *&head, BiNode<T> *&rear);        // ��Ҷ�ڵ������й�
    int width(BiNode<T> *p);        // ���ȡ�������Ŀ���й�
public:
    BiTree();
    explicit BiTree(vector<T> &pre);     // ���������й��������
    BiTree(vector<T> &post, string type);   // �ɺ������й��������
    BiTree(vector<T> &pre, vector<T> &mid);     // �������������й��������
    BiTree(vector<T> &mid, vector<T> &post, const string& type);    // �����򡢺������й��������
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
    void swapChild();    // ����ÿ���ڵ�����Һ���
    void pathToLeaf();      // ������ڵ㵽ÿ��Ҷ�ڵ��·��
    int leafCount();        // ��ȡҶ�ӽڵ���Ŀ
    int singleBranchCount();        // ��ȡ����֧�ڵ���Ŀ
    int doubleBranchCount();        // ��ȡ˫���ӽڵ���Ŀ
    void balanceFactor();        //  ������ڵ��ƽ������
    int leafCountOfLevel(int k);        // ��ȡ �� k �� ��Ҷ����Ŀ
    int leafCountOfLevel_2(int k);     // ͳ�� �� k ��Ҷ�ӽڵ���� �汾2
    BiNode<T> * lowestCommonAncestor(BiNode<T> * x, BiNode<T> * y);     // ��ȡ�����������
    string allAncestorOfX(T x);       // ��� x �ڵ����������
    bool isCompleteBiTree();        //�ж��Ƿ�Ϊ��ȫ������
    bool isCompleteBiTree_2();      // �ж��Ƿ�Ϊ��ȫ������ �汾��
    BiNode<T> *getLeafTable();      //  �����ҵ�Ҷ������
    int width();        // ��ȡ�������Ŀ��
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
BiNode<T> *BiTree<T>::createByPost(vector<T> &post, int &i) {
    T e = post[i];       // ��ȡ��ǰ����
    i--;
    if(e == '*')
        return NULL;
    auto *p = new BiNode<T>;   // �����½��
    p->data = e;
    p->rightChild = createByPost(post, i);     // ����������
    p->leftChild = createByPost(post,i);     // ����������
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
    for (i = 0; i < n; ++i) {       // �����������ж�λ���ڵ�
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
    p->data = post[ipost];   // �������еĸ��ڵ������һλ
    int i;
    for (i = 0; i < n; ++i) {   // // �����������ж�λ���ڵ�
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
void BiTree<T>::swapChild(BiNode<T> *p) {
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
    swapChild(p->leftChild);    // ��ǰ�ڵ�����Һ��ӽ������ ���������� ��������
    swapChild(p->rightChild);   // ���������� �������� �����Һ��Ӽ�������
}

template<class T>
void BiTree<T>::swapChild() {
    swapChild(root);
}

/*
 *  pathToLeaf ������ڵ㵽����Ҷ�ڵ��·��
 *  DFS�����������������˼·
 *  ���ﲢû�ж�·�����б��� ֻʹ����һ�� string���͵� path������ͨ������������ path �ĸ���
 *  ����������� ����Ҷ�ڵ�����
 */
template<class T>
void BiTree<T>::pathToLeaf(BiNode<T> *p, string path) {
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
    if (p->rightChild) {    // ����Һ��Ӵ��� ����������
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
    cout << p->data << "��" << abs(left - right) << endl;
    return max(left, right) + 1;
}

template<class T>
void BiTree<T>::balanceFactor() {
    balanceFactor(root);
}

/*
 * leafCountOfLevel ��ȡ�� k ��Ҷ�ӽڵ���� ����һ �ݹ��
 * ���ȡ˫��֧�ڵ���������� ����
 * ͨ�����ݲ������õķ�ʽ����¼��ǰ�Ĳ������Ŀ
 */
template<class T>
void BiTree<T>::leafCountOfLevel(BiNode<T> *p, int k, int level, int &cnt) {
    if (p == nullptr) {
        return;
    }
    if(level == k) {
        if (!p->leftChild && !p->rightChild)
            cnt++;
        return; // �Ѿ������ k ���� û�б�Ҫ��������ȥ
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
    BiNode<T> *left = lowestCommonAncestor(p->leftChild, x, y);     // ���������в���
    BiNode<T> *right = lowestCommonAncestor(p->rightChild, x, y);  // ���������в���
    if(left != nullptr && right != nullptr){
        return p;    // x, y �ڵ� �ֱ������������� ���ص�ǰ�ĸ��ڵ�
    }
    if(left == nullptr && right == nullptr){
        return nullptr; // x, y ���������������� ���� null
    }
    return left == nullptr ? right : left;  // ��һ����һ��û�� ���е�һ��
}

template<class T>
BiNode<T> *BiTree<T>::lowestCommonAncestor(BiNode<T> *x, BiNode<T> *y) {
    return lowestCommonAncestor(root, x, y);
}

/*
 * leafCountOfLevel_l2 �е����� ������
 * ���ò�α��� ��ȡ�� k ��Ҷ�ӽڵ���Ŀ
 * ����ж����� ����� k ���Ͳ��ڼ������� k+1 ��
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
            if (!p->leftChild && !p->rightChild)    // ����� k �� ��ΪҶ�ӽڵ�
                cnt++;
            continue;   // ����� k ��� û�б�Ҫ��������ȥ�����ֵ� k ��ֱ��ȫ������
        }
        if(p->leftChild != nullptr)
            Q.push(p->leftChild);
        if(p->rightChild != nullptr)
            Q.push(p->rightChild);
        level++;
    }
    return cnt;     // ���ؽ��
}

template <typename T>
int BiTree<T>::leafCountOfLevel_2(int k) {
    return leafCountOfLevel_l2( k);
}

template<class T>
void BiTree<T>::allAncestorOfX(BiNode<T> *p, T x, string path, string &res) {
    if (p == nullptr) return;
    if (p->data == x) {
        path.pop_back();    // �����Լ������Լ�������
        res = path;     // �ѽ���������ô��ݳ�ȥ
        return; // ��������
    }
    path += " ";
    if (p->leftChild) {     // ���������ڽ���������
        path += p->leftChild->data;
        allAncestorOfX(p->leftChild, x, path, res);
        path.pop_back();    // ����
    }
    if (p->rightChild) {    // ���������ڽ���������
        path += p->rightChild->data;
        allAncestorOfX(p->rightChild, x, path, res);
        path.pop_back();    // ����
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
 * isCompleteBiTree_2 �ж��Ƿ�Ϊ��ȫ������ �汾1
 * ��������α���
 * ˼·����ȫ������ �����ڶ�������һ�������������� �������һ��  ��һ�ڵ���� �����α����ϵ�ǰ��һ������
 * Ҳ����˵ ����ǰ�ڵ㲻���� �����ٳ��ֽڵ���� �Ͳ���������ȫ������
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
        if(t->leftChild != nullptr)   //���Ӳ�Ϊ�գ����뵽������ȥ
            q.push(t->leftChild);
        if(t->rightChild != nullptr)  //�Һ��Ӳ�Ϊ�գ����뵽������ȥ
            q.push(t->rightChild);
        if((t->leftChild != nullptr && t->rightChild == nullptr ) || (t->leftChild == nullptr && t->rightChild == nullptr) )
            leaf = true;
    }
    return true;
}

/*
 * isCompleteBiTree_2 �ж��Ƿ�Ϊ��ȫ������ �汾2
 * ˼·����ȫ������ �����ڶ�������һ�������������� �������һ��  ��һ�ڵ���� �����α����ϵ�ǰ��һ������
 * Ҳ����˵ ����ǰ�ڵ㲻���� �����ٳ��ֽڵ���� �Ͳ���������ȫ������
 */
template<class T>
bool BiTree<T>::isCompleteBiTree_2() {
    if (root == nullptr) return true;       // ����Ҳ����ȫ������
    queue<BiNode<T> *> queue;
    bool flag = false;  // ״̬���� ��¼�Ƿ�����Ϊ nullptr �Ľڵ�
    queue.push(root);
    while (!queue.empty()) {
        BiNode<T> * p = queue.front();
        if (p != nullptr) {
            if (flag) {
                return false;
            }
            // ������û�����Һ��Ӷ���� Ϊ�ж�״̬��׼��
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
 *getLeafTable ���һ�������� ������Ҷ�ӽڵ������Һ���ָ���������������
 * �����������������������ʵ��Ҷ�ڵ�Ĵ�����˳��
 * ����˵����    head��Ҷ�������ͷָ��       rear��ʼ��ָ��Ҷ�������β��
 * Ϊʲô head �� rear �β����ô��ݣ���Ϊ�漰��ָ��ָ����޸�
 */
template<typename T>
void BiTree<T>::getLeafTable(BiNode<T> *p, BiNode<T> *&head, BiNode<T> *&rear) {
    if (p == nullptr) return;
    if (!p->leftChild && !p->rightChild) {  // �����Ҷ�ڵ�
        if (rear) { // Ҷ������Ϊ��
            rear->rightChild = p;
            rear = p;
            rear->rightChild = nullptr;
        } else {    // Ҷ������Ϊ�� ����ͷ���
            head = rear = p;
        }
    }
    getLeafTable(p->leftChild, head, rear); // ������ ��������
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
    int len;    // ��¼ÿһ��ĸ���
    while (!queue.empty()) {
        len = queue.size();
        while (len) {
            BiNode<T> * t = queue.front();
            queue.pop();
            // ��һ�����
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