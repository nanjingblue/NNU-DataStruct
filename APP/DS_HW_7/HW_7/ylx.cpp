#include<iostream>
#include<string>
#include <ctime>
#include <cmath>
#include <queue>
#include<vector>
#include <cstring>
using namespace std;
//abd**e**cf***
//abdf**g**eh***ci**j**
template< class T>
struct BiNode
{
	T data;
	BiNode<T>* rchild;
	BiNode<T>* lchild;
};
template<class T>
struct Node
{
	T data;
	Node<T>* next;
};
template<class T>
class LinkQueue
{
	Node<T>* front, * rear;
public:
	LinkQueue();
	void EnQueue(T x);
	T DeQueue();
	~LinkQueue();
	bool Empty();
};
template<class T>
class BiTree
{
	BiNode<T>* root;
	BiNode<T>* CreateByPre(vector<T>& pre, int& i); 
	//带空指针标识的先序序列构造二叉树
	BiNode<T>* Copy(BiNode<T>* p); //拷贝函数
	void Free(BiNode<T>* p);       //释放函数
	void PreOrder(BiNode<T>* p);  //先序遍历
	void InOrder(BiNode<T>* p);   //中序遍历
	void PostOrder(BiNode<T>* p); //后序遍历
	int Count(BiNode<T>* p);       //计算结点个数
	//==================
	int singleBranchCount(BiNode<T>* p);        // 与统计 单分支节点数目有关
	int doubleBranchCount(BiNode<T>* p);        // 与统计 双分支节点数目有关
	void swapChild(BiNode<T>* p);        // 与交换每个节点的左右孩子相关
	//======================================
	int Height(BiNode<T>* p);      //计算二叉树高度
	int leafCount(BiNode<T>* p);       // 与统计 叶子节点数 相关
	BiNode<T>* Search(BiNode<T>* p, T e); //二叉树查找算法
	BiNode<T>* SearchParent(BiNode<T>* p, BiNode<T>* child); //二叉树查找结点父结点	
public:
	BiTree() { root = NULL; }
	BiTree(vector<T>& pre);
	BiTree(BiTree<T>& tree);
	~BiTree();
	void PreOrder();
	void InOrder();
	void PostOrder();
	void LevelOrder();
	int Count();
	//==================================
	int singleBranchCount();        // 获取单分支节点数目
	int doubleBranchCount();        // 获取双分子节点数目
	void swapChild();    // 交换每个节点的左右孩子
	//==================================
	int Height();
	BiNode<T>* Search(T e);
	BiNode<T>* SearchParent(BiNode<T>* child);
};

//----------------建树--------------------
//先序
template<class T>

void BiTree<T>::PreOrder()
{
	PreOrder(root);
}
template<class T>
void BiTree<T>::PreOrder(BiNode<T>* p)
{
	if (p == NULL) return;
	cout << p->data << "\t";
	PreOrder(p->lchild);
	PreOrder(p->rchild);
}
//中序
template<class T>
void BiTree<T>::InOrder()
{
	InOrder(root);
}
template<class T>
void BiTree<T>::InOrder(BiNode<T>* p)
{
	if (p == NULL) return;
	InOrder(p->lchild);
	cout << p->data << "\t";
	InOrder(p->rchild);
}

//层次
template<class T>
void BiTree<T>::LevelOrder()
{
	if (root == NULL)return;
	LinkQueue<BiNode<T>*>Q;
	Q.EnQueue(root);
	while (!Q.Empty())
	{
		BiNode<T>* p;
		p = Q.DeQueue();
		cout << p->data << "\t";
		if (p->lchild != NULL)
			Q.EnQueue(p->lchild);
		if (p->rchild != NULL)
			Q.EnQueue(p->rchild);
	}
}
//后序
template<class T>
void BiTree<T>::PostOrder()
{
	PostOrder(root);
}
template<class T>
void BiTree<T>::PostOrder(BiNode<T>* p)
{
	if (p == NULL) return;
	PostOrder(p->lchild);
	PostOrder(p->rchild);
	cout << p->data << "\t";
}
//构造函数
template<class T>
BiNode<T>* BiTree<T>::CreateByPre(vector<T>& pre, int& i)
{
	T e = pre[i];
	i++;
	if (e == '*')
		return NULL;
	BiNode<T>* p = new BiNode<T>;
	p->data = e;
	p->lchild = CreateByPre(pre, i);
	p->rchild = CreateByPre(pre, i);
	return p;
}

