//
// Created by cherry on 2021/9/27.
//
#include <iostream>

using namespace std;

template<typename T, int MaxSize>
class Stack {
    T data[MaxSize];
    int top1, top2;
public:
    Stack() {
        top1 = -1;
        top2 = MaxSize;
    }
    void pushToStack1(const T& item) {
        if (top1 + 1 == top2) {
            cerr << "上溢";
            exit(1);
        }
        data[++top1] = item;
    }
    T popFromStack1() {
        if (top1 == -1) {
            cerr << "下溢";
            exit(1);
        }
        return data[top1--];
    }
    T Top1() {
        if(top1 == -1) {
            cerr << "下溢" << endl;
            exit(-1);
        }
        return data[top1];
    }
    void pushToStack2(const T & item) {
        if (top2 - 1 == top1) {
            cerr << "下溢";
            exit(-1);
        }
        data[--top2] = item;
    }
    T popFromSatck2() {
        if (top2 == MaxSize) {
            cerr << "下溢";
            exit(-1);
        }
        return data[top2++];
    }
    T Top2() {
        if (top2 == MaxSize) {
            cerr << "下溢";
            exit(-1);
        }
        return data[top2];
    }
};

int main() {
    Stack<int, 20> stk;
    stk.pushToStack1(1);
    stk.pushToStack2(10);
//   cout << stk.popFromStack1() << endl;
    cout << stk.Top1() << endl;
    cout << stk.Top2() << endl;
    cout << stk.popFromSatck2() << endl;
    cout << stk.popFromStack1() << endl;
    return 0;
}
