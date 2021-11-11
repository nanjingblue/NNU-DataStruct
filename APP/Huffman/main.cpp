//
// Created by cherry on 2021/9/4.
//
#include <iostream>
#include <assert.h>

#include "TreeCreator.h"

using namespace std;

int main() {
    std::cout << "---------------HUFFMAN文件压缩编码-------------------------" << std::endl;
    std::cout << "请输入文件名：";
    char fileName[] = "../images/xst.png";
    // std::cin >> fileName;
    treeCreator::initHuffmanTree(fileName);
    return 0;
}