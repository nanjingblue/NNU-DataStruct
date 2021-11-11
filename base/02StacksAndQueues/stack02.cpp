//
// Created by cherry on 2021/8/11.
//

#include <iostream>
#include "LinkStack.h"

int main() {
    LinkStack<int> linkStack;
    linkStack.Push(1314);
    cout << linkStack.Top() << endl;
    cout << linkStack.Empty() << endl;
    cout << linkStack.Pop() << endl;
    cout << linkStack.Top() << endl;
    return 0;
}

