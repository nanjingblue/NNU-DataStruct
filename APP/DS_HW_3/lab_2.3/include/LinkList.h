//
// Created by cherry on 2021/7/30.
//

#ifndef DATASTRUCTURES_LINKLIST_H
#define DATASTRUCTURES_LINKLIST_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
class LinkList;

template<class T1, class T2>
void Merge(LinkList<T1> &L1, LinkList<T2> &L2);

template<class T>
struct Node {
    T data;
    Node<T> * next;
};

template<class T>
class LinkList {
    Node<T> *head;
public:
    LinkList();
    LinkList(T a[], int n);
    LinkList(const LinkList<T>& A);
    LinkList<T>& operator=(const LinkList<T>& A);
    ~LinkList();
    int listLength();
    T get(int pos);
    int locate(T item);
    void printLinkList();
    void insert(int i, T item);       // 插入到第 i 个位置上 也就是索引 i-1
    T Delete(int i);                  // delete 第 i 个元素
    void invert();      // 逆置单链表
    void printByOrder();
    template<class Temp>
    friend void Merge(LinkList<Temp> &L1, LinkList<Temp> &L2);   // 合并有序单链表，声明为友元
    template<typename Temp>
    friend void genList(LinkList<Temp>& list1, LinkList<Temp>& list2, LinkList<Temp>& list3);
};

template<class T>
LinkList<T>::LinkList() {
    head = new Node<T>;
    head->next = nullptr;
}

template<class T>
LinkList<T>::LinkList(T *a, int n) {
    head = new Node<T>;     // 生成头结点
    Node<T> *rear = head;   // 指针 rear 用于指向当前单链表的最后一个节点
    for (int i = 0; i < n; ++i) {
        auto * temp = new Node<T>;
        temp->data = a[i];
        rear->next = temp;
        rear = temp;
    }
    rear->next = head;
}

template<class T>
LinkList<T>::~LinkList() {
    Node<T> * p =  head->next;
    Node<T> * q = p;
    while (p) {
        q = p;
        p = p->next;
        delete q;
    }

    this->head = nullptr;
}

template<class T>
int LinkList<T>::listLength() {
    int num = 0;
    Node<T> * p = head->next;
    while (p != head) {
        p = p->next;
        num++;
    }
    return num;
}

template<class T>
T LinkList<T>::get(int pos) {
    Node<T> * p = this->head->next;
    int j=1;
    while (p && j < pos) {
        p = p->next;
        j++;
    }
    if (!p || j > pos) {
        cerr << "查找位置非法" << endl;
        exit(1);
    } else {
        return p->data;
    }
}

template<class T>
int LinkList<T>::locate(T item) {
    Node<T> *p = head->next;
    int j=1;
    while (p != head  && p->data != item) {
        p = p->next;
        j++;
    }
    if (p)
        return j;
    else
        return 0;
}

template<class T>
void LinkList<T>::printLinkList() {
    Node<T> * p = head->next;
    cout << "linklist: [ ";
    while (p != head) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "]" << endl;
}

template<class T>
void LinkList<T>::insert(int i, T item) {
    // 后插法
    Node<T> * p = head;
    int j=0;
    while (p != head && j < i-1) {
        p = p->next;
        j++;
    }
    if (!p) {
        cerr << "Insert position unlawful";
        exit(1);
    } else {
        auto * s = new Node<T>;
        s->data = item;
        s->next = p->next;
        p->next = s;
    }
}

template<class T>
T LinkList<T>::Delete(int i) {
    Node<T> * p = this->head;
    int j=0;
    while (p != head && j < i-1) {      // 遍历到要删除节点的前驱
        p = p->next;
        j++;
    }
    if (!p || !p->next) {
        cerr << "Delete Position Unlawful" << endl;
        exit(1);
    } else {
        Node<T> * q = p->next;
        T x = q->data;
        p->next = q->next;
        delete q;
        return x;
    }
}

template<class T>
void LinkList<T>::invert() {
    Node<T> * p = head->next;
    Node<T> * q = p;
    head->next = nullptr;
    while (p != nullptr) {
        q = p;
        p = p->next;
        q->next = head->next;     // 插入表头
        head->next = q;
    }
}

// 有序链表合并
template<class T>
void Merge(LinkList<T> &L1, LinkList<T> &L2) {
    Node<T> *p1 = L1.head->next;
    Node<T> *p2 = L2.head->next;
    Node<T> *p3 = L1.head;
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->data < p2->data) {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        } else {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
    }
    if ( p1 != nullptr) {
        p3->next = p1;
    }
    if (p2 != nullptr) {
        p3->next = p2;
    }
    delete L2.head;
    L2.head = NULL;
}

// 生成奇偶链表
template<typename  T>
void genList(LinkList<T>& L1, LinkList<T>& L2, LinkList<T>& L3) {
    Node<T> * p1 = L1.head->next;
    while (p1 != nullptr) {
        (p1->data % 2 != 0) ? L2.insert(L2.listLength() + 1, p1->data) : L3.insert(L3.listLength() + 1, p1->data);
        p1 = p1->next;
    }
}

template<class T>
LinkList<T>::LinkList(const LinkList<T> &A) {
    head = new Node<T>;
    Node<T> * rear = head;
    Node<T> * t = A.head->next;
    while (t != nullptr) {
        auto * temp = new Node<T>;
        temp->data = t->data;
        rear->next = temp;
        rear = temp;
        t = t->next;
    }
    rear->next = nullptr;
}

template<class T>
LinkList<T> & LinkList<T>::operator=(const LinkList<T> & A) {
    if (this != &A) {
        Node<T> * p = head->next;
        Node<T> * q;
        while (p != nullptr) { q = p; p = p->next; delete q;}
    }
    Node<T> * rear = head;
    Node<T> * t = A.head->next;
    while (t != nullptr) {
        auto * temp = new Node<T>;
        temp->data = t->data;
        rear->next = temp;
        rear = temp;
        t = t->next;
    }
    rear->next = nullptr;
    return  *this;
}

template<class T>
void LinkList<T>::printByOrder() {
    vector<T> v;
    auto * p = head->next;
    while (p != nullptr) {
        v.push_back(p->data);
        p = p->next;
    }
    sort(v.begin(), v.end());
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        cout<< *it <<" ";
    }
    cout << endl;
}

#endif //DATASTRUCTURES_LINKLIST_H
