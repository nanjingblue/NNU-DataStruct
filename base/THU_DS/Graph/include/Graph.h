//
// Created by cherry on 2021/11/23.
//

#ifndef DATASTRUCTURES_GRAPH_H
#define DATASTRUCTURES_GRAPH_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

typedef enum { UNDISCOVERED, DISCOVERED, VISITED} VStatus;  // 顶点状态
typedef enum  { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD} EType;    // 边在遍历树中所属类型

template <typename Tv, typename Te> // 顶点类型，边类型
class Graph { // 图 Graph 模板类
private:
    void reset() {
        for (int i = 0; i < n; ++i) {
            status(i) = UNDISCOVERED; dTime(i) = fTime(i) = -1; // 状态，时间标签
            parent(i) = -1; priority(i) = INT_MAX;  // (在遍历树中的）父节点，优先级数
            for (int j = 0; i < n; ++j) // 所有边的
                if (exists(i, j)) type(i, j) = UNDETERMINED;    // 类型
        }
    }
    void BFS(int, int&);    // (连通域) 广度优先搜索算法
    void DFS(int, int&);    // (连通域) 深度优先算法
    void BCC(int, int &, std::stack<int>&);     // (连通域) 基于DFS的双连通分量分解算法
    bool TSort ( int, int&, Stack<Tv>* ); //（连通域）基亍DFS癿拓扑排序算法
    template <typename PU> void PFS ( int, PU ); //（连通域）优先级搜索框架
public:
    // 顶点
    int n;
    virtual int insert ( Tv const& ) = 0; //插入顶点 返回编号
    virtual Tv remove ( int ) = 0;   //删除顶点及其关联边，返回该顶点信息
    virtual Tv& vertex ( int ) = 0; //顶点v的数据（该顶点的确存在）
    virtual int inDegree ( int ) = 0; //顶点v癿入度（诠顶点癿确存在）
    virtual int outDegree ( int ) = 0; //顶点v癿出度（诠顶点癿确存在）
    virtual int firstNbr ( int ) = 0; //顶点的首个邻接顶点
    virtual int nextNbr ( int, int ) = 0; //顶点v的（相对亍顶点j的）下一邻接顶点
    virtual VStatus& status ( int ) = 0; //顶点v的状态
    virtual int& dTime ( int ) = 0; //顶点v癿时间标签dTime
    virtual int& fTime ( int ) = 0; //顶点v癿时间标签fTime
    virtual int& parent ( int ) = 0; //顶点v在遍历树中癿父亲
    virtual int& priority ( int ) = 0; //顶点v在遍历树中癿优先级数
    // 边：返里约定，无向边均统一转化为斱向互逆对的一对有向边，从而将无向图规作有向图癿特例
    int e; //边总数
    virtual bool exists ( int, int ) = 0; //边(v, u)是否存在
    virtual void insert ( Te const&, int, int, int ) = 0; //在顶点v和u乀间揑入权重为w癿边e
    virtual Te remove ( int, int ) = 0; //初除顶点v和u乀间癿边e，迒回诠边信息
    virtual EType& type ( int, int ) = 0; //边(v, u)癿类型
    virtual Te& edge ( int, int ) = 0; //边(v, u)癿数据（诠边癿确存在）
    virtual int& weight ( int, int ) = 0; //边(v, u)癿权重
    // 算法
    void bfs ( int ); //广度优先搜索算法
    void dfs ( int ); //深度优先搜索算法
    void bcc ( int ); //基亍DFS癿双连通分量分解算法
    std::stack<Tv>* tSort ( int ); //基亍DFS癿拓扑排序算法
    void prim ( int ); //最小支撑树Prim算法
    void dijkstra ( int ); //最短路径Dijkstra算法
    template <typename PU> void pfs ( int, PU ); //优先级搜索框架
};

template<typename Tv, typename Te>
void Graph<Tv, Te>::bfs(int s) {
    reset(); int clock = 0; int v = s;  // 初始化
    do {
        if (UNDISCOVERED == status(v)) {    // 一旦遇到尚未发现的顶点
            BFS(v, clock);  // 即从该顶点出发启动 BFS
        }
    } while (s != (v = (++v % n))); // 按序号检查，故不漏不重
}

template<typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int& clock) {
    std::queue<int> Q;
    status(v) = DISCOVERED;
    Q.push(v);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        dTime(v) = ++clock;
        for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {
            if (UNDISCOVERED == status(u)) {
                status(u) = DISCOVERED; // 发现该节点
                Q.push(u);
                type(v, u) = TREE;  // 引入树边拓展支撑树
                parent(u) = v;
            } else {
                type(v, u) = CROSS; // 将(v, u) 归类于跨边
            }
        }
        status(v) = VISITED;    // 至此 当前顶点访问完毕
    }
}

template<typename Tv, typename Te>
void Graph<Tv, Te>::dfs(int s) {
    reset(); int clock = 0; int v = s;  // 初始化
    do {
        if (UNDISCOVERED == status(v)) {
            DFS(v, clock);
        }
    } while (s != (v = (++v % n))); // 按序号检查
}

template<typename Tv, typename Te>
void Graph<Tv, Te>::DFS(int v, int& clock) {     //assert: 0 <= v < n
    dTime(v) = ++clock;
    status(v) = DISCOVERED; // 发现当前顶点
    for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {
        switch (status(u)) {
            case UNDISCOVERED:  // 未发现
                type(v, u) = TREE;
                parent(u) = v;
                DFS(u, clock);
                break;
            case DISCOVERED:    // 已发现但为访问完毕
                type(v, u) = BACKWARD;
                break;
            default:
                type(v, u) = (dTime(v) < dTime(u)) ?FORWARD : CROSS;
                break;
        }
    }
    status(v) = VISITED;
    fTime(v) = ++clock; // 访问完毕
}


#endif //DATASTRUCTURES_GRAPH_H
