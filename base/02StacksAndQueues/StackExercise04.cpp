/*
 *  Created by c20190408��ʿ�� on 2021/9/26.
 *  6. ������ʽ���������3�����ţ�Բ���š������źʹ����š�
 *  �Ա�дһ���㷨�������ʽ�������Ƿ���ԣ����ܹ�ȫ������򷵻�1�����򷵻�0��
 */
#include <iostream>
#include <string>
#include "LinkStack.h"

using namespace std;

int checkBracket(string str) {
    LinkStack<char> stk;
    int len = str.length();
    int i = 0;
    while (i < len) {
        switch (str[i]) {
            case '[': case '(': case '{':
                stk.Push(str[i++]);
                break;
            case ']': case ')': case '}':
                if (!stk.Empty()) {
                    char e = stk.Pop();
                    if ((str[i] == ']' && e != '[')
                            || (str[i] == ')' && e != '(')
                            || (str[i] == '{' && e != '}')) {
                        return 0;
                    } else {
                        i++;
                        break;
                    }
                } else {
                    return 0;
                }
            default:
                i++;
        }
    }
    return 1;
}

int main() {
    string str;
    cout << "�������жϵ����У�";
    cin >> str;
    cout << checkBracket(str) << endl;
}