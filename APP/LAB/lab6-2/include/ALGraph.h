//
// Created by cherry on 2021/11/24.
//

#ifndef ALGRAPH_H
#define ALGRAPH_H

#include <iostream>
#include <vector>
#include <queue>

#include "CSTree.h"

typedef float weight;

enum GraphType { undigraph, digraph, undinetwork, dinetwork};

struct EdgeNode {   // �߱�Ľ��ṹ����
    int adjvex; // �ñߵ��յ�λ��
    weight cost;
    EdgeNode * nextEdge;    // ָ����һ���ߵ�ָ��
};

template<typename T>
struct VexNode {
    T data;
    EdgeNode * firstEdge;
};

template<typename T>
struct Edge {
    T adjvex;   // ��Ӧ�ڼ��� U �еĶ���
    weight lowCost;
};

template<typename T>
class ALGraph {
    int vexnum, edgenum;
    std::vector<VexNode<T>> adjlist;    // �����
    GraphType kind;
    void DFS(int v, bool * visited);
    void BFS(int v, bool * visited);
    T getVexValue(int v);
    float getEdgeValue(int v, int i);
    int miniNum(Edge<T> *miniEdges);
    void primForest(int v, std::vector<Coupe<T>> &coupes, bool *visited);
    void isExistPathK(int u, int v, int k, int now, T *path, bool *visited, bool &ans);
public:
    ALGraph(GraphType t, T vexs[], int n, int e);
    void DFSTraverse(); // ������ȱ���
    void BFSTraverse(); //  �����������
    bool isExistPath(int i, int j);
    bool isExistPathK(int i, int j, int k);
    void prim(int v);
    CSTree<T> primForest();
};

template<typename T>
ALGraph<T>::ALGraph(GraphType t, T *vexs, int n, int e) {
    EdgeNode * p;
    vexnum = n;
    edgenum = e;
    kind = t;
    adjlist.resize(vexnum);
    for (int i = 0; i < vexnum; ++i) {
        adjlist[i].data = vexs[i];
        adjlist[i].firstEdge = nullptr;
    }
    for (int j = 0; j < edgenum; ++j) {
        int va, vb;
        float w;
        std::cin >> va >> vb >> w;
        p = new EdgeNode;   // ������һ������
        p->adjvex = vb;
        p->cost = w;
        p->nextEdge = adjlist[va].firstEdge;
        adjlist[va].firstEdge = p;
        if (t == undigraph || t == undinetwork) {   // ��������ͼ���������������
            p = new EdgeNode;   // �����ڶ�������
            p->adjvex = va;
            p->cost = w;
            p->nextEdge = adjlist[vb].firstEdge; // �����ͷ
            adjlist[vb].firstEdge = p;
        }
    }
}

template<typename T>
void ALGraph<T>::DFS(int v, bool *visited) {
    std::cout << adjlist[v].data;    // ���� v �ڵ�
    visited[v] = true;  // ��Ϊ�������¼״̬ �ú��������ö�������
    EdgeNode * p = adjlist[v].firstEdge;
    while (p) {
        if (!visited[p->adjvex]) {
            DFS(p->adjvex, visited);    // û���ʹ� ����
        }
        p = p->nextEdge;
    }
}

template<typename T>
void ALGraph<T>::DFSTraverse() {
    bool * visited = new bool[vexnum];
    for (int i = 0; i < vexnum; ++i)
        visited[i] = false;
    for (int v = 0 ; v < vexnum; ++v) {
        if (!visited[v]) {
            DFS(v, visited);
        }
    }
    delete []visited;
}

template<typename T>
void ALGraph<T>::BFSTraverse() {
    bool * visited = new bool[vexnum];
    for (int i = 0; i < vexnum; ++i)
        visited[i] = false;
    for (int v = 0; v < vexnum; ++v) {
        if (!visited[v]) {
            BFS(v, visited);
        }
    }
    delete []visited;
}

template<typename T>
void ALGraph<T>::BFS(int v, bool *visited) {
    std::queue<int> q;
    std::cout << adjlist[v].data;
    visited[v] = true;
    q.push(v);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        EdgeNode * p = adjlist[u].firstEdge;
        while (p) {
            if (!visited[p->adjvex]) {
                visited[p->adjvex] = true;
                std::cout << adjlist[p->adjvex].data;
                q.push(p->adjvex);
            }
            p = p->nextEdge;
        }
    }
}

template<typename T>
bool ALGraph<T>::isExistPath(int i, int j) {
    int vis[vexnum];
    for (int k = 0; k < vexnum; ++k)
        vis[k] = 0;
    bool ans = false;
    std::queue<int> q;
    q.push(i);
    vis[i] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        // ƥ�䵽 ���˳�
        if (j == v) {
            ans = true;
            break;
        }
        // ����ǰ�ڵ� v �������ڽӶ������
        EdgeNode * p = adjlist[v].firstEdge;
        while (p) {
            if (!vis[p->adjvex]) {
                vis[p->adjvex] = 1;
                q.push(p->adjvex);
            }
            p = p->nextEdge;
        }
    }
    return ans;
}

