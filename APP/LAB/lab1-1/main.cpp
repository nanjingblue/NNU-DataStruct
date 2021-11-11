#include <iostream>
#include "SeqList.h"

using namespace std;

const int MaxSize = 100;

void showMenu();
SeqList<int, MaxSize>  initSeqList();
SeqList<int, MaxSize*2> mergeList(SeqList<int, MaxSize> &list1, SeqList<int, MaxSize> &list2);

int main() {
    SeqList<int, MaxSize> list = initSeqList();
    cout << "顺序表的长度为：" << list.listLength() << endl;
    int choose = 1;
    int pos, item;
    while (choose != 0) {
        system("cls");
        showMenu();
        cin >> choose;
        switch (choose) {
            case 1: {
                cout << "顺序表的长度为：" << list.listLength() << endl;
                system("pause"); break;
            }
            case 2: {
                cout << "请输入 pos 值：";
                cin >> pos;
                cout << "第 " << pos << "位元素为：" << list.get(pos) << endl;
                system("pause"); break;
            }
            case 3:{
                cout << "请输入要查找的值：";
                cin >> item;
                cout << item << "的位置在：" << list.find(item) << endl;
                system("pause"); break;
            }
            case 4: {
                list.traserse();
                system("pause"); break;
            }
            case 5: {
                cout << "请输入要插入的元素："; cin >> item;
                cout << "请输入要插入的位置："; cin >> pos;
                list.insert(pos, item);
                system("pause"); break;
            }
            case 6: {
                cout << "请输入要删除元素的位置："; cin >> pos;
                list.Delete(pos);
                system("pause"); break;
            }
            case 7: {
                list.sort();
                system("pause"); break;
            }
            case 8: {
                SeqList<int, MaxSize> t = initSeqList();
                SeqList<int, MaxSize*2> newList = mergeList(list, t);
                cout << "合并后：";
                newList.traserse();
                system("pause"); break;
            }
        }
    }
    return 0;
}

void showMenu() {
    cout << "----------------------------" << endl;
    cout << "*****1. 获取顺序表长度*****" << endl;
    cout << "*****2. 获取第 pos 位元素****" << endl;
    cout << "*****3. 查找元素返回位置*****" << endl;
    cout << "*****4. 遍历*****" << endl;
    cout << "*****5. 插入元素******" << endl;
    cout << "*****6. 删除元素******" << endl;
    cout << "*****7. 排序******" << endl;
    cout << "*****8. 排序并合并*****" << endl;
    cout << "*****0.退出*****" << endl;
    cout << "----------------------------" << endl;
    cout << "请输入操作序号：";
}

SeqList<int, MaxSize>  initSeqList() {
    int len;
    int a[MaxSize] = {0};
    cout << "初始化顺序表：" << endl;
    cout << "请输入顺序表长度：";
    cin >> len;
    cout << "依次输入顺序表元素（空格相隔）：";
    for (int i = 0; i < len; ++i) {
        cin >> a[i];
    }
    SeqList<int, MaxSize> list(a, len);
    return list;
}

SeqList<int, MaxSize*2> mergeList(SeqList<int, MaxSize> &list1, SeqList<int, MaxSize> &list2) {
    cout << "Hello world" << endl;
    list1.sort();
    list2.sort();
    int a[MaxSize * 2] = {0};
    int i = 0, j = 0, k = 0;
    while (i < list1.listLength() && j < list2.listLength()) {
        if (list1[i] < list2[j]) {
            a[k++] = list1[i++];
        } else {
            a[k++] = list2[j++];
        }
    }
    if (i < list1.listLength()) {
        for (; i < list1.listLength(); ++i) {
            a[k++] = list1[i];
        }
    } else if (j < list2.listLength()) {
        for (; j < list2.listLength(); ++j) {
            a[k++] = list2[j];
        }
    }
    SeqList<int, MaxSize*2> list3(a, k);
    return list3;
}