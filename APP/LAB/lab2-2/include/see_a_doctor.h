//
// Created by cherry on 2021/10/12.
//

#ifndef LAB2_2_SEE_A_DOCTOR_H
#define LAB2_2_SEE_A_DOCTOR_H

#include "seq_queue.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template<typename T, int MaxSize>
class SeeADoctor {
    SeqQueue<T, MaxSize> sqe;
public:
    string genRandStr(int len);
    void showMenu();
    void main() {
        int choose;
        while (true) {
            system("cls");
            showMenu();
            cin >> choose;
            switch (choose) {
                case 1: {
                    T str = genRandStr(6);
                    sqe.push(str);
                    cout << "�Ŷӳɹ���������Ϊ��" << str << endl;
                    system("pause"); break;
                }
                case 2: {
                    T str = sqe.pop();
                    cout << "��������ţ�" << str << endl;
                    system("pause"); break;
                }
                case 3: {
                    T str = sqe.back();
                    cout << "�鿴���л��߲�����" << endl;
                    while (str != sqe.Front()) {
                        cout << sqe.pop() << endl;
                    }
                    cout << sqe.pop() << endl;
                    sqe.push(str);
                    system("pause"); break;
                }
                case 4: {
                    return;
                }
                default: {
                    cout << "��������ȷ�Ĳ�����" << endl;
                    system("pause"); break;
                }
            }
        }
    }

};

template<typename T, int MaxSize>
string SeeADoctor<T, MaxSize>::genRandStr(int len) {
    srand(time(NULL));
    string str;
    for (int i = 1; i <= len; ++i) {
        str = str + char(('A' + rand() % 26));
    }
    return str;
}

template<typename T, int MaxSize>
void SeeADoctor<T, MaxSize>::showMenu() {
    cout << "-----1. �Ŷ�-----" << endl;
    cout << "-----2. ����-----" << endl;
    cout << "-----3. �鿴-----" << endl;
    cout << "-----4. �°�-----" << endl;
    cout << "�������������";
}

#endif //LAB2_2_SEE_A_DOCTOR_H
