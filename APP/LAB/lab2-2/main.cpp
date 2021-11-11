#include <iostream>
#include "test_seq_queue.h"
#include "see_a_doctor.h"

void showMenu() {
    cout << "-----1. class SeqQueue进行测试-----" << endl;
    cout << "-----2. 看医生-----" << endl;
    cout << "-----0. 退出-----" << endl;
    cout << "请输入操作数：";
}

int main() {
    int choose;
    while (true) {
        system("cls");
        showMenu();
        cin >> choose;
        switch (choose) {
            case 1: {
                TestSeqQueue<int, 200> testSeqQueue;
                testSeqQueue.main();
                system("pause"); break;
            }
            case 2: {
                SeeADoctor<string, 200> seeADoctor;
                seeADoctor.main();
                system("pause"); break;
            }
            case 0: {
                cout << "退出";
                system("pause");
                exit(0);
            }
            default: {
                cout << "请输入正确的操作数" << endl;
                system("pause"); break;
            }
        }
    }
    return 0;
}
