#include <iostream>
using namespace std;

struct Node {
    int i, j;
};

const int MAX = 10010;

int n, m, mx, my;
int mp[MAX][MAX];

int main() {
    cin >> n;
    int t;
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> t;
            if (j > i) mp[i][j] = t;
            if (i == j) mp[i][j] = -1;
        }
    }
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> t;
            if (i > j) {
                mp[i][j] = t;
                if (mp[i][j] + mp[j][i] > m) {
                    mx = i;
                    my = j;
                    m = mp[i][j] +mp[j][i];
                }
            }
        }
    }
    int l;
    for (l = 1; l <=n; ++l) {
        if (l != mx && l != my) break;
    }
    int z = m;
    int x = mp[l][mx] + mp[mx][l];
    int y = mp[l][my] + mp[my][l];
    m = (y - x + z) / 2;
    m = max(m, z - m);
    cout << m << endl;
    return 0;
}