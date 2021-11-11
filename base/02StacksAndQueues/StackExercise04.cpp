/*
 *  Created by c20190408左士海 on 2021/9/26.
 *  6. 假设表达式中允许包含3种括号：圆括号、方括号和大括号。
 *  试编写一个算法，检查表达式中括号是否配对，若能够全部配对则返回1，否则返回0。
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
    cout << "请输入判断的序列：";
    cin >> str;
    cout << checkBracket(str) << endl;
}