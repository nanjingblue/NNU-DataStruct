//
// Created by cherry on 2021/8/21.
//

#ifndef DATASTRUCTURES_GLIST_H
#define DATASTRUCTURES_GLIST_H

#include <iostream>
#include <string>
using namespace std;

enum GListNodeType{ATOM, LIST};
template <class T>
struct GListNode {
    GListNodeType type;     // 结点类型
    union {
        T data;
        GListNode * sublist;
    };
    GListNode<T> * next;
};

template<class T>
class GList {
private:
    GListNode<T> * head;
    GListNode<T> * DoCreate(string s, int &i);      // 与广义表构造函数有关
    GListNode<T> * Copy(GListNode<T> *p);       // 与拷贝构造函数有关
    void Traverse(GListNode<T> *p);     // 与遍历广义表的 Traverse() 函数有关
    void Free(GListNode<T> *p);     // 与析构函数有关
    int Depth(GListNode<T> *p);     // 与计算广义表的 Depth() 函数有关
    void Replace(GListNode<T> *p, T x1, T x2); // 与广义表某原子值替换有关
    GListNode<T> * Delete(GListNode<T> *p, T x);  // 与删除原子节点有关
public:
    GList();
    explicit GList(string s);        // 根据字符串 s 广义表对象
    GList(GList<T> &gl);        // 拷贝构造函数
    ~GList();
    void Traverse();        // 遍历
    int Length();
    int Depth();
    void Replace(T x1, T x2);
    void Delete(T x);
};

template<class T>
GList<T>::GList() {
    // 初始化空广义表
    head = new GListNode<T>;
    head->type = LIST;
    head->sublist = head->next = NULL;
}

template<class T>
GListNode<T> *GList<T>::DoCreate(string s, int &i) {
    // 根据字符串 s 中的元素序列构造广义表
    GListNode<T> * p;
    while (s[i] == ' ' || s[i] == ',') ++i;
    char e = s[i];
    ++i;
    if(e == '(') {
        p = new GListNode<T>;
        p->type = LIST;
        p->sublist = DoCreate(s, i);
        p->next = DoCreate(s, i);
        return p;
    }
    if(e == ')' || e == '\0') return NULL;
    p = new GListNode<T>;       // 构造原子节点
    p->type = ATOM;
    p->data = e;
    p->next = DoCreate(s, i);
    return p;
}

template<class T>
GList<T>::GList(string s) {
    int i=0;
    head = DoCreate(s, i);
}

template<class T>
void GList<T>::Traverse(GListNode<T> *p) {
    // 广义表的遍历算法
    if(p == NULL)
        return;
    if(p->type == ATOM) {
        cout << p->data;
    } else {
        cout << "( ";
        Traverse(p->sublist);
        cout << " )";
    }
    if(p->next) {
        cout << ", ";
    }
    Traverse(p->next);
}

template<class T>
void GList<T>::Traverse() {
    Traverse(head);
    cout << endl;
}

template<class T>
GListNode<T> *GList<T>::Copy(GListNode<T> *p) {
    if(p == NULL)
        return NULL;
    auto * newp = new GListNode<T>;
    newp->type = p->type;
    if(p->type == LIST) {
        newp->sublist = Copy(p->sublist);
    } else {
        newp->data = p->data;
    }
    newp->next = Copy(p->next);
    return newp;
}

template<class T>
GList<T>::GList(GList<T> &gl) {
    head = Copy(gl.head);
}

template<class T>
int GList<T>::Length() {    GListNode<T> * p;
    int n = 0;
    p = head->sublist;
    while (p) {
        p = p->next;
        n++;
    }
    return n;
}

template<class T>
int GList<T>::Depth(GListNode<T> *p) {
    if(p->type == ATOM)
        return 0;
    int maxDepth = 0;
    GListNode<T> *q;
    q = p->sublist;
    while (q) {
        int depth = Depth(q);
        if(depth > maxDepth)
            maxDepth = depth;
        q = q->next;
    }
    return maxDepth + 1;
}

template<class T>
int GList<T>::Depth() {
    return Depth(head);
}

template<class T>
void GList<T>::Free(GListNode<T> *p) {
    if(p == NULL)
        return;
    if(p->type == LIST)
        Free(p->sublist);
    Free(p->next);
    delete p;
}

template<class T>
GList<T>::~GList() {
    Free(head);
}

template<class T>
void GList<T>::Replace(GListNode<T> *p, T x1, T x2) {
    if(p == NULL)
        return;
    if(p->type == ATOM) {
        if(p->data == x1) {
            p->data = x2;
        }
    } else {
        Replace(p->sublist, x1, x2);
    }
    if(p->next) {
        Replace(p->next, x1, x2);
    }
}


template<class T>
GListNode<T> * GList<T>::Delete(GListNode<T> *p, T x) {
    if(p == NULL)
        return NULL;
    GListNode<T> * q = Delete(p->next, x);
    if(p->type == ATOM) {
        if(p->data == x) {
            delete []p;
            return q;
        }
    }
    p->next = q;
    if(p->type == LIST) {
        p->sublist = Delete(p->sublist, x);
    }
    return p;
}

template<class T>
void GList<T>::Replace(T x1, T x2) {
    // 将广义表中某种原子值全部替换为指定值
    Replace(head, x1, x2);
}

template<class T>
void GList<T>::Delete(T x) {
    // 删除广义表中所有值为指定值得原子节点
    head = Delete(head, x);
}


#endif //DATASTRUCTURES_GLIST_H
