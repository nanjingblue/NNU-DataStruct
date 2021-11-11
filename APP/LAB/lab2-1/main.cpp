#include "seq_stack_test.h"
#include "in_expression.h"
#include "infix_to_suffix.h"
#include "suffix_expression.h"

using namespace std;

void showMenu() {
    cout << "-----1. SeqStack ����-----" << endl;
    cout << "-----2. ��׺���ʽ��ֵ-----" << endl;
    cout << "-----3. ��׺ת��׺���ʽ��-----" << endl;
    cout << "-----0. �˳�-----" << endl;
    cout << "���������ָ�";
}

int main() {
    int choose;
    while (true) {
        system("cls");
        showMenu();
        cin >> choose;
        switch (choose) {
            case 0:
                exit(0);
            case 1: {
                SeqStackTest<int, 100> test;
                test.main();
                system("pause"); break;
            }
            case 2: {
                getchar();
                string str;
                cout << "��������׺���ʽ (�� @ ��β)��";
                getline(cin, str);
                cout << "���Ϊ��" << in_Expression_Eval(str) << endl;
                system("pause"); break;
            }
            case 3: {
                getchar();
                string str;
                cout << "��������׺���ʽ (�� @ ��β)��";
                getline(cin, str);
                cout << "��׺���ʽ��" << infixToSuffix(str) << endl;
                cout << "��׺���ʽ��ֵ��" << suffix_Expression_Eval(infixToSuffix(str)) << endl;
                system("pause"); break;
            }
            default: {
                cout << "��������ȷ�Ĳ���ָ��" << endl;
            }
        }
    }
    return 0;
}