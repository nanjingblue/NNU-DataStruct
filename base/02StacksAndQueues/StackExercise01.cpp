#include <iostream>

using namespace std;

template<class T, int MAXSIZE>
class StackArray {
public:
    T data[MAXSIZE];
};

int top1;
int top2;
const int MaxSize = 100;
StackArray<int, MaxSize> say;

template<class T>
class SharedStack1 {
public:
    SharedStack1() {
        top1 = -1;
    }
    void push_back(T x) {
        if(top1 + 1 == top2) {
            cerr << "����" << endl;
            exit(1);
        }
        say.data[top1++] = x;
    }
    void pop() {
        if(top1 == 0) {
            cerr << "����" << endl;
        }
        say.data[top1--] = 0;
    }
};

template<class T>
class SharedStack2 {
public:
    SharedStack2() {
        top2 = MaxSize - top2 - 1;
    }
    void push_back(T x) {
        if(top2 - 1 == top1) {
            cerr << "����" << endl;
            exit(1);
        }
        say.data[top2--] = x;
    }
    void pop() {
        if(top2 == MaxSize-1) {
            cerr << "����" << endl;
        }
        say.data[top2++] = 0;
    }
};

void showMenu() {
    cout << "1. sstk1 ��ջ" << endl;
    cout << "2. sstk1 ��ջ" << endl;
    cout << "3. sstk2 ��ջ" << endl;
    cout << "4. sstk2 ��ջ" << endl;
    cout << "0. �˳�" << endl;
}

int main() {
    SharedStack1<int> sstk1;
    SharedStack2<int> sstk2;
    int choose;
    int val;
    while (true) {
        system("cls");
        showMenu();
        cin >> choose;
        switch (choose) {
            case 1:
                cout << "��������ջ��ֵ: ";
                cin >> val;
                sstk1.push_back(val);
                break;
            case 2:
                sstk1.pop();
                break;
            case 3:
                cout << "��������ջ��ֵ";
                cin >> val;
                sstk2.push_back(val);
                break;
            case 4:
                sstk2.pop();
                break;
            case 0:
                exit(1);
        }
    }
    return 0;
}