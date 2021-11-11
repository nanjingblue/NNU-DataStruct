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
    GListNodeType type;     // �������
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
    GListNode<T> * DoCreate(string s, int &i);      // �������캯���й�
    GListNode<T> * Copy(GListNode<T> *p);       // �뿽�����캯���й�
    void Traverse(GListNode<T> *p);     // ����������� Traverse() �����й�
    void Free(GListNode<T> *p);     // �����������й�
    int Depth(GListNode<T> *p);     // ���������� Depth() �����й�
    void Replace(GListNode<T> *p, T x1, T x2); // ������ĳԭ��ֵ�滻�й�
    GListNode<T> * Delete(GListNode<T> *p, T x);  // ��ɾ��ԭ�ӽڵ��й�
public:
    GList();
    explicit GList(string s);        // �����ַ��� s ��������
    GList(GList<T> &gl);        // �������캯��
    ~GList();
    void Traverse();        // ����
    int Length();
    int Depth();
    void Replace(T x1, T x2);
    void Delete(T x);
};

template<class T>
GList<T>::GList() {
    // ��ʼ���չ����
    head = new GListNode<T>;
    head->type = LIST;
    head->sublist = head->next = NULL;
}

template<class T>
GListNode<T> *GList<T>::DoCreate(string s, int &i) {
    // �����ַ��� s �е�Ԫ�����й�������
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
    p = new GListNode<T>;       // ����ԭ�ӽڵ�
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
    // �����ı����㷨
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
    // ���������ĳ��ԭ��ֵȫ���滻Ϊָ��ֵ
    Replace(head, x1, x2);
}

template<class T>
void GList<T>::Delete(T x) {
    // ɾ�������������ֵΪָ��ֵ��ԭ�ӽڵ�
    head = Delete(head, x);
}


#endif //DATASTRUCTURES_GLIST_H
