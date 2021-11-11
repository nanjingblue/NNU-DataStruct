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
    cout << "ÇëÊäÈëÃÔ¹¬µÄ³¤ºÍ¿í£º";
    cin >> n >> m;
    cout << "ÇëÊäÈëÃÔ¹¬¾ØÕó: " << endl;
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
