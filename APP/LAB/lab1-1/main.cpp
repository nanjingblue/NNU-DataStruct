#include <iostream>
#include "SeqList.h"

using namespace std;

const int MaxSize = 100;

void showMenu();
SeqList<int, MaxSize>  initSeqList();
SeqList<int, MaxSize*2> mergeList(SeqList<int, MaxSize> &list1, SeqList<int, MaxSize> &list2);

int main() {
    SeqList<int, MaxSize> list = initSeqList();
    cout << "˳���ĳ���Ϊ��" << list.listLength() << endl;
    int choose = 1;
    int pos, item;
    while (choose != 0) {
        system("cls");
        showMenu();
        cin >> choose;
        switch (choose) {
            case 1: {
                cout << "˳���ĳ���Ϊ��" << list.listLength() << endl;
                system("pause"); break;
            }
            case 2: {
                cout << "������ pos ֵ��";
                cin >> pos;
                cout << "�� " << pos << "λԪ��Ϊ��" << list.get(pos) << endl;
                system("pause"); break;
            }
            case 3:{
                cout << "������Ҫ���ҵ�ֵ��";
                cin >> item;
                cout << item << "��λ���ڣ�" << list.find(item) << endl;
                system("pause"); break;
            }
            case 4: {
                list.traserse();
                system("pause"); break;
            }
            case 5: {
                cout << "������Ҫ�����Ԫ�أ�"; cin >> item;
                cout << "������Ҫ�����λ�ã�"; cin >> pos;
                list.insert(pos, item);
                system("pause"); break;
            }
            case 6: {
                cout << "������Ҫɾ��Ԫ�ص�λ�ã�"; cin >> pos;
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
                cout << "�ϲ���";
                newList.traserse();
                system("pause"); break;
            }
        }
    }
    return 0;
}

void showMenu() {
    cout << "----------------------------" << endl;
    cout << "*****1. ��ȡ˳�����*****" << endl;
    cout << "*****2. ��ȡ�� pos λԪ��****" << endl;
    cout << "*****3. ����Ԫ�ط���λ��*****" << endl;
    cout << "*****4. ����*****" << endl;
    cout << "*****5. ����Ԫ��******" << endl;
    cout << "*****6. ɾ��Ԫ��******" << endl;
    cout << "*****7. ����******" << endl;
    cout << "*****8. ���򲢺ϲ�*****" << endl;
    cout << "*****0.�˳�*****" << endl;
    cout << "----------------------------" << endl;
    cout << "�����������ţ�";
}

SeqList<int, MaxSize>  initSeqList() {
    int len;
    int a[MaxSize] = {0};
    cout << "��ʼ��˳���" << endl;
    cout << "������˳����ȣ�";
    cin >> len;
    cout << "��������˳���Ԫ�أ��ո��������";
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