//
// Created by cherry on 2021/11/24.
//

#ifndef LAB6_1_ALGRAPH_H
#define LAB6_1_ALGRAPH_H

#include <iostream>
#include <vector>
#include <queue>

enum GraphType { undigraph, digraph, undinetwork, dinetwork};

struct EdgeNode {   // �߱�Ľ��ṹ����
    int adjvex; // �ñߵ��յ�λ��
    EdgeNode * nextEdge;    // ָ����һ���ߵ�ָ��
};

template<typename T>
struct VexNode {
    T data;
    EdgeNode * firstEdge;
};

template<typename T>
class ALGraph {
    int vexnum, edgenum;
    std::vector<VexNode<T>> adjlist;    // �����
    GraphType kind;
    void DFS(int v, bool * visited);
    void BFS(int v, bool * visited);
public:
    ALGraph(GraphType t, T vexs[], int n, int e);
    void DFSTraverse(); // ������ȱ���
    void BFSTraverse(); //  �����������
    bool isExistPath(int i, int j);
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
        adjlist[i].firstEdge = 0;
    }
    for (int j = 0; j < edgenum; ++j) {
        int va, vb;
        std::cin >> va >> vb;
        p = new EdgeNode;   // ������һ������
        p->adjvex = vb;
        p->nextEdge = adjlist[va].firstEdge;
        adjlist[va].firstEdge = p;
//        p = new EdgeNode;   // �����ڶ���`����
//        p->adjvex = va;
//        p->nextEdge = adjlist[vb].firstEdge; // �����ͷ
//        adjlist[vb].firstEdge = p;
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

#endif //LAB6_1_ALGRAPH_H
