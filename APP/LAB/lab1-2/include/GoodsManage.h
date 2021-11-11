#ifndef DS_HW_2_GOODSMANAGE
#define DS_HW_2_GOODSMANAGE

#include <iostream>
#include <fstream>
#include <cassert>
#include "SeqList.h"
#include "Goods.h"

using namespace std;

const int MaxSize = 9999; // 能记录的最大商品数目
const std::string input  = "../goods.txt";
const std::string output = "../newgoods.txt";

class GoodsManage {
    SeqList<Goods> * gsList;
    void initList(const Goods * G, int len);
    void addGoods();
    void initGoodsFromFile(string fileName);
    void saveGoodsToFile(string fileName);
    static void showMenu();
    void editGoods();
public:
    GoodsManage() { gsList = nullptr;}
    ~GoodsManage() { delete []gsList; }
    void main();
};

void GoodsManage::main() {
    initGoodsFromFile(input);
    int choice = 1;
    while (choice != 0) {
        system("cls");
        showMenu();
        cin >> choice;
        switch (choice) {
            case 0: {
                cout << "程序已退出" << endl;
                system("pause"); break;
            }
            case 1: {
                cout << *gsList << endl;
                system("pause"); break;
            }
            case 2: {
                editGoods();
                cout << "修改成功" << endl;
                break;
            }
            case 3:{
                Goods G;
                cout << "请输入要删除的商品代号：";
                cin >> G.id;
                gsList->remove(G);
                cout << "删除成功" << endl;
                system("pause"); break;
            }
            case 4: {
                gsList->sort();
                cout << "排序成功" << endl;
                system("pause"); break;
            }
        }
        saveGoodsToFile(output);
    }
}

void GoodsManage::initList(const Goods * G, int len) {
    if (gsList != nullptr) {
        delete []gsList;
    }
    gsList = new SeqList<Goods>(G, len);
}

void GoodsManage::initGoodsFromFile(string fileName) {
    // 从文件中初始化商品目录
    Goods G[MaxSize];
    ifstream ifs(fileName, ios::in);
    assert(ifs);
    int len = 0;
    // while (ifs >> G[len++]);
    while ( ! ifs.eof() && len < MaxSize) {
        ifs >> G[len++];
    }
    ifs.close();    // 用完即关
    initList(G, len);
}

void GoodsManage::saveGoodsToFile(string fileName) {
    ofstream ofs(fileName, ios::out);
    assert(ofs);
    for (int i = 0; i < gsList->size(); i++) {
        ofs << (*gsList)[i].id << " " << (*gsList)[i].name << " " << (*gsList)[i].price << " " << (*gsList)[i].inventory << endl;
    }
    ofs.close();
}

void GoodsManage::addGoods() {
    Goods G;
    cout << "请依次空格相隔输入商品信息：代号 名称 价格 库存量：";
    cin >> G;
    gsList->insert(G);
}

void GoodsManage::showMenu() {
    cout << "------------商品管理系统-----------" << endl;
    cout << "******1. 打印库存表************" << endl;
    cout << "******2. 修改商品记录**********" << endl;
    cout << "******3. 删除记录**************" << endl;
    cout << "******4. 排序******************" << endl;
    cout << "******0. 退出并保存************" << endl;
    cout << "--------------------------------------" << endl;
    cout << "请输入操作指令: ";
}

void GoodsManage::editGoods() {
    Goods G;
    cout << "请输入商品代号：";
    cin >> G.id;
    if (gsList->isExist(G)) {
        int pos = gsList->search(G);
        cout << "请输入要修改的信息：库存量：";
        G = (*gsList)[pos];
        cin >> G.inventory;
        gsList->update(pos, G);
    } else {
        cout << "未找到商品，请添加一条新纪录：" << endl;
        addGoods();
    }
    system("pause");
}

#endif // DS_HW_2_GOODSMANAGE