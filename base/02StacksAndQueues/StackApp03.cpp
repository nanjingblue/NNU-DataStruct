//
// Created by cherry on 2021/8/16.
// 栈应用
// 后缀表达式求值
//
#include <iostream>
#include <string>
#include "SeqStack.h"

using namespace std;

int IsOper(char a)
{
    if(a>='0'&& a<='9'||a=='.')
        return 0;
    else	return 1;
}

double Operate(double a, char f, double b) {
    double result;
    switch (f) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': if(b == 0) {
                cerr << "除数不可为 0";
                exit(1);} result = a / b; break;
        default: result = 0;
    }
    return result;
}

double Expression_Eval(string s) {
    SeqStack<double, 100> OPND;     // 操作数栈
    OPND.Push('@');
    int i = 0, j, point;
    char ch;
    double num, a, b;
    while (s[i] != '@') {
        if(s[i] == ' ') {
            i++;
            continue;
        }
        if(s[i] >= '0' && s[i] <= '9' || s[i] == '.') {
            num = 0;
            point = 0;
            if(s[i] == '.') {
                point = 10;
            } else {
                num = s[i] - '0';
            }
            j = i+1;
            while(!IsOper(s[j])) {
                if(s[j] == '.') {
                    point = 10;
                    j++;
                    continue;
                }
                if(!point) {
                    num = num * 10 + s[j] - '0';
                } else {
                    num  = num + 1.0*(s[j] - '0') / point;
                    point *= 10;
                }
                j++;
            }
            i = j;
            OPND.Push(num);
        } else {
            ch = s[i];
            b = OPND.Pop();
            a = OPND.Pop();
            OPND.Push(Operate(a, ch, b));
            i++;
        }
    }
    return OPND.Top();
}

int main() {
    string s;
    cout << "请输入后缀表达式：";
    getline(cin, s);
    cout << Expression_Eval(s) <<endl;
}
