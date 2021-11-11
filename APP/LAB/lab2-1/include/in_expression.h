//
// Created by cherry on 2021/10/9.
// 中缀表达式求值 可以大数 浮点数
//

#ifndef INC_20190408ZSH_LAB2_IN_EXPRESSION_H
#define INC_20190408ZSH_LAB2_IN_EXPRESSION_H

#include <iostream>
#include <string>
#include "seq_stack.h"

using namespace std;

char Precede(char a, char b) {
    int i, j;
    char result;
    char Table[8][8] = {
            {' ','+','-','*','/','(',')','@'},
            {'+','>','>','<','<','<','>','>'},
            {'-','>','>','<','<','<','>','>'},
            {'*','>','>','>','>','<','>','>'},
            {'/','>','>','>','>','<','>','>'},
            {'(','<','<','<','<','<','=',' '},
            {')','>','>','>','>',' ','>','>'},
            {'@','<','<','<','<','<',' ','='}
    };
    for(i=0; i<8; ++i) {
        if(Table[i][0] == a)
            break;
    }
    for(j=0; j<8; ++j) {
        if(Table[0][j] == b)
            break;
    }
    result = Table[i][j];
    return result;
}

double Operate(double a, char f, double b) {
    double result;
    switch (f) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': result = a / b; break;
        default: result = 0;
    }
    return result;
}

int IsOper(char c)
{
    string s = "()+-*/@";
    for (auto it : s) {
        if (c == it)
            return true;
    }
    return false;
}

double in_Expression_Eval(string s) {
    SeqStack<char, 100> OPTR;       // 操作符栈
    SeqStack<double, 100> OPND;     // 操作数栈
    OPTR.Push('@');
    int i = 0, j, point;
    char ch;
    double a, b;
    double num;
    while (s[i] != '@' || OPTR.Top() != '@') {
        if (s[i] >= '0' && s[i] <= '9' || s[i] == '.') {
            num = 0;
            point = 0;
            if (s[i] == '.') {
                point = 10;
            } else {
                num = s[i] - '0';
            }
            j = i + 1;
            if (s[j] == ' ') {
                OPND.Push(num);
                i = j + 1;
                continue;
            }
            while (!IsOper(s[j])) {
                if (s[j] == '.') {
                    point = 10;
                    j++;
                    continue;
                } else if (s[j] == ' ') {
                    j++;
                    break;
                }
                if (!point) {
                    num = num * 10 + (s[j] - '0');
                } else {
                    num = num + 1.0 * (s[j] - '0') / point;
                    point *= 10;
                }
                j++;
            }
            i = j;
            OPND.Push(num);
        } else if (IsOper(s[i])) {
            switch (Precede(OPTR.Top(), s[i])) {
                case '<':
                    OPTR.Push(s[i++]);
                    break;
                case '=':
                    OPTR.Pop();
                    i++;
                    break;
                case '>':
                    ch = OPTR.Top();
                    OPTR.Pop();
                    b = OPND.Top();
                    OPND.Pop();
                    a = OPND.Top();
                    OPND.Pop();
                    OPND.Push(Operate(a, ch, b));
                    break;
            }
        } else {
            i++;
        }
    }
    return OPND.Top();
}

#endif //INC_20190408ZSH_LAB2_IN_EXPRESSION_H
