//
// Created by cherry on 2021/11/24.
//

#ifndef LAB6_1_MGRAPH_H
#define LAB6_1_MGRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>

const int maxx = 100;

enum GraphType { undigraph, digraph, undinetwork, dinetwork};

typedef int weight; // 定义权值类型
const int INFINITY = 999999;

template<typename T>
struct EdgeType {
    T head, tail;
    weight cost;
    EdgeType();
    EdgeType(T h, T t, weight c) {
        head = h; tail = t, cost = c;
    }
    bool operator<(EdgeType<T> e);
};

template<typename T>
bool EdgeType<T>::operator<(EdgeType<T> e) {
    return cost < e.cost;
}

template<typename T>
EdgeType<T>::EdgeType() {
    head = -1;
    tail = -1;
    cost = 0;
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
    int getEdgeValue(int v, int i);
    int miniNum(Edge<T> *miniEdges);
    void getGraph(std::vector<EdgeType<int>> &graph);
    void dijkstra(int v, int path[], int dist[]);
    void floyd(int path[][maxx], int D[][maxx]);
public:
    MGraph(GraphType t, const std::string& filename);
    void DFSTraverse(); // 深度优先遍历
    void BFSTraverse(); // 广度优先遍历
    void Prim(int v);
    void Kruskal(std::vector<EdgeType<int>> &tree);
    void Dijkstra(int v);
    void Floyd();

    template<typename T1, typename T2>
    friend void printSubTree(MGraph<T1> &g, std::vector<EdgeType<T2>> tree);

    template<typename T1>
    friend void printPath(MGraph<T1> * g, int *path, int *dist, int v);
};

template<typename T>
MGraph<T>::MGraph(GraphType t, const std::string& filename) {
    std::ifstream ifs(filename, std::ios::in);
    ifs >> vexnum;
    ifs >> edgenum;
    kind = t;
    vexs.resize(vexnum);
    edges.resize(vexnum);
    for (int i = 0; i < vexnum; ++i) {
        ifs >> vexs[i];
    }
    for (int i = 0; i < vexnum; ++i) {
        edges[i].resize(vexnum);
    }
    for (int i = 0; i < vexnum; ++i) {
        for (int j = 0; j < vexnum; ++j) {
            if (i == j)
                edges[i][j] = 0;
            else
                edges[i][j] = INFINITY;
        }
    }
    for (int i = 0; i < edgenum; ++i) {
        int va, vb, w;
        ifs >> va >> vb >> w;
        edges[va][vb] = w;
        if (t == undinetwork || t == undigraph)
            edges[vb][va] = w;
    }
    ifs.close();
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
        std::cout << miniEdges[k].adjvex << "-->" << getVexValue(k) << miniEdges[k].lowCost << std::endl;
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
int MGraph<T>::getEdgeValue(int v, int i) {
    return edges[v][i];
}

template<typename T>
int MGraph<T>::miniNum(Edge<T> *miniEdges) {
    int min = INFINITY;
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
void MGraph<T>::Kruskal(std::vector<EdgeType<int>> &tree) {
    std::vector<EdgeType<int>> graph;
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

/*
 * getGraph 按照边的权值排序 将其存放在graph中
 * 邻接矩阵是二维数组 由于不可以改变邻接矩阵的原值
 * 这里先把所有边添加进vector 再直接排序
 */
template<typename T>
void MGraph<T>::getGraph(std::vector<EdgeType<int>> &graph) {
    for (int i = 0; i < vexnum; ++i) {
        for (int j = 0; j < vexnum; ++j) {
            if (i < j && edges[i][j] != INFINITY)
                graph.emplace_back(i, j, edges[i][j]);
        }
    }
    std::sort(graph.begin(), graph.end());  // 默认递增
}

template<typename T1, typename T2>
void printSubTree(MGraph<T1> &g, std::vector<EdgeType<T2>> tree) {
    int i = 0;
    while (i < tree.size()) {
        std::cout << g.getVexValue(tree[i].head) << "-->" << g.getVexValue(tree[i].tail) << "-->"<< tree[i].cost <<  std::endl;
        ++i;
    }
}

template<typename T>
void MGraph<T>::Dijkstra(int v) {
    int * path = new int[vexnum];
    int * dist = new int[vexnum];
    memset(path, 0, sizeof(path));
    memset(dist, 0, sizeof(dist));
    dijkstra(v, path, dist);
    printPath(this, path, dist, 4);
    delete []path;
    delete []dist;
}

/*
 * dijkstra
 * 求出从编号v的顶点到其余各点的最短路径 path中存放路径 dist中存放路径长度
 */
template<typename T>
void MGraph<T>::dijkstra(int v, int *path, int *dist) {
    bool * s = new bool[vexnum];
    int k;
    for (int i = 0; i < vexnum; ++i) {
        s[i] = false;
        dist[i] = getEdgeValue(v, i);   // 距离初始化
        if (dist[i] < INFINITY && i != v)    // 路径初始化
            path[i] = v;
        else
            path[i] = -1;   // 表示顶点 i 的前驱顶点不是 v
    }
    dist[v] = 0;
    s[v] = true;
    for (int i = 1; i < vexnum; ++i) {
        int min = INFINITY;  // 设置最短路径初值为足够大的数
        for (int j = 0; j < vexnum; ++j) {
            if (!s[j] && dist[j] < min) {
                k = j;
                min = dist[j];
            }
        }
        s[k] = true;    // 将距离v最近的顶点加入集合s中
        for (int w = 0; w < vexnum; ++w) {
            if (!s[w] && (dist[k] + getEdgeValue(k, w)) < dist[w]) {
                dist[w] = dist[k] + getEdgeValue(k, w);
                path[w] = k;
            }
        }
    }
    delete []s;
}

template<typename T1>
void printPath(MGraph<T1> * g, int *path, int *dist, int v) {
    if (v == -1) return;
    printPath(g, path, dist, path[v]);
    std::cout << g->getVexValue(v) << "-->";
}

template<typename T>
void MGraph<T>::floyd(int path[][maxx], int D[][maxx]) {
    for (int i = 0; i < vexnum; ++i) {
        for (int j = 0; j < vexnum; ++j) {
            if (i == j)
                D[i][j] = 0;
            else
                D[i][j] = getEdgeValue(i, j);
            if (D[i][j] < INFINITY)
                path[i][j] = j;
            else
                path[i][j] = -1;
        }
        for (int k = 0; k < vexnum; ++k) {
            for (int i = 0; i < vexnum; ++i) {
                for (int j = 0; j < vexnum; ++j) {
                    if (D[i][k] + D[k][j] < D[i][j]) {
                        D[i][j] = D[i][k] + D[k][j];    // 修改最短路径长度
                        path[i][j] = path[i][k];     // 修改最短路径
                    }
                }
            }
        }
    }
}

template<typename T>
void MGraph<T>::Floyd() {
    int path[maxx][maxx];
    int D[maxx][maxx];
    floyd(path, D);
    for (int i = 0; i < vexnum; ++i) {
        for (int j = 0; j < vexnum; ++j) {
            std::cout << D[i][j] << std::setw(10) << " ";
        }
        std::cout << std::endl;
    }
}

#endif //LAB6_1_MGRAPH_H
