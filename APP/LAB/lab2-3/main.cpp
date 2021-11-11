#include <iostream>
#include "labyrinth.h"

/*
010000
000100
001001
110000
 */

int main() {
    int n, m;
    cout << "�������Թ��ĳ��Ϳ�";
    cin >> n >> m;
    cout << "�������Թ�����: " << endl;
    char mp[100][100];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mp[i][j];
        }
    }
    Labyrinth<100, 100> labyrinth((char *)mp, n, m, 1, 1, n, m);
    labyrinth.BFS();
    return 0;
}
