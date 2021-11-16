//
// Created by 20190408 ZuoShi Hia on 2021/9/14.
//

#ifndef DS_HW_2_SEQLIST_H
#define DS_HW_2_SEQLIST_H
#include <iostream>

template<class T, int MaxSize>
class SeqList {
    T data[MaxSize];
    int length;
    void quickSort(int lo, int hi);
public:
    SeqList() { length = 0; }
    SeqList(T a[], int n);
    int listLength();
    T get(int pos);
    int find(T item);
    void traserse();
    void insert(int pos, T item);
    T Delete(int pos);
    void sort() { quickSort(0, length - 1); }
    T operator[](int pos) const;
    
    T delMin();
    void delAllX(T x);
    void delByRange(T s, T t);
    int find(const T& e, int lo, int hi);
    void remove(int i);
    void deduplicate();
    void insertOrder(const T& e);
};

template<class T, int MaxSize>
SeqList<T, MaxSize>::SeqList(T a[], int n) {
    if (n > MaxSize) {
        std::cerr << "参数非法";
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        data[i] = a[i];
    }
    length = n;
}

template<class T, int MaxSize>
int SeqList<T, MaxSize>::listLength() {
    return length;
}

template<class T, int MaxSize>
T SeqList<T, MaxSize>::get(int pos) {
    if (pos < 1 || pos > MaxSize) {
        std::cerr << "查找位置非法";
        exit(1);
    }
    return data[pos - 1];
}

template<class T, int MaxSize>
int SeqList<T, MaxSize>::find(T item) {
    for (int i = 0; i < length; ++i) {
        if (data[i] == item) {
            return i + 1;
        }
    }
    return 0;
}

template<class T, int MaxSize>
void SeqList<T, MaxSize>::traserse() {
    std::cout << "[ ";
    for (int i = 0; i < length - 1; ++i) {
        std::cout << data[i] << ", ";
    }
    std::cout << data[length - 1] << " ]" << std::endl;
}

template<class T, int MaxSize>
void SeqList<T, MaxSize>::insert(int pos, T item) {
    if (length >= MaxSize) {
        std::cerr << "上溢出";
        exit(1);
    }
    if (pos < 1 || pos > length + 1) {
        std::cerr << "插入位置非法";
        exit(1);
    }
    for (int i = length - 1; i >= pos - 1; --i) {
        data[i+1] = data[i];
    }
    data[pos - 1] = item;
    length++;
}

template<class T, int MaxSize>
T SeqList<T, MaxSize>::Delete(int pos) {
    if (length == 0) {
        std::cerr << "下溢";
        exit(1);
    }
    if (pos < 1 || pos > length) {
        std::cerr << "删除位置非法";
        exit(1);
    }
    T x = data[pos - 1];
    for (int i = pos; i < length; ++i) {
        data[i - 1] = data[i];
    }
    length--;
    return x;
}

template<class T, int MaxSize>
void SeqList<T, MaxSize>::quickSort(int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    int x = data[(lo + hi) >> 1];
    int i = lo - 1, j = hi + 1;
    while (i < j) {
        do i++; while (data[i] < x);
        do j--; while (data[j] > x);
        if (i < j) {
            std::swap(data[i], data[j]);
        }
    }
    quickSort(lo, j);
    quickSort(j + 1,hi);
}

template<class T, int MaxSize>
T SeqList<T, MaxSize>::operator[](int pos) const {
    return data[pos];
}

template<class T, int MaxSize>
T SeqList<T, MaxSize>::delMin() {
    if (length < 1) {
        std::cerr << "顺序表为空";
        exit(1);
    }
    T min = data[0];
    int pos = 0;
    for (int i = 1; i < length; ++i) {
        if (data[i] < min) {
            min = data[i];
            pos = i;
        }
    }
    data[pos] = data[length - 1];
    length--;
    return min;
}

template<class T, int MaxSize>
void SeqList<T, MaxSize>::delAllX(T x) {
    int index = 0;
    for (int i = 0; i < length; ++i) {
        if (data[i] != x) {
            data[index++] = data[i];
        }
    }
    length = index;
}

template<class T, int MaxSize>
void SeqList<T, MaxSize>::delByRange(T s, T t) {
    int index = 0;
    for (int i = 0; i < length; ++i) {
        if(data[i] <= s || data[i] >= t) {
            data[index++] = data[i];
        }
    }
    length = index;
}

template<class T, int MaxSize>
int SeqList<T, MaxSize>::find(const T& e, int lo, int hi) {
    // 从后向前找
    while ((lo < hi--) && (e != data[hi]));
    return hi;
}

template<class T, int MaxSize>
void SeqList<T, MaxSize>::remove(int i) {
    int j = i + 1;
    while (j < length) {
        data[i++] = data[j++];
    }
    length = i;
}

template<class T, int MaxSize>
void SeqList<T, MaxSize>::deduplicate() {
    int index = 1;
    while (index < length) {
        (find(data[index], 0, index) < 0) ? index++ : remove(index);
    }
}

template<class T, int MaxSize>
void SeqList<T, MaxSize>::insertOrder(const T& e) {
    int lo = 0, hi = length - 1, mid = 0;
    T x = data[(lo + hi) >> 1];
    while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if (e > data[mid]) {
            lo = mid + 1;
        } else if (e < data[mid]) {
            hi = mid - 1;
        } else {
            break;
        }
    }
    std::cout << mid << std::endl;
    for (int i = length; i >= mid; --i) {
        data[i + 1] = data[i];
    }
    data[mid] = e;
    length++;
}



#endif //DS_HW_2_SEQLIST_H
