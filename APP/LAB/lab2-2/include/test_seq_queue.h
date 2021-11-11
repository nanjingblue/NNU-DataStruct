//
// Created by cherry on 2021/10/12.
//

#ifndef LAB2_2_TEST_SEQ_QUEUE_H
#define LAB2_2_TEST_SEQ_QUEUE_H

#include "seq_queue.h"
#include <iostream>

using namespace std;

template<typename T, int MaxSize>
class TestSeqQueue {
    SeqQueue<T, MaxSize> sqe;
public:
    void main() {
        int choose;
        while (true) {
            system("cls");
            showMenu();
            cin >> choose;
            switch (choose) {
                case 0:
                    return;
                case 1: {
                    T x;
                    cout << "������Ҫ��ӵ�����";
                    cin >> x;
                    sqe.push(x);
                    system("pause"); break;
                }
                case 2: {
                    cout << "���ӣ�" << sqe.pop() << endl;
                    system("pause"); break;
                }
                case 3: {
                    cout << "���ף�" << sqe.Front() << endl;
                    system("pause"); break;
                }
                case 4: {
                    cout << "��β��" << sqe.back() << endl;
                    system("pause"); break;
                }
                case 5: {
                    cout << "�Ƿ�Ϊ�գ�" << sqe.empty() << endl;
                    system("pause"); break;
                }
                case 6: {
                    cout << "���ȣ�" << sqe.length() << endl;
                    system("pause"); break;
                }
                default: {
                    cout << "��������ȷ�Ĳ�����" << endl;
                    system("pause"); break;
                }
            }
        }
    }
    void showMenu();
};

template<typename T, int MaxSize>
void TestSeqQueue<T, MaxSize>::showMenu() {
    cout << "-----1. ���-----" << endl;
    cout << "-----2. ����-----" << endl;
    cout << "-----3. ��ȡ����-----" << endl;
    cout << "-----4. ��ȡ��β-----" << endl;
    cout << "-----5. �п�-----" << endl;
    cout << "-----6. ��ȡ���г���-----" << endl;
    cout << "-----0. �˳�-----" << endl;
    cout << "������Ҫִ�еĲ�������";
}

#endif //LAB2_2_TEST_SEQ_QUEUE_H
