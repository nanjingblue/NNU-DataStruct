/*
 *  Created by c20190408��ʿ�� on 2021/9/26.
 *  ���Ϊ1��2��3��4��5�������г���˳�򿪽�һ��ջʽ�ṹ��վ�㣬�ʿ�����վ��˳���ж����ֿ��ܣ�
 *  �����д�����п��ܵĳ�ջ���С�
 */
#include <iostream>
#include "LinkStack.h"

using namespace std;

const int MAXN = 100;
int n;
int input[MAXN];
LinkStack<int> stk;
int now[MAXN];
int ans;

// ��ջ�ĸ��� i, ��ջ���� j, �������� n, ջ stk, ��ǰ��ջ���� now, �ܸ��� ans
void dfs(int i, int j, int n, int input[], LinkStack<int> & stk, int now[], int & ans) {
    if(i == n) {    // ȫ����ջ
        if(!stk.Empty()) {  // ջ��Ϊ�� ֻ�ܳ�ջ
            int x = stk.Pop();
            now[j + 1] = x;
            dfs(i, j+1, n, input, stk, now, ans);
            stk.Push(x);
            now[j + 1] = 0;
        } else {
            ans++;
            for (int k = 1; k <= i; ++k) {
                cout << now[k] << " ";
            }
            cout << endl;
        }
    } else {        // ����ѡ���ջ������ջ
        // ��ջ
        stk.Push(input[i + 1]);
        dfs(i + 1, j, n, input, stk, now, ans);
        stk.Pop();
        // ��ջ
        if(!stk.Empty()) {
            int x = stk.Pop();
            now[j + 1] = x;
            dfs(i, j + 1, n, input, stk, now, ans);
            stk.Push(x);
            now[j + 1] = 0;
        }
    }
}

int main() {
    cout << "input list length: ";
    cin >> n;
    cout << "input list: ";
    for(int i=1; i<=n; ++i) {
        cin >> input[i];
    }
    dfs(0, 0, n, input, stk, now, ans);
    cout << ans << endl;
}