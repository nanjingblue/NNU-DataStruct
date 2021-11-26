//
// Created by cherry on 2021/11/24.
//

#ifndef LAB6_1_ALGRAPH_H
#define LAB6_1_ALGRAPH_H

#include <iostream>
#include <vector>

enum GraphType { undigraph, digraph, undinetwork, dinetwork};

struct EdgeNode {   // 边表的结点结构类型
    int adjvex; // 该边的终点位置
    EdgeNode * nextEdge;    // 指向下一条边的指针
};

template<typename T>
struct VexNode {
    T data;
    EdgeNode * firstEdge;
};

template<typename T>
class ALGraph {
    int vexnum, edgenum;
    std::vector<VexNode<T>> adjlist;    // 顶点表
    GraphType kind;
public:
    ALGraph(GraphType t, T vexs[], int n, int e);
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
        cin >> va >> vb;
        p = new EdgeNode;   // 产生第一个表结点
        p->adjvex = vb;
        p->nextEdge = adjlist[va].firstEdge;
        adjlist[va].firstEdge = p;
        p = new EdgeNode;   // 产生第二个人表结点
        p->adjvex = va;
        p->nextEdge = adjlist[vb].firstEdge; // 插入表头
        adjlist[vb].firstEdge = p;
    }
}

#endif //LAB6_1_ALGRAPH_H