template<class T>
BiTree<T>::BiTree(vector<T>& pre)
{
	int i = 0;
	root = CreateByPre(pre, i);
}
//拷贝构造
template<class T>
BiNode<T>* BiTree<T>::Copy(BiNode<T>* p)
{
	if (p == NULL)return NULL;
	BiNode<T>* newp = new BiNode<T>;
	newp->data = p->data;
	newp->lchild = Copy(p->lchild);
	newp->rchild = Copy(p->rchild);
	return newp;
}
template<class T>
BiTree<T>::BiTree(BiTree<T>& tree)
{
	root = Copy(tree.root);
}
//析构
template<class T>
void BiTree<T>::Free(BiNode<T>* p)
{
	if (p == NULL) return;
	Free(p->lchild);
	Free(p->rchild);
	delete p;
}
template<class T>
BiTree<T>::~BiTree()
{
	Free(root);
}
//结点数
template<class T>
int BiTree<T>::Count(BiNode<T>* p)
{
	if (p == NULL)
		return 0;
	int left = Count(p->lchild);
	int right = Count(p->rchild);
	return 1 + left + right;
}
//============================
template<class T>
int BiTree<T>::singleBranchCount(BiNode<T>* p) {
	if (p == nullptr) {
		return 0;
	}
	int left = singleBranchCount(p->lchild);
	int right = singleBranchCount(p->rchild);
	return left + right + ((p->lchild == nullptr && p->rchild != nullptr) || (p->lchild != nullptr && p->rchild == nullptr) ? 1 : 0);
}

template<class T>
int BiTree<T>::singleBranchCount() {
	return singleBranchCount(root);
}
template<class T>
int BiTree<T>::doubleBranchCount(BiNode<T>* p) {
	if (p == nullptr) {
		return 0;
	}
	int left = doubleBranchCount(p->lchild);
	int right = doubleBranchCount(p->rchild);
	return left + right + ((p->lchild && p->rchild) ? 1 : 0);
}
template<class T>
int BiTree<T>::doubleBranchCount() {
    return doubleBranchCount(root);
}
template<class T>
void BiTree<T>::swapChild(BiNode<T>* p) {
	if (p == nullptr) {
		return;
	}
	// 如果当前节点的左孩子和右孩子有一个存在 就需要进行交换
	if (p->lchild || p->rchild) {
		BiNode<T>* temp;       // 利用第三变量 来完成交换
		temp = p->lchild;
		p->lchild = p->rchild;
		p->rchild = temp;
	}
	swapChild(p->lchild);    // 当前节点的左右孩子交换完毕 进入左子树 继续交换
	swapChild(p->rchild);   // 进入左子树 继续交换 进入右孩子继续交换
}

template<class T>
void BiTree<T>::swapChild() {
	swapChild(root);
}

