//
// Created by cherry on 2021/8/15.
// 栈应用
// 中缀表达式转后缀表达式
//
#include <iostream>
#include "SeqStack.h"
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

void MiddleToSuffix(string s) {
    SeqStack<char, 100> OPTR;
    OPTR.Push('@');
    int i=0;
    while (s[i] != '@' || OPTR.Top() != '@') {
        if(s[i] >= '0' && s[i] <= '9' || s[i] == '.') {
            cout << s[i];
        } else if(s[i] == '(') {
            OPTR.Push(s[i]);
        } else if(s[i] == ')') {
          while(OPTR.Top() != '(') cout << OPTR.Pop();
          OPTR.Pop();
        }  else if(s[i] == '@') {
            while (OPTR.Top() != '@') cout << OPTR.Pop();
            break;
        } else {
            if(Precede(OPTR.Top(), s[i]) == '<') {
                OPTR.Push(s[i]);
            } else {
                cout << OPTR.Pop();
            }
        }
        i++;
    }
}

int main() {
    string s;
    cin >> s;
    MiddleToSuffix(s);
    return 0;
}

