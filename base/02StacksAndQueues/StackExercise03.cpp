/*
 *  Created by c20190408��ʿ�� on 2021/9/26.
 *  4. ����ջʵ�ְ�ʮ��������ת��Ϊ����ʮ��֮�����һ����������Ĺ��ܡ�
 */
#include <iostream>
#include "LinkStack.h"
using namespace std;

const char h[] = {'A', 'B', 'C', 'D', 'E', 'F'};
// �洢���ջ��stk, ԭʮ���ƣ�val Ҫת���Ľ��ƣ�n
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
    cout << "������Ҫת��Ϊ���ٽ��ƣ�";
    cin >> n;
    cout << "������ʮ��������";
    cin >> val;
    tenToN(stk, val, n);
}
