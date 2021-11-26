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
    Tv data; int inDegree, outDegree; VStatus status; // ���� ������� ״̬
    int dTime, fTime;   // ʱ���ǩ
    int parent; int priority;   // �ڱ������еĸ���� ���ȼ���
    explicit Vertex(Tv const& d = (Tv) 0) : data(d), inDegree(0), outDegree(0), status(UNDISCOVERED),
    dTime(-1), fTime(-1), parent(-1), priority(INT_MAX) {}  // �ݲ�����Ȩ�����
};

template <typename Te>
struct Edge {
    Te data; int weight; EType type;    // ���� Ȩ�� ����
    Edge(Te const& d, int w) : data(d), weight(w), type(UNDETERMINED) {}
};

template <typename Tv, typename Te> // �������ͣ�������
class GraphMatrix : public Graph<Tv, Te> {
private:
    std::vector<Vertex<Tv>> V; // ���㼯(����)
    std::vector< std::vector<Edge<Te> *> > E;   // �߼����ڽӾ���
public:
    GraphMatrix() { n = e = 0; }    // ����
    ~GraphMatrix() {
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                delete E[j][k];
    }
    // ����Ļ�������
    virtual Tv& vertex(int i) { return V[i].data; } // ����
    virtual int inDegree(int i) { return V[i].inDegree;}    // ���
    virtual int outDegree(int i) { return  V[i].outDegree; }    // ����
    virtual int firstNbr(int i) { return nextNbr(i, n); }   // �׸��ڽӶ���
    virtual int nextNbr(int i, int j) {     // ����ڶ��� j ����һ���ڽӶ���(�����ڽӱ�����Ч��
        while ((-1 < j) && (!exists(i, --j))); return j;    // ����������̽
    }
    virtual VStatus& status ( int i ) { return V[i].status; } //״̬
    virtual int& dTime ( int i ) { return V[i].dTime; } //ʱ���ǩdTime
    virtual int& fTime ( int i ) { return V[i].fTime; } //ʱ���ǩfTime
    virtual int& parent ( int i ) { return V[i].parent; } //�ڱ������аm����
    virtual int& priority ( int i ) { return V[i].priority; } //�ڱ������аm���ȼ���
    // ����Ķ�̬����
    virtual int insert(Tv const& vertex);  // ���붥�㷵�ر��
    virtual Tv remove(int i);  // ɾ���� i �����㼰�������
    // �ߵ�ȷ�ϲ���
    virtual bool exists(int i, int j);  // �� (i, j)�Ƿ����
    // �ߵĻ������� ��ѯ���� i �� j ֮������ߣ�0 <= i, j < n �� exists(i, j) ��
    virtual EType& type(int i, int j) { return E[i][j]->type; } // ��(i, j)������
    virtual Te& edge(int i, int j) { return E[i][j]->data; }    // ��(i, j)������
    virtual int& weight(int i, int j) { return E[i][j]->weight; }       // ��(i, j) ��Ȩ��
    // �ߵĶ�̬����
    virtual void insert(Te const& edge, int w, int i, int j);   // ����Ȩ��Ϊ w �ı� e = (i, j)
    virtual Te remove(int i, int j);    // ɾ������ i �� j ֮�������
};

template<typename Tv, typename Te>
Tv GraphMatrix<Tv, Te>::remove(int i) {
    for (int j = 0; j < n; ++j) {
        if (exists(i, j)) {
            delete E[i][j]; V[j].inDegree--;
        }  // ����ɾ��
    }
    E.erase(i); --n;
    Tv vBak = vertex(i); V.erase(i);    // ɾ������ i
    for (int j = 0; j < n; ++j) {
        if (Edge<Te> * e = E[j][i]) {
            E[j].erase(i);
            delete e;
            V[j].outDegree--;   // ����ɾ��
        }
    }
    return vBak;    // ���ر�ɾ���������Ϣ
}

template<typename Tv, typename Te>
bool GraphMatrix<Tv, Te>::exists(int i, int j) {
    return (0 <= i) && (i < n) && (0 <= j) && (j < n) && E[i][j] != nullptr;
}

template<typename Tv, typename Te>
int GraphMatrix<Tv, Te>::insert(const Tv &vertex) {
    for (int j = 0; j < n; ++j) E[j].insert(nullptr); ++n;  // ������Ԥ��һ��Ǳ�ڵĹ�����
    E.insert(std::vector<Edge<Te> *> (n, n, (Edge<Te> *) nullptr)); // �����¶����Ӧ�ı�����
    return V.insert(Vertex<Tv> (vertex));   // ������������һ������
}

template<typename Tv, typename Te>
void GraphMatrix<Tv, Te>::insert(const Te& edge, int w, int i, int j) {
    if (exists(i, j)) return;   // ȷ���ñ߲�����
    E[i][j] = new Edge<Te>(edge, w);    // �����±�
    e++;
    V[i].outDegree++;
    V[j].inDegree++;    // ���±߼���������������
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
