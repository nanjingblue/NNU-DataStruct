#include <iostream>
#include "gen_render.h"
#include "sort.h"

using namespace std;

const int len = 10;

int main() {
    std::cout << "Hello, World!" << std::endl;
    int a[1000];
    getRanderArray(a, len);
    cout << "----------ֱ�Ӳ�������-----------" << endl;
    insertSort(a, len);
    for (int i = 0; i < len; ++i) {
        cout << a[i] << " ";
    }
    cout << endl << "----------�۰��������-----------" << endl;
    binInsertSort(a, len);
    for (int i = 0; i < len; ++i) {
        cout << a[i] << " ";
    }
    cout << endl << "----------ð������-----------" << endl;
    bubbleSort(a, len);
    for (int i = 0; i < len; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}
