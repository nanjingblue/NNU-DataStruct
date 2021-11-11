//
// Created by cherry on 2021/8/16.
//

#ifndef DATASTRUCTURES_SEQQUEUE_H
#define DATASTRUCTURES_SEQQUEUE_H

#include <iostream>

using namespace std;

template<class T, int MAXSIZE>
class SeqQueue {
    T data[MAXSIZE];
    // ѭ������Ϊ�ջ������������� front = rear
    int front;      // ��ͷǰһ��Ԫ�ص��±�
    int rear;        // ��β�±�
public:
    SeqQueue();
    void push(T x);     // �� x ���
    T pop();        // ����ͷ����
    T Front();
    T back();
    bool empty();
    int length() { return (front - rear + MAXSIZE) % MAXSIZE; }
};

template<class T, int MAXSIZE>
SeqQueue<T, MAXSIZE>::SeqQueue() {
    front = rear = 0;
}

template<class T, int MAXSIZE>
void SeqQueue<T, MAXSIZE>::push(T x) {
    if((rear + 1) % MAXSIZE == front) {
        cerr << "����";
        exit(1);
    }
    rear = (rear + 1) % MAXSIZE;
    data[rear] = x;
}

template<class T, int MAXSIZE>
T SeqQueue<T, MAXSIZE>::pop() {
    if(rear == front) {
        cerr << "����" << endl;
        exit(1);
    }
    front = (front + 1) % MAXSIZE;
    return data[front];
}

template<class T, int MAXSIZE>
T SeqQueue<T, MAXSIZE>::Front() {
    return data[(front+1) % MAXSIZE];
}

template<class T, int MAXSIZE>
T SeqQueue<T, MAXSIZE>::back() {
    return data[(rear) % MAXSIZE];
}

template<class T, int MAXSIZE>
bool SeqQueue<T, MAXSIZE>::empty() {
    return rear == front;
}

#endif //DATASTRUCTURES_SEQQUEUE_H
