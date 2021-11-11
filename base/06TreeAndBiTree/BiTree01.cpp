//
// Created by cherry on 2021/8/23.
//
#include <iostream>
#include <vector>
#include "LinkBiTree.h"

using namespace std;

int main() {
    vector<char> v1;
    v1.push_back('a');
    v1.push_back('b');
    v1.push_back('*');
    v1.push_back('*');
    v1.push_back('c');
    v1.push_back('*');
    v1.push_back('*');
    BiTree<char> bit(v1);
    bit.preOrder();
    cout << endl;
    return 0;
}