//
// Created by cherry on 2021/9/11.
//
#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

typedef int Rank;
const int DEFAULT_CAPACITY = 3;

template<typename T>
class Vector {
protected:
    Rank _size{};
    int _capacity{};
    T * _elem;
    void copyFrom(T const * A, Rank lo, Rank hi);
    void expend();      // 扩容
    void shrink();      //  缩容
    void permute(Vector<T> & V);    // 随机置乱向量，各元素等概率出现于个位置
    static Rank binSearch(T * A, T const& e, Rank lo, Rank hi);
    void bubbleSort(Rank lo, Rank hi);
    bool bubble(Rank lo, Rank hi);
    void merge(Rank lo, Rank mi, Rank hi);
    void mergeSort(Rank lo, Rank hi);
public:
    // 构造函数
    explicit Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0);       // 容量为 c 规模为 s, 所有元素初始为 v
    Vector(T const * A, Rank n) { copyFrom(A, 0, n); }      // 数组整体复制
    Vector(T const * A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }      // 区间
    Vector(Vector<T> const & V) { copyFrom(V._elem, 0, V._size); }      // 向量整体复制
    Vector(Vector<T> const & V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); }        // 区间
    // 析构
    ~Vector();
    // 只读接口
    Rank size() const {return _size;}
    bool empty() const {return !_size;}
    int disordered() const;     //  判断是否有序
    Rank find(T const& e) const { return find(e, 0, _size); }
    Rank find(T const& e, Rank lo, Rank hi) const;
    Rank search(T const& e, Rank lo, Rank hi) const;
    // 可写接口
    void unsort(Rank lo, Rank hi);      // 等概率随机置乱区间[lo, hi)
    void unsort() { unsort(0, _size); }     // 整体置乱
    Rank insert(Rank r, T const& e);
    Rank insert(T const & e) {return insert(_size, e); }        // 默认尾插
    int remove(Rank lo, Rank hi);
    T remove(Rank r) {T e = _elem[r]; remove(r, r+1); return e; }       // 单元素删除 区间删除的特殊情况
    int deduplicate();      // 唯一化 去重
    int uniquify();     // 有序序列 唯一化
    // 重载
    Vector<T>& operator = (Vector<T> const & V);        // 重载 =
    T & operator[] (Rank r) const;     // 重载下标操作符
    // 遍历
    void traverse(void (*visit) (T&));
    template <typename VST> void traverse(VST& visit);
};

template<typename T>
void Vector<T>::copyFrom(const T *A, Rank lo, Rank hi) {
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while (lo < hi)
        _elem[_size++] = A[lo++];
}

template<typename T>
Vector<T>::Vector(int c, int s, T v) {
    _elem = new T[_capacity = c];
    for (_size = 0; _size < s; _elem[_size++] = v);
}

template<typename T>
Vector<T> &Vector<T>::operator = (const Vector<T> &V) {
    if (_elem)
        delete []_elem;
    copyFrom(V._elem, 0, V._size);
    return * this;
}

template<typename T>
Vector<T>::~Vector() {
    delete []_elem;
}

template<typename T>
void Vector<T>::expend() {
    if (_size < _capacity)
        return;
    if (_capacity < DEFAULT_CAPACITY) {
        _capacity = DEFAULT_CAPACITY;       // 不低于最小容量
    }
    T * oldElem = _elem;
    _elem = new T[_capacity << 1];      // 容量加倍
    for (int i = 0; i < _size; ++i) {
        _elem[i] = oldElem[i];
    }
    delete []oldElem;
}

template<typename T>
void Vector<T>::shrink() {
    if (_capacity < DEFAULT_CAPACITY << 1)
        return;
    if (_size << 2 > _capacity) {
        return;     // 以 25% 为界
    }
    T * oldElem = _elem;
    _elem = new T[_capacity >>= 1];     // 容量减半
    for (int i = 0; i < _size; ++i) {
        _elem[i] == oldElem[i];
    }
    delete []oldElem;
}

template<typename T>
T &Vector<T>::operator[](Rank r) const {
    return _elem[r];
}

template<typename T>
void Vector<T>::permute(Vector<T> &V) {
    for (int i = V.size(); i > 0; --i) {
        swap(V[i-1], V[rand() % i]);
    }
}

