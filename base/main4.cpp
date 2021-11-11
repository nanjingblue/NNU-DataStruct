#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
long long cnt, num;
long long a[1000010];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    if (a[n] - a[1] == 0) {
        cout << n * (n - 1) / 2 << endl;
        return 0;
    }
    for (int i = 1; i <n; ++i) {
        if (i > 1 && a[i] == a[i - 1]) {
            num++;
            cnt += num;
            continue;
        }
        num = 0;
        for (int j = n; a[j] > a[i]; j--) {
            if ((a[j] - a[i]) % k == 0) {
                num ++;
            }
        }
        cnt += num;
    }
    cout << cnt << endl;
    return 0;
}