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
	//����ָ���ʶ���������й��������
	BiNode<T>* Copy(BiNode<T>* p); //��������
	void Free(BiNode<T>* p);       //�ͷź���
	void PreOrder(BiNode<T>* p);  //�������
	void InOrder(BiNode<T>* p);   //�������
	void PostOrder(BiNode<T>* p); //�������
	int Count(BiNode<T>* p);       //���������
	//==================
	int singleBranchCount(BiNode<T>* p);        // ��ͳ�� ����֧�ڵ���Ŀ�й�
	int doubleBranchCount(BiNode<T>* p);        // ��ͳ�� ˫��֧�ڵ���Ŀ�й�
	void swapChild(BiNode<T>* p);        // �뽻��ÿ���ڵ�����Һ������
	//======================================
	int Height(BiNode<T>* p);      //����������߶�
	int leafCount(BiNode<T>* p);       // ��ͳ�� Ҷ�ӽڵ��� ���
	BiNode<T>* Search(BiNode<T>* p, T e); //�����������㷨
	BiNode<T>* SearchParent(BiNode<T>* p, BiNode<T>* child); //���������ҽ�㸸���	
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
	int singleBranchCount();        // ��ȡ����֧�ڵ���Ŀ
	int doubleBranchCount();        // ��ȡ˫���ӽڵ���Ŀ
	void swapChild();    // ����ÿ���ڵ�����Һ���
	//==================================
	int Height();
	BiNode<T>* Search(T e);
	BiNode<T>* SearchParent(BiNode<T>* child);
};

//----------------����--------------------
//����
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
//����
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

//���
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
//����
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
//���캯��
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
//��������
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
//����
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
//�����
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
	// �����ǰ�ڵ�����Ӻ��Һ�����һ������ ����Ҫ���н���
	if (p->lchild || p->rchild) {
		BiNode<T>* temp;       // ���õ������� ����ɽ���
		temp = p->lchild;
		p->lchild = p->rchild;
		p->rchild = temp;
	}
	swapChild(p->lchild);    // ��ǰ�ڵ�����Һ��ӽ������ ���������� ��������
	swapChild(p->rchild);   // ���������� �������� �����Һ��Ӽ�������
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
//�߶�
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
//����
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
//���Ҹ����
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
//----------------����--------------------
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
		cerr << "����" << endl;
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
	cout << "----���п�ָ���ǰ�����н���������----" << endl;
	cout << "�����������" << endl;
	char list[100];
	cin >> list;
	vector<char>prelist;
	for (int i = 0; i < strlen(list); i++)
		prelist.push_back(list[i]);

	BiTree<char>tree(prelist);
	cout << "------------�˵�------------" << endl;
	cout << "||1.ǰ�����������       ||" << endl;
	cout << "||2.�������������       ||" << endl;
	cout << "||3.�������������       ||" << endl;
	cout << "||4.��α���������       ||" << endl;
	cout << "||5.Ѱ�Ҹ��ڵ�           ||" << endl;
	cout << "||6.��ȡ�������ĸ߶�     ||" << endl;
	cout << "||7.����֧�ڵ���Ϊ       ||" << endl;
	cout << "||8.˫��֧�ڵ���Ϊ       ||" << endl;
	cout << "||9.�������Һ��ӽ��     ||" << endl;
	cout << "||10.�˳�                ||" << endl;
	cout << "---------------------------" << endl;
	int choose = 1;
	while (choose != 10)
	{
		cout << "\n" << "������Ҫѡ��Ĺ���" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "ǰ��" << endl;
			tree.PreOrder();
			break;
		case 2:
			cout << "����" << endl;
			tree.InOrder();
			break;
		case 3:
			cout << "����" << endl;
			tree.PostOrder();
			break;
		case 4:
			cout << "���" << endl;
			tree.LevelOrder();
			break;
		case 5:
			cout << "����ҪѰ�ҵĽ��" << endl;
			char temp;
			cin >> temp;
			BiNode<char>* P;
			P = tree.SearchParent(tree.Search(temp));
			cout << temp << "�����Ϊ";
			cout << P->data << endl;
			break;
		case 6:
			cout << "�������߶�Ϊ" << tree.Height() << endl;
			break;
		case 7:
			cout << "����֧�����Ϊ" << tree.singleBranchCount() << endl;
			break;
		case 8:
			cout << "˫��֧�����Ϊ" << tree.doubleBranchCount() << endl;
			break;
		case 9:
			tree.swapChild();
            cout << "������";
            tree.PreOrder();
			break;
		case 10:
			cout << "quit successed(>-<)" << endl;
			break;
		}
	}
}