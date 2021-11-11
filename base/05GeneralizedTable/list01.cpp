//
// Created by cherry on 2021/8/21.
//
#include <iostream>
#include "GList.h"
using namespace std;

int main() {
    GList<char> gl1("(a, b, c)");
    gl1.Traverse();
    cout << gl1.Length() << endl;
    cout << gl1.Depth() << endl;

    GList<char> gl2("(a, (a, b, c), b, (b, c), c)");
    gl2.Traverse();
    cout << gl2.Length() << endl;
    cout << gl2.Depth() << endl;

    GList<char> gl3("(a, (a, (a, (a))))");
    gl3.Traverse();
    cout <<gl3.Length() << endl;
    cout << gl3.Depth() << endl;
    gl3.Replace('a', 'b');
    gl3.Traverse();

    gl1.Traverse();
    gl1.Delete('a');
    gl1.Traverse();

    return 0;
}
