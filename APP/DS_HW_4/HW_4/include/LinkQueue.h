//
// Created by cherry on 2021/8/17.
//
#ifndef DATASTRUCTURES_LINKQUEUE_H
#define DATASTRUCTURES_LINKQUEUE_H
#include <iostream>
using namespace std;

template<class T>
struct Node {
    T data;
    Node<T> * next;
};

template<class T>
class LinkQueue {
    Node<T> *rear;
public:
    LinkQueue();
    ~LinkQueue();
    void push(T x);
    T pop();
    T Front();
    T back();
    bool empty();
};

template<class T>
LinkQueue<T>::LinkQueue() {
    auto * s =new Node<T>;
    rear = s;
    rear->next = rear;
}

template<class T>
LinkQueue<T>::~LinkQueue() {
    auto * p = rear;
    auto *q = p;
    while(p != rear) {
        q = p;
        p = p->next;
        delete q;
    }
}

template<class T>
void LinkQueue<T>::push(T x) {
    auto * s = new Node<T>;
    s->data = x;
    s->next = rear->next;
    rear->next = s;
    rear = s;
}

template<class T>
T LinkQueue<T>::pop() {
    if(rear == rear->next) {
        cerr << "ÏÂÒç";
        exit(1);
    }
    auto * p = rear->next->next;
    T x = p->data;
    rear->next->next = p->next;
    if(p->next == rear->next)
        rear = rear->next;
    delete p;
    return x;
}

template<class T>
T LinkQueue<T>::Front() {
    if(rear == rear->next) {
        cerr << "ÏÂÒç";
        exit(1);
    }
    return rear->next->next->data;
}

template<class T>
T LinkQueue<T>::back() {
    if(rear == rear->next) {
        cerr << "ÏÂÒç";
        exit(1);
    }
    return rear->data;
}

template<class T>
bool LinkQueue<T>::empty() {
    return rear == rear->next;
}

#endif //DATASTRUCTURES_LINKQUEUE_H
