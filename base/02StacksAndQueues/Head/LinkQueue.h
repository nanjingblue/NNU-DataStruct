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
    Node<T> *front;
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
    s->next = NULL;
    front = rear = s;
}

template<class T>
LinkQueue<T>::~LinkQueue() {
    auto * p = front;
    auto *q = p;
    while(p) {
        q = p;
        p = p->next;
        delete q;
    }
}

template<class T>
void LinkQueue<T>::push(T x) {
    auto * s = new Node<T>;
    s->data = x;
    s->next = NULL;
    rear->next = s;
    rear = s;
}

template<class T>
T LinkQueue<T>::pop() {
    if(rear == front) {
        cerr << "下溢";
        exit(1);
    }
    auto * p = front->next;
    T x = p->data;
    front->next = p->next;
    if(p->next == NULL)
        rear = front;
    delete p;
    return x;
}

template<class T>
T LinkQueue<T>::Front() {
    if(front->next == NULL) {
        cerr << "下溢";
        exit(1);
    }
    return front->next->data;
}

template<class T>
T LinkQueue<T>::back() {
    if(front == rear) {
        cerr << "下溢";
        exit(1);
    }
    return rear->data;
}

template<class T>
bool LinkQueue<T>::empty() {
    return front == rear;
}

#endif //DATASTRUCTURES_LINKQUEUE_H
