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
    int front;      // ��ͷǰһ��Ԫ�ص��±�
    int rear;        // ��β�±�
    int num;      // ����ʱ num == MAXSIZE �ӿ�ʱ num == 0
public:
    SeqQueue();
    void push(T x);     // �� x ���
    T pop();        // ����ͷ����
};

template<class T, int MAXSIZE>
SeqQueue<T, MAXSIZE>::SeqQueue() {
    front = rear = num = 0;
}

template<class T, int MAXSIZE>
void SeqQueue<T, MAXSIZE>::push(T x) {
    if (front == rear && num == MAXSIZE) {
        cerr << "����";
        exit(1);
    }
    rear = (rear + 1) % MAXSIZE;
    num++;
    data[rear] = x;
}

template<class T, int MAXSIZE>
T SeqQueue<T, MAXSIZE>::pop() {
    if(rear == front && num == 0) {
        cerr << "����" << endl;
        exit(1);
    }
    front = (front + 1) % MAXSIZE;
    num--;
    return data[front];
}
#endif //DATASTRUCTURES_SEQQUEUE_H
