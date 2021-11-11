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
                    cout << "������Ҫ��ջ��ֵ��";
                    cin >> x;
                    stk.Push(x);
                    system("pause"); break;
                }
                case 2: {
                    cout << "��ջ��" << stk.Pop() << endl;
                    system("pause"); break;
                }
                case 3: {
                    cout << "�Ƿ�Ϊ�գ�" << stk.Empty() << endl;
                    system("pause"); break;
                }
                case 4: {
                    cout << "ջ����" << stk.Top() << endl;
                    system("pause"); break;
                }
                case 0: {
                    cout << "�˳�" << endl;
                    return;
                }
                default: {
                    cout << "��������ȷ�Ĳ�����" << endl;
                }
            }
        }
    }
};

template<typename T, int MaxSize>
void SeqStackTest<T, MaxSize>::showTestMenu() {
    cout << "-----SeqStack ����-----" << endl;
    cout << "-----1. ��ջ-----" << endl;
    cout << "----2. ��ջ-----" << endl;
    cout << "----3. �п�-----" << endl;
    cout << "-----4. ��ȡջ��-----" << endl;
    cout << "----0. �˳�-----" << endl;
    cout << "���������ָ�";
}


#endif //INC_20190408ZSH_LAB2_SEQ_STACK_TEST_H
