//
// Created by cherry on 2021/8/11.
//

#ifndef DATASTRUCTURES_LINKSTACK_H
#define DATASTRUCTURES_LINKSTACK_H

#include <iostream>
using namespace std;

/*
 * 栈的链式存储结构
 */

template<class T>
struct Node {
    T data;
    Node<T> * next;
};

template<class T>
class LinkStack {
    Node<T> * top;      // 栈顶指针
public:
    LinkStack();
    ~LinkStack();
    void Push(T x);
    T Pop();
    T Top();
    bool Empty();
};

template<class T>
LinkStack<T>::LinkStack() {
    top = NULL;
}

template<class T>
void LinkStack<T>::Push(T x) {
    auto * s = new Node<T>;
    s->data = x;
    s->next = top;
    top = s;
}

template<class T>
T LinkStack<T>::Pop() {
    if(top == NULL) {
        cerr << "下溢";
        exit(1);
    }
    T x = top->data;
    auto * p  =top;
    top = top->next;
    delete p;
    return x;
}

template<class T>
T LinkStack<T>::Top() {
    if(top == NULL) {
        cerr << "下溢";
        exit(1);
    }
    return top->data;
}

template<class T>
bool LinkStack<T>::Empty() {
    return top == NULL;
}

template<class T>
LinkStack<T>::~LinkStack() {
    auto * p = top;
    auto *q = p;
    while (p) {
        q = p;
        p = p->next;
        delete q;
    }
    top = NULL;
}


#endif //DATASTRUCTURES_LINKSTACK_H
