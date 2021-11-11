//
// Created by cherry on 2021/10/11.
//

#ifndef INC_20190408ZSH_LAB2_SUFFIX_EXPRESSION_H
#define INC_20190408ZSH_LAB2_SUFFIX_EXPRESSION_H

#include <iostream>
#include "seq_stack.h"

bool isOperate(char c) {
    string a = "+-*/";
    for (auto it : a) {
        if (c == it)
            return true;
    }
    return false;
}

double operate(double a, double b, char f) {
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

double suffix_Expression_Eval(string s) {
    SeqStack<double, 100> OPND;
    int i = 0, j, point;
    double a, b;
    double num;
    while (s[i] != '@') {
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
        } else if (isOperate(s[i])) {
            a = OPND.Top();
            OPND.Pop();
            b = OPND.Top();
            OPND.Pop();
            OPND.Push(operate(b, a, s[i]));
            i++;
        } else {
            i++;
        }
    }
    return OPND.Top();
}

#endif //INC_20190408ZSH_LAB2_SUFFIX_EXPRESSION_H