template<typename T>
T ALGraph<T>::getVexValue(int v) {
    return adjlist[v].data;
}

template<typename T>
float ALGraph<T>::getEdgeValue(int v, int i) {
    EdgeNode * p = adjlist[v].firstEdge;
    while (p) {
        if (i == p->adjvex) {
            return p->cost;
        }
        p = p->nextEdge;
    }
    return INT_MAX;
}

template<typename T>
int ALGraph<T>::miniNum(Edge<T> *miniEdges) {
    float min = INT_MAX;
    int pos = -1;   // ����-1��ʾ �����Ѿ�ȫ�����뼯�� U
    for (int i = 0; i < vexnum; ++i) {
        if (miniEdges[i].lowCost < min && miniEdges[i].lowCost != 0) {
            min = miniEdges[i].lowCost;
            pos = i;
        }
    }
    return pos;
}

template<typename T>
void ALGraph<T>::prim(int v) {
    auto * miniEdges = new Edge<T>[vexnum];
    for (int i = 0; i < vexnum; ++i) {
        miniEdges[i].adjvex = getVexValue(v);
        miniEdges[i].lowCost = getEdgeValue(v, i);
    }
    miniEdges[v].lowCost = 0;   // ���뼯�� U
    for (int i = 1; i < vexnum; ++i) {
        int k = miniNum(miniEdges);
        std::cout << miniEdges[k].adjvex << "-->" << getVexValue(k) << std::endl;
        miniEdges[k].lowCost = 0;   // �� k ��������뼯�� U
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
CSTree<T> ALGraph<T>::primForest() {
    bool * visited = new bool[vexnum];
    for (int i = 0; i < vexnum; ++i) visited[i] = false;
    std::vector<Coupe<T>> coupes;   // ɭ��Ҳ��һ����
    for (int i = 0; i < vexnum; ++i) {
        if (!visited[i]) {
            // �������� -1 ��ʾɭ�ֵĸ�
            coupes.push_back(Coupe<T>{-1, i});
            primForest(i, coupes, visited);
        }
    }
    // ����ɭ���ú����ֵܱ�ʾ��
    CSTree<T> forest(coupes);
    delete []visited;
    return forest;
}

template<typename T>
void ALGraph<T>::primForest(int v, std::vector<Coupe<T>> &coupes, bool *visited) {
    visited[v] = true;
    auto *miniEdges = new Edge<T>[vexnum];
    for (int i = 0; i < vexnum; ++i) {
        miniEdges[i].adjvex = getVexValue(v);
        miniEdges[i].lowCost = getEdgeValue(v, i);
    }
    miniEdges[v].lowCost = 0;   // �� v ��������뼯�� U
    int k;
    k = miniNum(miniEdges);
//    if (visited[k]) return;
    while (k != -1) {
        if (visited[k]) break;
        // �� k �����뼯��u
        visited[k] = true;
        coupes.push_back(Coupe<T>{miniEdges[k].adjvex, getVexValue(k)});
        std::cout << miniEdges[k].adjvex << "-->" << getVexValue(k) << std::endl;
        miniEdges[k].lowCost = 0;
        // ����miniEdges
        for (int i = 0; i < vexnum; ++i) {
            if (getEdgeValue(k, i) < miniEdges[i].lowCost) {
                miniEdges[i].adjvex = getVexValue(k);
                miniEdges[i].lowCost = getEdgeValue(k, i);
            }
        }
        k = miniNum(miniEdges);
    }
    delete []miniEdges;
}

template<typename T>
bool ALGraph<T>::isExistPathK(int i, int j, int k) {
    bool * visited = new bool[vexnum];
    for (int i = 0; i < vexnum; ++i) visited[i] = false;
    T path[vexnum];
    bool ans = false;
    isExistPathK(i, j, k, 0, path, visited, ans);
    delete []visited;
    return ans;
}

template<typename T>
void ALGraph<T>::isExistPathK(int u, int v, int k, int now, T *path, bool *visited, bool &ans) {
    visited[u] = true;
    path[now] = u;
    if (u == v && now == k) {
        ans = true;
        for (int i = 0; i <= now; ++i) {
            std::cout << path[i];
        }
        std::cout << std::endl;
    } else {
        for (EdgeNode * p = adjlist[u].firstEdge; p; p = p->nextEdge) {
            int w = p->adjvex;
            if (!visited[w]) {
                isExistPathK(w, v, k, now + 1, path, visited, ans);
            }
        }
    }
    visited[u] = false;
    path[now] = 0;
}

#endif //ALGRAPH_H
