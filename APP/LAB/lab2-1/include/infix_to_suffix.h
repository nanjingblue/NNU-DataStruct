//
// Created by cherry on 2021/8/15.
// 栈应用
// 中缀表达式转后缀表达式 返回字符串
//
#ifndef INC_20190408ZSH_LAB2_INFIX_TO_SUFFIX_H
#define INC_20190408ZSH_LAB2_INFIX_TO_SUFFIX_H

#include <iostream>
#include <string>
#include "seq_stack.h"
using namespace std;

char Precede2(char a, char b) {
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

string infixToSuffix(string s) {
    string opt;
    SeqStack<char, 100> OPTR;
    OPTR.Push('@');
    int i=0;
    while (s[i] != '@' || OPTR.Top() != '@') {
        if(s[i] >= '0' && s[i] <= '9' || s[i] == '.' || s[i] == ' ') {
            opt += s[i];
        } else if(s[i] == '(') {
            OPTR.Push(s[i]);
        } else if(s[i] == ')') {
            while(OPTR.Top() != '(') {
                // cout << OPTR.Top();
                opt += OPTR.Pop();
            }
            OPTR.Pop();
        }  else if(s[i] == '@') {
            while (OPTR.Top() != '@') {
                // cout << OPTR.Top();
                opt += OPTR.Pop();
                opt += " ";
            }
            break;
        } else {
            if(Precede2(OPTR.Top(), s[i]) == '<') {
                OPTR.Push(s[i]);
            } else {
                // cout << OPTR.Top();
                opt += OPTR.Pop();
                opt += " ";
            }
        }
        i++;
    }
    opt += '@';
    return opt;
}

#endif //INC_20190408ZSH_LAB2_INFIX_TO_SUFFIX_H
