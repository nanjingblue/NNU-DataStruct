//
// Created by cherry on 2021/8/20.
// 稀疏矩阵的压缩储存 三元组实现
#include <iostream>
#include <vector>
using namespace std;

template<class T>
struct Triple {
    int r, c;
    T elem;
};

template<class T>
class SparseMatrix {
    vector< Triple<T> > triList;
    int rows, cols, num;        // 矩阵的行数列数和非零元素个数
public:
    SparseMatrix();
    SparseMatrix(Triple<T> *tlist, int rs, int cs, int n);
    void plainTrans(SparseMatrix &B);
    void quickTrans(SparseMatrix &B);
};

template<class T>
SparseMatrix<T>::SparseMatrix() {
    this->rows = 0;
    this->cols = 0;
    this->num = 0;
}

template<class T>
SparseMatrix<T>::SparseMatrix(Triple<T> *tlist, int rs, int cs, int n) {
    this->rows = rs;
    this->cols = cs;
    this->num = n;
    this->triList = tlist;
}

template<class T>
void SparseMatrix<T>::plainTrans(SparseMatrix &B) {
    B.rows = cols;
    B.clos = rows;
    B.num = num;
    B.triList.resize(num); // resize(n) 用于改变容器大小并创建对象。调用此函数后，就可以引用容器内的对象了
    if(num == 0) {
        return;
    }
    int q = 0;
    for(int col=0; col < cols; ++col) {     // 按矩阵 A 的列序转置
        for(int p=0; p<num; ++p) {
            if(triList[p].c == col) {
                B.triList[q].r = triList[q].c;
                B.triList[q].c = triList[q].r;
                B.triList[q].elem = triList[q].elem;
                ++q;
            }
        }
    }
}

template<class T>
void SparseMatrix<T>::quickTrans(SparseMatrix &B) {
    B.rows = cols;
    B.clos = rows;
    B.num = num;
    if(num == 0) return;
    int *cnum = new int[cols];
    int *cpot = new int[cols];
    for(int col=0; col < cols; ++ col) cnum[col] = 0;
    for(int t=0; t < num; ++t) ++cnum[triList[t].c];
    cpot[0] = 0;
    for(int col=1; col < cols; ++col) {
        cpot[col] = cpot[col-1] + cnum[col-1];
    }
    for(int p=0; p < num; ++p) {
        int col = triList[p].c;
        int q = cpot[col];
        B.triList[q].r = triList[q].c;
        B.triList[q].c = triList[q].r;
        B.triList[q].elem = triList[q].elem;
        ++cpot[col];
    }
    delete []cnum;
    delete []cpot;
}

int main() {

    return 0;
}

