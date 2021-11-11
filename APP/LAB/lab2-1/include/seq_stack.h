//
// Created by cherry on 2021/8/8.
//
#ifndef DATASTRUCTURES_SEQSTACK_H
#define DATASTRUCTURES_SEQSTACK_H

#include <iostream>

using namespace std;

/*
 * 栈：功能受限的线性表
 *  栈的顺序储存结构
 *  Last In First Out (LIFO)
 */
template <class T, int MaxSize>
class SeqStack {
    T data[MaxSize];
    int top;
public:
    SeqStack();
    void Push(T x);
    T Pop();
    T Top();
    bool Empty();
};

template<class T, int MaxSize>
SeqStack<T,MaxSize>::SeqStack() {
    top = -1;
}

// 入栈
template<class T, int MaxSize>
void SeqStack<T, MaxSize>::Push(T x) {
    if(top == MaxSize-1) {
        cerr << "上溢" ;
        exit(1);
    }
    top++;
    data[top] = x;
}

// 出栈
template<class T, int MaxSize>
T SeqStack<T, MaxSize>::Pop() {
    if(top == -1) {
        cerr << "下溢" << endl;
        exit(1);
    }
    T x = data[top];
    top--;
    return x;
}

// 取栈顶元素
template<class T, int MaxSize>
T SeqStack<T, MaxSize>::Top() {
    if(top == -1) {
        cerr << "下溢" << endl;
        exit(-1);
    }
    return data[top];
}

template<class T, int MaxSize>
bool SeqStack<T, MaxSize>::Empty() {
    return top == -1;
}

#endif //DATASTRUCTURES_SEQSTACK_H
