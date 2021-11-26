//
// Created by cherry on 2021/11/23.
//

#ifndef DATASTRUCTURES_GRAPHMATRIX_H
#define DATASTRUCTURES_GRAPHMATRIX_H

#include <iostream>
#include <vector>
#include "Graph.h"

template <typename Tv>
struct Vertex {
    Tv data; int inDegree, outDegree; VStatus status; // 数据 出入度数 状态
    int dTime, fTime;   // 时间标签
    int parent; int priority;   // 在遍历树中的父结点 优先级数
    explicit Vertex(Tv const& d = (Tv) 0) : data(d), inDegree(0), outDegree(0), status(UNDISCOVERED),
    dTime(-1), fTime(-1), parent(-1), priority(INT_MAX) {}  // 暂不考虑权重溢出
};

template <typename Te>
struct Edge {
    Te data; int weight; EType type;    // 数据 权重 类型
    Edge(Te const& d, int w) : data(d), weight(w), type(UNDETERMINED) {}
};

template <typename Tv, typename Te> // 顶点类型，边类型
class GraphMatrix : public Graph<Tv, Te> {
private:
    std::vector<Vertex<Tv>> V; // 顶点集(向量)
    std::vector< std::vector<Edge<Te> *> > E;   // 边集（邻接矩阵）
public:
    GraphMatrix() { n = e = 0; }    // 构造
    ~GraphMatrix() {
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                delete E[j][k];
    }
    // 顶点的基本操作
    virtual Tv& vertex(int i) { return V[i].data; } // 数据
    virtual int inDegree(int i) { return V[i].inDegree;}    // 入度
    virtual int outDegree(int i) { return  V[i].outDegree; }    // 出度
    virtual int firstNbr(int i) { return nextNbr(i, n); }   // 首个邻接顶点
    virtual int nextNbr(int i, int j) {     // 相对于顶点 j 的下一个邻接顶点(改用邻接表可提高效率
        while ((-1 < j) && (!exists(i, --j))); return j;    // 逆向线性试探
    }
    virtual VStatus& status ( int i ) { return V[i].status; } //状态
    virtual int& dTime ( int i ) { return V[i].dTime; } //时间标签dTime
    virtual int& fTime ( int i ) { return V[i].fTime; } //时间标签fTime
    virtual int& parent ( int i ) { return V[i].parent; } //在遍历树中癿父亲
    virtual int& priority ( int i ) { return V[i].priority; } //在遍历树中癿优先级数
    // 顶点的动态操作
    virtual int insert(Tv const& vertex);  // 插入顶点返回编号
    virtual Tv remove(int i);  // 删除第 i 个顶点及其关联边
    // 边的确认操作
    virtual bool exists(int i, int j);  // 边 (i, j)是否存在
    // 边的基本操作 查询顶点 i 与 j 之间的联边（0 <= i, j < n 且 exists(i, j) ）
    virtual EType& type(int i, int j) { return E[i][j]->type; } // 边(i, j)的类型
    virtual Te& edge(int i, int j) { return E[i][j]->data; }    // 边(i, j)的数据
    virtual int& weight(int i, int j) { return E[i][j]->weight; }       // 边(i, j) 的权重
    // 边的动态操作
    virtual void insert(Te const& edge, int w, int i, int j);   // 插入权重为 w 的边 e = (i, j)
    virtual Te remove(int i, int j);    // 删除顶点 i 和 j 之间的联边
};

template<typename Tv, typename Te>
Tv GraphMatrix<Tv, Te>::remove(int i) {
    for (int j = 0; j < n; ++j) {
        if (exists(i, j)) {
            delete E[i][j]; V[j].inDegree--;
        }  // 逐条删除
    }
    E.erase(i); --n;
    Tv vBak = vertex(i); V.erase(i);    // 删除顶点 i
    for (int j = 0; j < n; ++j) {
        if (Edge<Te> * e = E[j][i]) {
            E[j].erase(i);
            delete e;
            V[j].outDegree--;   // 逐条删除
        }
    }
    return vBak;    // 返回被删除顶点的信息
}

template<typename Tv, typename Te>
bool GraphMatrix<Tv, Te>::exists(int i, int j) {
    return (0 <= i) && (i < n) && (0 <= j) && (j < n) && E[i][j] != nullptr;
}

template<typename Tv, typename Te>
int GraphMatrix<Tv, Te>::insert(const Tv &vertex) {
    for (int j = 0; j < n; ++j) E[j].insert(nullptr); ++n;  // 各顶点预留一条潜在的关联边
    E.insert(std::vector<Edge<Te> *> (n, n, (Edge<Te> *) nullptr)); // 创建新顶点对应的边向量
    return V.insert(Vertex<Tv> (vertex));   // 顶点向量增加一个顶点
}

template<typename Tv, typename Te>
void GraphMatrix<Tv, Te>::insert(const Te& edge, int w, int i, int j) {
    if (exists(i, j)) return;   // 确保该边不存在
    E[i][j] = new Edge<Te>(edge, w);    // 创建新边
    e++;
    V[i].outDegree++;
    V[j].inDegree++;    // 更新边计数与关联顶点度数
}

template<typename Tv, typename Te>
Te GraphMatrix<Tv, Te>::remove(int i, int j) {
    Te eBak = edge(i, j);
    delete E[i][j];
    E[i][j] = nullptr;
    e--;
    V[i].outDegree--;
    V[j].inDegree--;
    return eBak;
}


#endif //DATASTRUCTURES_GRAPHMATRIX_H
