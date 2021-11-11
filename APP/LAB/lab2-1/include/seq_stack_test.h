//
// Created by cherry on 2021/10/9.
//

#ifndef INC_20190408ZSH_LAB2_SEQ_STACK_TEST_H
#define INC_20190408ZSH_LAB2_SEQ_STACK_TEST_H

#include "seq_stack.h"
#include <iostream>                             

using namespace std;

template <typename T, int MaxSize>
class SeqStackTest {
    SeqStack<T, MaxSize> stk;
public:
    void showTestMenu();
    void main() {
        int choose;
        while (true) {
            system("cls");
            showTestMenu();
            cin >> choose;
            switch (choose) {
                case 1: {
                    T x;
                    cout << "请输入要入栈的值：";
                    cin >> x;
                    stk.Push(x);
                    system("pause"); break;
                }
                case 2: {
                    cout << "出栈：" << stk.Pop() << endl;
                    system("pause"); break;
                }
                case 3: {
                    cout << "是否为空：" << stk.Empty() << endl;
                    system("pause"); break;
                }
                case 4: {
                    cout << "栈顶：" << stk.Top() << endl;
                    system("pause"); break;
                }
                case 0: {
                    cout << "退出" << endl;
                    return;
                }
                default: {
                    cout << "请输入正确的操作数" << endl;
                }
            }
        }
    }
};

template<typename T, int MaxSize>
void SeqStackTest<T, MaxSize>::showTestMenu() {
    cout << "-----SeqStack 测试-----" << endl;
    cout << "-----1. 入栈-----" << endl;
    cout << "----2. 出栈-----" << endl;
    cout << "----3. 判空-----" << endl;
    cout << "-----4. 获取栈顶-----" << endl;
    cout << "----0. 退出-----" << endl;
    cout << "请输入操作指令：";
}


#endif //INC_20190408ZSH_LAB2_SEQ_STACK_TEST_H
