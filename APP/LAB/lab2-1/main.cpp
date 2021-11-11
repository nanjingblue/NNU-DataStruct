#include "seq_stack_test.h"
#include "in_expression.h"
#include "infix_to_suffix.h"
#include "suffix_expression.h"

using namespace std;

void showMenu() {
    cout << "-----1. SeqStack 测试-----" << endl;
    cout << "-----2. 中缀表达式求值-----" << endl;
    cout << "-----3. 中缀转后缀表达式并-----" << endl;
    cout << "-----0. 退出-----" << endl;
    cout << "请输入操作指令：";
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
                cout << "请输入中缀表达式 (以 @ 结尾)：";
                getline(cin, str);
                cout << "结果为：" << in_Expression_Eval(str) << endl;
                system("pause"); break;
            }
            case 3: {
                getchar();
                string str;
                cout << "请输入中缀表达式 (以 @ 结尾)：";
                getline(cin, str);
                cout << "后缀表达式：" << infixToSuffix(str) << endl;
                cout << "后缀表达式求值：" << suffix_Expression_Eval(infixToSuffix(str)) << endl;
                system("pause"); break;
            }
            default: {
                cout << "请输入正确的操作指令" << endl;
            }
        }
    }
    return 0;
}