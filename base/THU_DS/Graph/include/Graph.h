//
// Created by cherry on 2021/11/23.
//

#ifndef DATASTRUCTURES_GRAPH_H
#define DATASTRUCTURES_GRAPH_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

typedef enum { UNDISCOVERED, DISCOVERED, VISITED} VStatus;  // ����״̬
typedef enum  { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD} EType;    // ���ڱ���������������

template <typename Tv, typename Te> // �������ͣ�������
class Graph { // ͼ Graph ģ����
private:
    void reset() {
        for (int i = 0; i < n; ++i) {
            status(i) = UNDISCOVERED; dTime(i) = fTime(i) = -1; // ״̬��ʱ���ǩ
            parent(i) = -1; priority(i) = INT_MAX;  // (�ڱ������еģ����ڵ㣬���ȼ���
            for (int j = 0; i < n; ++j) // ���бߵ�
                if (exists(i, j)) type(i, j) = UNDETERMINED;    // ����
        }
    }
    void BFS(int, int&);    // (��ͨ��) ������������㷨
    void DFS(int, int&);    // (��ͨ��) ��������㷨
    void BCC(int, int &, std::stack<int>&);     // (��ͨ��) ����DFS��˫��ͨ�����ֽ��㷨
    bool TSort ( int, int&, Stack<Tv>* ); //����ͨ�򣩻�ءDFS�m���������㷨
    template <typename PU> void PFS ( int, PU ); //����ͨ�����ȼ��������
public:
    // ����
    int n;
    virtual int insert ( Tv const& ) = 0; //���붥�� ���ر��
    virtual Tv remove ( int ) = 0;   //ɾ�����㼰������ߣ����ظö�����Ϣ
    virtual Tv& vertex ( int ) = 0; //����v�����ݣ��ö����ȷ���ڣ�
    virtual int inDegree ( int ) = 0; //����v�m��ȣ�ڹ����mȷ���ڣ�
    virtual int outDegree ( int ) = 0; //����v�m���ȣ�ڹ����mȷ���ڣ�
    virtual int firstNbr ( int ) = 0; //������׸��ڽӶ���
    virtual int nextNbr ( int, int ) = 0; //����v�ģ����ء����j�ģ���һ�ڽӶ���
    virtual VStatus& status ( int ) = 0; //����v��״̬
    virtual int& dTime ( int ) = 0; //����v�mʱ���ǩdTime
    virtual int& fTime ( int ) = 0; //����v�mʱ���ǩfTime
    virtual int& parent ( int ) = 0; //����v�ڱ������аm����
    virtual int& priority ( int ) = 0; //����v�ڱ������аm���ȼ���
    // �ߣ�����Լ��������߾�ͳһת��Ϊ������Ե�һ������ߣ��Ӷ�������ͼ��������ͼ�m����
    int e; //������
    virtual bool exists ( int, int ) = 0; //��(v, u)�Ƿ����
    virtual void insert ( Te const&, int, int, int ) = 0; //�ڶ���v��u�T��I��Ȩ��Ϊw�m��e
    virtual Te remove ( int, int ) = 0; //��������v��u�T��m��e��ކ��ڹ����Ϣ
    virtual EType& type ( int, int ) = 0; //��(v, u)�m����
    virtual Te& edge ( int, int ) = 0; //��(v, u)�m���ݣ�ڹ�߰mȷ���ڣ�
    virtual int& weight ( int, int ) = 0; //��(v, u)�mȨ��
    // �㷨
    void bfs ( int ); //������������㷨
    void dfs ( int ); //������������㷨
    void bcc ( int ); //��ءDFS�m˫��ͨ�����ֽ��㷨
    std::stack<Tv>* tSort ( int ); //��ءDFS�m���������㷨
    void prim ( int ); //��С֧����Prim�㷨
    void dijkstra ( int ); //���·��Dijkstra�㷨
    template <typename PU> void pfs ( int, PU ); //���ȼ��������
};

template<typename Tv, typename Te>
void Graph<Tv, Te>::bfs(int s) {
    reset(); int clock = 0; int v = s;  // ��ʼ��
    do {
        if (UNDISCOVERED == status(v)) {    // һ��������δ���ֵĶ���
            BFS(v, clock);  // ���Ӹö���������� BFS
        }
    } while (s != (v = (++v % n))); // ����ż�飬�ʲ�©����
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
                status(u) = DISCOVERED; // ���ָýڵ�
                Q.push(u);
                type(v, u) = TREE;  // ����������չ֧����
                parent(u) = v;
            } else {
                type(v, u) = CROSS; // ��(v, u) �����ڿ��
            }
        }
        status(v) = VISITED;    // ���� ��ǰ����������
    }
}

template<typename Tv, typename Te>
void Graph<Tv, Te>::dfs(int s) {
    reset(); int clock = 0; int v = s;  // ��ʼ��
    do {
        if (UNDISCOVERED == status(v)) {
            DFS(v, clock);
        }
    } while (s != (v = (++v % n))); // ����ż��
}

template<typename Tv, typename Te>
void Graph<Tv, Te>::DFS(int v, int& clock) {     //assert: 0 <= v < n
    dTime(v) = ++clock;
    status(v) = DISCOVERED; // ���ֵ�ǰ����
    for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {
        switch (status(u)) {
            case UNDISCOVERED:  // δ����
                type(v, u) = TREE;
                parent(u) = v;
                DFS(u, clock);
                break;
            case DISCOVERED:    // �ѷ��ֵ�Ϊ�������
                type(v, u) = BACKWARD;
                break;
            default:
                type(v, u) = (dTime(v) < dTime(u)) ?FORWARD : CROSS;
                break;
        }
    }
    status(v) = VISITED;
    fTime(v) = ++clock; // �������
}


#endif //DATASTRUCTURES_GRAPH_H
