/*
 *  Created by c20190408左士海 on 2021/9/26.
 *  4. 利用栈实现把十进制整数转换为二至十六之间的任一进制数输出的功能。
 */
#include <iostream>
#include "LinkStack.h"
using namespace std;

const char h[] = {'A', 'B', 'C', 'D', 'E', 'F'};
// 存储结果栈：stk, 原十进制：val 要转化的进制：n
void tenToN(LinkStack<int> stk, int val, int n) {
    if(val == 0) {
        while (!stk.Empty()) {
            int x = stk.Pop();
            if(x < 10) {
                cout << x;
            } else {
                cout << h[x%10];
            }
        }
        cout << endl;
        return;
    }
    stk.Push(val % n );
    val /= n;
    tenToN(stk, val, n);
}

int main() {
    int n;
    int val;
    LinkStack<int> stk;
    cout << "请输入要转化为多少进制：";
    cin >> n;
    cout << "请输入十进制数：";
    cin >> val;
    tenToN(stk, val, n);
}