template<typename T>
void Vector<T>::unsort(Rank lo, Rank hi) {
    T * V = _elem + lo;     // 将指向量 _elem[lo, hi) 视作另一向量 V[0, hi - lo)
    permute(V);
}

template<typename T>
Rank Vector<T>::find(const T &e, Rank lo, Rank hi) const {
    while ((lo < hi--) && (e != _elem[hi]));        // 从后向前，顺序查找
    return hi;      // 若 hi < lo, 则意味着失败， 否则 hi 即命中元素的秩
}

template<typename T>
Rank Vector<T>::insert(Rank r, const T &e) {
    expend(); // 若有必要 扩容
    for (int i = _size; i > r; --i) {
        _elem[i] = _elem[i - 1];        // 从后向前，后继元素顺次后羿一个单元
    }
    _elem[r] = e;
    _size++;
    return r;       // 返回秩
}

template<typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
    if (lo == hi) {
        return 0;       // 出于效率考虑，单独处理退化情况，比如 remove(0, 0)
    }
    while (hi < _size) {
        _elem[lo++] = _elem[hi++];
    }
    _size = lo;
    shrink();       // 若有必要 缩容
    return hi - lo;
}

template<typename T>
int Vector<T>::deduplicate() {
    int oldSize = _size;
    Rank i = 1;
    while (i < _size) {
        (find(_elem[i], 0, i) < 0 ) ? i++ : remove(i);
    }
    return oldSize - _size;
}

template<typename T>
void Vector<T>::traverse(void (*visit)(T &)) {
    for (int i = 0; i < _size; ++i) {
        visit(_elem[i]);
    }
}

template<typename T> template <typename VST>
void Vector<T>::traverse(VST &visit) {
    for (int i = 0; i < _size; ++i) {
        visit(_elem[i]);
    }
}

template<typename T>
int Vector<T>::disordered() const {
    int n = 0; // 计数器
    for (int i = 1; i < _size; ++i) {
        if (_elem[i - 1] > _elem[i]) {
            n++;
        }
    }
    return n; // 返回逆序对数量
}

template<typename T>
int Vector<T>::uniquify() {
    Rank i = 0, j = 0;
    while (++j < _size) {
        if (_elem[i] != _elem[j]) {
            _elem[++i] = _elem[j];
        }
    }
    _size = ++i;
    shrink();       // 若需要 则缩容
    return j - i;
}

template<typename T>
Rank Vector<T>::search(const T &e, Rank lo, Rank hi) const {
    // 按各 50 % 的概率随机使用二分查找或者 Fibonacci 查找
    return (rand() % 2) ? binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);
}

template<typename T>
Rank Vector<T>::binSearch(T * A, T const& e, Rank lo, Rank hi) {
    while (lo < hi) {
        Rank mi = (lo + hi) >> 1;
        (e < A[mi]) ? hi = mi : lo = mi + 1;
    }
    return --lo; // 循环结束时，lo 为大于 e 元素的最小秩，故 lo - 1 即不大于 e 元素的最大秩
}   // 有多个命中元素，总能返回秩最大者，查找失败时能返回失败的位置。

template<typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {
    while ( !bubble(lo, hi--) );
}

template<typename T>
bool Vector<T>::bubble(Rank lo, Rank hi) {
    bool sorted = true;
    while (++lo < hi) {
        if (_elem[lo - 1] > _elem[lo]) {
            sorted = false;
            std::swap(_elem[lo - 1], _elem[lo]);
        }
    }
    return sorted;
}

template<typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {      // 各自有序的子向量 [lo,mi) 和 [mi, hi)
    T * A = _elem + lo;
    int lb = mi - lo;
    T * B = new T[lb];
    for (Rank i = 0; i < lb; B[i] = A[i++]);
    int lc = hi - mi;
    T * C = _elem + mi;
    for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);) {
        if ((j < lb) && (!(k < lc) || (B[j] <= C[k]))) A[i++] = B[j++];
        if ((k < lc) && (!(j < lb) || (C[k] < B[j])))  A[i++] = C[k++];
    }
    delete [] B;
}

template<typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi) {
    if (hi - lo < 2) {
        return;
    }
    int mi = (lo + hi) >> 1;
    mergeSort(lo, mi);
    mergeSort(mi, hi);  // 分别排序
    merge(lo, mi, hi);  // 归并
}

#endif //VECTOR_VECTOR_H
