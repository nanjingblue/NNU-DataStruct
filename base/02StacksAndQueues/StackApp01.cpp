//
// Created by cherry on 2021/8/11.
//
#include <iostream>
#include <string>
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

int IsOper(char a)
{
    if(a>='0'&& a<='9'||a=='.')
        return 0;
    else	return 1;
}

double Expression_Eval(string s) {
    SeqStack<char, 100> OPTR;       // ²Ù×÷·ûÕ»
    SeqStack<double, 100> OPND;     // ²Ù×÷ÊýÕ»
    OPTR.Push('@');
    int i=0, j, point;
    char ch;
    double a, b;
    double num;
    while(s[i] != '@' || OPTR.Top() != '@') {
        if(s[i] >= '0' && s[i] <= '9' || s[i] == '.') {
            num = 0;
            point = 0;
            if(s[i] == '.') {
                point = 10;
            } else {
                num = s[i] - '0';
            }
            j = i+1;
            while (!IsOper(s[j])) {
                if(s[j] == '.') {
                    point = 10;
                    j++;
                    continue;
                }
                if(!point) {
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
                    OPTR.Push(s[i++]); break;
                case '=':
                    OPTR.Pop(); i++; break;
                case '>':
                    ch = OPTR.Top(); OPTR.Pop(); b = OPND.Top(); OPND.Pop(); a = OPND.Top(); OPND.Pop(); OPND.Push(Operate(a, ch, b));
                    break;
            }
        }
    }
    return OPND.Top();
}

int main() {
    string s;
    cin >> s;
    cout << Expression_Eval(s) << endl;
    return 0;
}
