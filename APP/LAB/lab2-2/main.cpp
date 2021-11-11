#include <iostream>
#include "test_seq_queue.h"
#include "see_a_doctor.h"

void showMenu() {
    cout << "-----1. class SeqQueue���в���-----" << endl;
    cout << "-----2. ��ҽ��-----" << endl;
    cout << "-----0. �˳�-----" << endl;
    cout << "�������������";
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
                cout << "�˳�";
                system("pause");
                exit(0);
            }
            default: {
                cout << "��������ȷ�Ĳ�����" << endl;
                system("pause"); break;
            }
        }
    }
    return 0;
}
