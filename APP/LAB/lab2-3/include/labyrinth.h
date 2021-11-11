//
// Created by cherry on 2021/10/12.
//

#ifndef LAB2_3_LABYRINTH_H
#define LAB2_3_LABYRINTH_H

#include "seq_queue.h"
#include <iostream>
#include <queue>
#include <cstring>

struct Node {
    int x, y;
};

template<int length, int width>
class Labyrinth {
    char mp[length][width];
    char path[length][width];
    int vis[length][width];
    char k[4] = {'D', 'U', 'L', 'R'};
    int xx[4] = {1, -1, 0, 0};
    int yy[4] = {0, 0, -1, 1};
    queue<Node> q;
    int sx, sy, ex, ey;
public:
    Labyrinth(char *map, int len, int wid, int sx, int sy, int ex, int ey):sx(sx), sy(sy), ex(ex), ey(ey) {
        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j <= wid; ++j) {
                mp[i][j] = map[i * width + j];
            }
        }
        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j <= wid; ++j) {
                cout << mp[i][j] << " ";
            }
            cout << endl;
        }
        memset(vis, 0, sizeof(vis));
    }
    void print(int x, int y){
        if(path[x][y] == 'D') print(x - 1, y);
        if(path[x][y] == 'U') print(x + 1, y);
        if(path[x][y] == 'L') print(x, y + 1);
        if(path[x][y] == 'R') print(x, y - 1);
        cout << path[x][y];
    }
    void BFS(){
        q.push((Node){sx, sy});
        vis[sx][sy] = 1;
        while(!q.empty()){
            Node now = q.front();
            q.pop();
            if(now.x == ex && now.y == ey){
                print(ex, ey);
                return;
            }
            for(int i = 0; i < 4; i++){
                int dx = now.x + xx[i];
                int dy = now.y + yy[i];
                if(dx >= 1 && dx <= length && dy >= 1 && dy <= width && !vis[dx][dy] && mp[dx][dy] != '1'){
                    vis[dx][dy] = 1;
                    path[dx][dy] = k[i];
                    q.push((Node){dx, dy});
                }
            }
        }
    }
};


#endif //LAB2_3_LABYRINTH_H
