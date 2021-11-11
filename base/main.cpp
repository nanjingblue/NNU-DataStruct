/*
 *  created by 20190408左士海  on 2021/09/27
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX= 1e6 + 20;

int t, d;
int primer[MAX], num;
bool vis[MAX];

void primes(int n)      // 欧拉筛 获得素数
{
    for(int i = 2; i <= n; i ++){
        if(!vis[i]) primer[num++] = i;
        for(int j = 0; j < num && primer[j] <= n / i; j ++){
            vis[primer[j] * i] = true;
            if(i % primer[j] == 0) break;
        }
    }
}
// 第一个因子一定为 1， 第二个因子与第三个因子的乘积 即为所求
int main() {
    primes(MAX);
    cin >> t;
    while(t--){
        cin >> d;
        int x, y;
        x = upper_bound(primer,primer + num, d) - primer;   // 第一个大于
        y = lower_bound(primer, primer + num, primer[x] + d) - primer;  // 大于等于
        cout << primer[x] * primer[y] << endl;
    }
    return 0;
}