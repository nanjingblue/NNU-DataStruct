#include <iostream>
#include "LinkList.h"
using namespace std;

void showMenu();

int main(int argc, char const *argv[])
{
    cout << "hello world" << endl;
    return 0;
}

void showMenu() {
    cout << "-----LinkList功能测试-----" << endl;
    cout << "-----1. 构造----------------" << endl;
    cout << "-----2. 长度----------------" << endl;
    cout << "-----3. 获取第pos个元素---" << endl;
    cout << "-----4. 查找元素-----------" << endl;
    cout << "-----5. 遍历----------------" << endl;
    cout << "-----6. 插入----------------" << endl;
    cout << "-----7. 删除----------------" << endl;
    cout << "-----8. 逆置----------------" << endl;
    cout << "-----9. 排序----------------" << endl;
    cout << "-----10. 合并单链表--------" << endl;
    cout << "-----0. 退出----------------" << endl;
}

template<typename T>
LinkList<T> creatList() {
    cout << "请输入表长度: ";
    int len;
    cin >> len; 
    
}


