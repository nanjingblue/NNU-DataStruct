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
                    cout << "请输入要入队的数：";
                    cin >> x;
                    sqe.push(x);
                    system("pause"); break;
                }
                case 2: {
                    cout << "出队：" << sqe.pop() << endl;
                    system("pause"); break;
                }
                case 3: {
                    cout << "队首：" << sqe.Front() << endl;
                    system("pause"); break;
                }
                case 4: {
                    cout << "队尾：" << sqe.back() << endl;
                    system("pause"); break;
                }
                case 5: {
                    cout << "是否为空：" << sqe.empty() << endl;
                    system("pause"); break;
                }
                case 6: {
                    cout << "长度：" << sqe.length() << endl;
                    system("pause"); break;
                }
                default: {
                    cout << "请输入正确的操作数" << endl;
                    system("pause"); break;
                }
            }
        }
    }
    void showMenu();
};

template<typename T, int MaxSize>
void TestSeqQueue<T, MaxSize>::showMenu() {
    cout << "-----1. 入队-----" << endl;
    cout << "-----2. 出队-----" << endl;
    cout << "-----3. 获取队首-----" << endl;
    cout << "-----4. 获取对尾-----" << endl;
    cout << "-----5. 判空-----" << endl;
    cout << "-----6. 获取队列长度-----" << endl;
    cout << "-----0. 退出-----" << endl;
    cout << "请输入要执行的操作数：";
}

#endif //LAB2_2_TEST_SEQ_QUEUE_H
