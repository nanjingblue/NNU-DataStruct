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
struct Edge {
    T adjvex;
    float lowCost;
};

template<typename T>
class MGraph {
    int vexnum, edgenum;
    GraphType kind;
    std::vector<std::vector<int>> edges;    // �ڽӾ���
    std::vector<T> vexs;    // �����
    void DFS(int v, bool * visited); // ��ͨ������������ȱ���
    void BFS(int v, bool * visited);    // ��ͨ�����Ĺ�����ȱ���
    int getVexValue(int v);
    float getEdgeValue(int v, int i);
    int miniNum(Edge<T> *miniEdges);
public:
    MGraph(GraphType t, T v[], int n, int e);
    void DFSTraverse(); // ������ȱ���
    void BFSTraverse(); // ������ȱ���
    void Prim(int v);
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
    std::cout << vexs[v];   // ���ʵ� v ������
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
int MGraph<T>::getVexValue(int v) {
    return v;
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


#endif //LAB6_1_MGRAPH_H
