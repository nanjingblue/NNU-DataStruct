/*
 *  Created by c20190408左士海 on 2021/9/26.
 *  编号为1、2、3、4、5的五辆列车，顺序开进一个栈式结构的站点，问开出车站的顺序有多少种可能？
 *  请具体写出所有可能的出栈序列。
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

// 入栈的个数 i, 出栈个数 j, 序列总数 n, 栈 stk, 当前出栈序列 now, 总个数 ans
void dfs(int i, int j, int n, int input[], LinkStack<int> & stk, int now[], int & ans) {
    if(i == n) {    // 全部入栈
        if(!stk.Empty()) {  // 栈不为空 只能出栈
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
    } else {        // 可以选择出栈或者入栈
        // 入栈
        stk.Push(input[i + 1]);
        dfs(i + 1, j, n, input, stk, now, ans);
        stk.Pop();
        // 出栈
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