//
// Created by cherry on 2021/11/24.
//

#ifndef LAB6_1_MGRAPH_H
#define LAB6_1_MGRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

enum GraphType { undigraph, digraph, undinetwork, dinetwork};

template<typename T>
struct EdgeType {
    T head, tail;
    int cost;
    EdgeType(T h, T t, int c) {
        head = h; tail = t, cost = c;
    }
    bool operator<(EdgeType<T> e);
};

template<typename T>
bool EdgeType<T>::operator<(EdgeType<T> e) {
    return cost < e.cost;
}

template<typename T>
struct Edge {
    T adjvex;
    float lowCost;
};

template<typename T>
class MGraph {
    int vexnum, edgenum;
    GraphType kind;
    std::vector<std::vector<int>> edges;    // 邻接矩阵
    std::vector<T> vexs;    // 顶点表
    void DFS(int v, bool * visited); // 连通分量的深度优先遍历
    void BFS(int v, bool * visited);    // 连通分量的广度优先遍历
    T getVexValue(int v);
    float getEdgeValue(int v, int i);
    int miniNum(Edge<T> *miniEdges);
    void getGraph(std::vector<EdgeType<T>> &graph);
public:
    MGraph(GraphType t, T v[], int n, int e);
    void DFSTraverse(); // 深度优先遍历
    void BFSTraverse(); // 广度优先遍历
    void Prim(int v);
    void Kruskal(std::vector<EdgeType<T>> &tree);
    friend void printSubTree(MGraph<T> &g, std::vector<EdgeType<T>> tree);
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
    for (int v = 0; v < vexnum; ++v)
        visited[v] = false;
    for (int v = 0; v < vexnum; ++v) {
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
            BFS(i, visited);
        }
    }
    delete []visited;
}

template<typename T>
void MGraph<T>::BFS(int v, bool *visited) {
    std::queue<int> q;
    std::cout << vexs[v];
    visited[v] = true;
    q.push(v);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int j = 0; j < vexnum; ++j) {
            if (edges[u][j] == 1 && !visited[j]) {
                std::cout << vexs[j];
                visited[j] = true;
                q.push(j);
            }
        }
    }
}

template<typename T>
void MGraph<T>::Prim(int v) {
    auto * miniEdges = new Edge<T>[vexnum];
    for (int i = 0; i < vexnum; ++i) {
        miniEdges[i].adjvex = getVexValue(v);
        miniEdges[i].lowCost = getEdgeValue(v, i);
    }
    miniEdges[v].lowCost = 0;
    for (int i = 1; i < vexnum; ++i) {
        int k = miniNum(miniEdges);
        std::cout << miniEdges[k].adjvex << "-->" << getVexValue(k) << std::endl;
        miniEdges[k].lowCost = 0;
        for (int j = 0; j < vexnum; ++j) {
            if (getEdgeValue(k, j) < miniEdges[j].lowCost) {
                miniEdges[j].adjvex = getVexValue(k);
                miniEdges[j].lowCost = getEdgeValue(k, j);
            }
        }
    }
    delete []miniEdges;
}

template<typename T>
T MGraph<T>::getVexValue(int v) {
    return vexs[v];
}

template<typename T>
float MGraph<T>::getEdgeValue(int v, int i) {
    return edges[v][i];
}

template<typename T>
int MGraph<T>::miniNum(Edge<T> *miniEdges) {
    int min = INT_MAX;
    int pos;
    for (int i = 0; i < vexnum; ++i) {
        if (miniEdges[i].lowCost < min && miniEdges[i].lowCost != 0) {
            min = miniEdges[i].lowCost;
            pos = i;
        }
    }
    return pos;
}

template<typename T>
void MGraph<T>::Kruskal(std::vector<EdgeType<T>> &tree) {
    std::vector<EdgeType<T>> graph;
    getGraph(graph);
    tree.resize(vexnum - 1);
    int * components = new int[edgenum];
    for (int i = 0; i < vexnum; ++i)
        components[i] = i;
    int k = 0, j = 0;
    while (k < vexnum - 1) {
        int h1 = graph[j].head;
        int t1 = graph[j].tail;
        int h2 = components[h1];
        int t2 = components[t1];
        if (h1 != t2) {
            tree[k].head = h1;
            tree[k].tail = t1;
            tree[k].cost = graph[j].cost;
            ++k;
            for (int i = 0; i < vexnum; ++i) {
                if (components[i] == t2)
                    components[i] = h2;
            }
            ++j;
        }
        delete []components;
    }
}

template<typename T>
void MGraph<T>::getGraph(std::vector<EdgeType<T>> &graph) {
    std::sort(graph.begin(), graph.end());
}

template<typename T>
void printSubTree(MGraph<T> &g, std::vector<EdgeType<T>> tree) {
    int i = 0;
    while (i < tree.size()) {
        std::cout << g.getVexValue(tree[i].head) << "-->" << g.getVexValue(tree[i].tail) << std::endl;
        ++i;
    }
}

#endif //LAB6_1_MGRAPH_H