//=================================
template<class T>
int BiTree<T>::Count()
{
	return Count(root);
}
//高度
template<class T>
int BiTree<T>::Height(BiNode<T>* p)
{
	if (p == NULL) return 0;
	int left, right;
	left = Height(p->lchild);
	right = Height(p->rchild);
	if (left > right)
		return left + 1;
	else
		return right + 1;
}
template<class T>
int BiTree<T>::Height()
{
	return Height(root);
}
//查找
template<class T>
BiNode<T>* BiTree<T>::Search(BiNode<T>* p, T e)
{
	if (p == NULL) return NULL;
	if (p->data == e)
		return p;
	BiNode<T>* q = Search(p->lchild, e);
	if (q != NULL) return q;
	return Search(p->rchild, e);
}
template<class T>
BiNode<T>* BiTree<T>::Search(T e)
{
	return Search(root, e);
}
//查找父结点
template<class T>
BiNode<T>* BiTree<T>::SearchParent(BiNode<T>* p, BiNode<T>* child)
{
	if (p == NULL || child == NULL)return NULL;
	if (p->lchild == child || p->rchild == child)
		return p;
	BiNode<T>* q = SearchParent(p->lchild, child);
	if (q != NULL)return q;
	return SearchParent(p->rchild, child);
}
template<class T>
BiNode<T>* BiTree<T>::SearchParent(BiNode<T>* child)
{
	return SearchParent(root, child);
}
//----------------队列--------------------
template<class T>
LinkQueue<T>::LinkQueue()
{
	Node<T>* s;
	s = new Node<T>;
	s->next = NULL;
	front = rear = s;
}
template<class T>
void LinkQueue<T>::EnQueue(T x)
{
	Node<T>* s;
	s = new Node<T>;
	s->data = x;
	s->next = NULL;
	rear->next = s;
	rear = s;
}
template<class T>
T LinkQueue<T>::DeQueue()
{
	if (rear == front)
		cerr << "下溢" << endl;
	Node<T>* p;
	T x;
	p = front->next;
	x = p->data;
	front->next = p->next;
	if (p->next == NULL)
		rear = front;
	delete p;
	return x;
}
template<class T>
LinkQueue<T>::~LinkQueue()
{
	Node<T>* p = front;
	Node<T>* q;
	while (p)
	{
		q = p;
		p = p->next;
		delete q;
	}
	front = NULL;
}
template<class T>
bool LinkQueue<T>::Empty()
{
	return rear == front;
}
int main()
{
	cout << "----带有空指针的前序序列建立二叉树----" << endl;
	cout << "请输入二叉树" << endl;
	char list[100];
	cin >> list;
	vector<char>prelist;
	for (int i = 0; i < strlen(list); i++)
		prelist.push_back(list[i]);

	BiTree<char>tree(prelist);
	cout << "------------菜单------------" << endl;
	cout << "||1.前序遍历二叉树       ||" << endl;
	cout << "||2.中序遍历二叉树       ||" << endl;
	cout << "||3.后序遍历二叉树       ||" << endl;
	cout << "||4.层次遍历二叉树       ||" << endl;
	cout << "||5.寻找父节点           ||" << endl;
	cout << "||6.求取二叉树的高度     ||" << endl;
	cout << "||7.单分支节点数为       ||" << endl;
	cout << "||8.双分支节点数为       ||" << endl;
	cout << "||9.交换左右孩子结点     ||" << endl;
	cout << "||10.退出                ||" << endl;
	cout << "---------------------------" << endl;
	int choose = 1;
	while (choose != 10)
	{
		cout << "\n" << "请输入要选择的功能" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "前序" << endl;
			tree.PreOrder();
			break;
		case 2:
			cout << "中序" << endl;
			tree.InOrder();
			break;
		case 3:
			cout << "后序" << endl;
			tree.PostOrder();
			break;
		case 4:
			cout << "层次" << endl;
			tree.LevelOrder();
			break;
		case 5:
			cout << "输入要寻找的结点" << endl;
			char temp;
			cin >> temp;
			BiNode<char>* P;
			P = tree.SearchParent(tree.Search(temp));
			cout << temp << "父结点为";
			cout << P->data << endl;
			break;
		case 6:
			cout << "二叉树高度为" << tree.Height() << endl;
			break;
		case 7:
			cout << "单分支结点数为" << tree.singleBranchCount() << endl;
			break;
		case 8:
			cout << "双分支结点数为" << tree.doubleBranchCount() << endl;
			break;
		case 9:
			tree.swapChild();
            cout << "交换后：";
            tree.PreOrder();
			break;
		case 10:
			cout << "quit successed(>-<)" << endl;
			break;
		}
	}
}