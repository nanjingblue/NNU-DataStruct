//
// Created by cherry on 2021/9/4.
//
#include <iostream>
#include <assert.h>

#include "TreeCreator.h"

using namespace std;

int main() {
    std::cout << "---------------HUFFMAN�ļ�ѹ������-------------------------" << std::endl;
    std::cout << "�������ļ�����";
    char fileName[] = "../images/xst.png";
    // std::cin >> fileName;
    treeCreator::initHuffmanTree(fileName);
    return 0;
}