//
// Created by cherry on 2021/11/24.
//

#ifndef LAB6_1_MGRAPH_H
#define LAB6_1_MGRAPH_H

#include <iostream>
#include <vector>
#include <queue>

enum GraphType { undigraph, digraph, undinetwork, dinetwork};

template<typename T>
struct EdgeType {
    T head, tail;
    int cost;
    EdgeType(T h, T t, int c) {
        head = h; tail = t, cost = c;
    }
};

template<typename T>
class MGraph {
    int vexnum, edgenum;
    GraphType kind;
    std::vector<std::vector<int>> edges;    // 邻接矩阵
    std::vector<T> vexs;    // 顶点表
    void DFS(int v, bool * visited); // 连通分量的深度优先遍历
    void BFS(int v, bool * visited);    // 连通分量的广度优先遍历
public:
    MGraph(GraphType t, T v[], int n, int e);
    void DFSTraverse(); // 深度优先遍历
    void BFSTraverse(); // 广度优先遍历
};

template<typename T>
MGraph<T>::MGraph(GraphType t, T *v, int n, int e) {
    vexnum = n;
    edgenum = e;
    kind = t;
    vexs.resize(vexnum);
    edges.resize(vexnum);
    for (int i = 0; i < n; ++i) {
        vexs[i] = v[i];
    }
    for (int i = 0; i < n; ++i) {
        edges[i].resize(vexnum);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                edges[i][j] = 0;
            else
                edges[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < e; ++i) {
        int va, vb, w;
        std::cin >> va >> vb >> w;
        edges[va][vb] = edges[vb][va] = w;
    }
}

template<typename T>
void MGraph<T>::DFS(int v, bool *visited) {
    std::cout << vexs[v];   // 访问第 v 个顶点
    visited[v] = true;
    for (int i = 0; i < vexnum; ++i) {
        if (edges[v][i] == 1 && !visited[i])
            DFS(i, visited);
    }
}

template<typename T>
void MGraph<T>::DFSTraverse() {
    bool * visited = new bool[vexnum];
    for (int v = 0; i < vexnum; ++v)
        visited[v] = false;
    for (int v = 0; i < vexnum; ++v) {
        if (!visited[v]) {
            DFS(v, visited);
        }
    }
    delete []visited;
}

template<typename T>
void MGraph<T>::BFSTraverse() {
    bool * visited = new bool[vexnum];
    for (int i = 0; i < vexnum; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < vexnum; ++i) {
        if (!visited[i]) {
            BFS(v, visited);
        }
    }
    delete []visited;
}

template<typename T>
void MGraph<T>::BFS(int v, bool *visited) {
    std::queue<int> q;
    cout << vexs[v];
    visited[v] = true;
    q.push(v);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int j = 0; i < vexnum; ++j) {
            if (edges[u][j] == 1 && !visited[j]) {
                std::cout << vexs[j];
                visited[j] = true;
                q.push(j);
            }
        }
    }
}


#endif //LAB6_1_MGRAPH_H
