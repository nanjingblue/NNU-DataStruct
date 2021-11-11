#ifndef DS_HW_2_SEQLIST_H
#define DS_HW_2_SEQLIST_H

#include <iostream>

const int DEFAULT_CAPACITY = 9999;

template<typename T>
class SeqList {
protected:
    T *data;
    int length;
    int capacity;
    void copyForm(T const * A, int lo, int hi);
    void quickSort(T * A, int lo, int hi);
    void traverse(T const * A, int lo, int hi);
    int search(T const * A, const T& item);
    void update(T const * A, int index, const T& item);
    void remove(T const * A, const T& item);
public:
// 构造
    SeqList(int c = DEFAULT_CAPACITY, int len = 0, T v = 0) {
        data = new T[capacity = c];
        for (length = 0; length < len; data[length++] = v);
    }
    SeqList(T const *A, int n) { copyForm(A, 0, n); }
    SeqList(SeqList<T> & v) { copyForm(v.data, 0, v.length); }
// 析构
    ~SeqList() { delete []data; }
// 可读
    int size();     // 返回顺序表长度
    void traverse() { traverse(data, 0, length); }      // 遍历接口
    int search(const T& item) { return search(data, item); }
    bool isExist(const T& item) { return (search(data, item) == -1) ? false : true; }     // 存在接口
// 可写
    void sort() { quickSort(data, 0, length - 1); }       // 排序接口
    void insert(int index, const T & temp);     // 位置插入
    void insert(const T& temp) { insert(length, temp); }     // 默认尾插
    void update(int index, const T& temp) { update(data, index, temp); }
    void remove(const T& temp) { remove(data, temp); }       // 删除接口
// 重载
    T operator[](int index) const;                                        // 重载 []
    SeqList<T>& operator=(SeqList<T>& temp);      // 重载 =
    friend std::ostream& operator<<(std::ostream &os, SeqList<T> &temp) {       // 重载流输出
        os << "[ ";
        for (int i = 0; i < temp.size() - 1; ++i) {
            os << temp[i] << ", ";
        }
        os << temp[temp.size() - 1] << " ]" << std::endl;
        return os;
    }
};

template<typename T>
void SeqList<T>::copyForm(T const * A, int lo, int hi) {
    data = new T[2 * (hi - lo)];
    length = 0;
    while (lo < hi) {
        data[length++] = A[lo++];
    }
}

template<typename T>
void SeqList<T>::quickSort(T * A, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    T x = A[(lo + hi) >> 1];
    int i = lo - 1, j = hi + 1;
    while (i < j) {
        do i++; while (x > data[i]);
        do j--; while (x < data[j]);
        if (i < j) {
            std::swap(data[i], data[j]);
        }
    }
    quickSort(A, lo, j);
    quickSort(A, j + 1, hi);
}

template<typename T>
int SeqList<T>::size() {
    return length;
}

template<typename T>
void SeqList<T>::traverse(T const * A, int lo, int hi) {
    std::cout << "[ ";
    while (lo < hi - 1) {
        std::cout << data[lo++] << ", ";
    }
    std::cout << data[hi-1] << " ]" << std::endl;
}

template<typename T>
int SeqList<T>::search(T const * A, const T& item) {
    for (int i = 0; i < length; ++i) {
        if (data[i] == item) {
            return i;
        }
    }
    return -1;
}

template<typename T>
void SeqList<T>::insert(int index, const T& temp) {
    for (int i = length; i > index; --i) {
        data[i + 1] = data[i];
    }
    data[index] = temp;
    length++;
}

template<typename T>
T SeqList<T>::operator[](int index) const {
    return data[index];
}

template<typename T>
SeqList<T>& SeqList<T>::operator= (SeqList<T>& temp) {
    if (this != &temp) {
        delete[] data;
    } else {
        return *this;
    }
    copyForm(temp.data, 0, temp.size());
    return *this;
}

template<typename T>
void SeqList<T>::update(const T * A, int index, const T& item) {
    data[index] = item;
}

template<typename T>
void SeqList<T>::remove(const T * A, const T& item) {
    int index = 0;
    for (int i = 0; i < length; ++i) {
        if (data[i] == item) {
            continue;
        }
        data[index++] = data[i];
    }
    length = index;
}

#endif //DS_HW_2_SEQLIST_H