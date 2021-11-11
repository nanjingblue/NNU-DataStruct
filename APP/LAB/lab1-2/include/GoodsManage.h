#ifndef DS_HW_2_GOODSMANAGE
#define DS_HW_2_GOODSMANAGE

#include <iostream>
#include <fstream>
#include <cassert>
#include "SeqList.h"
#include "Goods.h"

using namespace std;

const int MaxSize = 9999; // �ܼ�¼�������Ʒ��Ŀ
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
                cout << "�������˳�" << endl;
                system("pause"); break;
            }
            case 1: {
                cout << *gsList << endl;
                system("pause"); break;
            }
            case 2: {
                editGoods();
                cout << "�޸ĳɹ�" << endl;
                break;
            }
            case 3:{
                Goods G;
                cout << "������Ҫɾ������Ʒ���ţ�";
                cin >> G.id;
                gsList->remove(G);
                cout << "ɾ���ɹ�" << endl;
                system("pause"); break;
            }
            case 4: {
                gsList->sort();
                cout << "����ɹ�" << endl;
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
    // ���ļ��г�ʼ����ƷĿ¼
    Goods G[MaxSize];
    ifstream ifs(fileName, ios::in);
    assert(ifs);
    int len = 0;
    // while (ifs >> G[len++]);
    while ( ! ifs.eof() && len < MaxSize) {
        ifs >> G[len++];
    }
    ifs.close();    // ���꼴��
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
    cout << "�����οո����������Ʒ��Ϣ������ ���� �۸� �������";
    cin >> G;
    gsList->insert(G);
}

void GoodsManage::showMenu() {
    cout << "------------��Ʒ����ϵͳ-----------" << endl;
    cout << "******1. ��ӡ����************" << endl;
    cout << "******2. �޸���Ʒ��¼**********" << endl;
    cout << "******3. ɾ����¼**************" << endl;
    cout << "******4. ����******************" << endl;
    cout << "******0. �˳�������************" << endl;
    cout << "--------------------------------------" << endl;
    cout << "���������ָ��: ";
}

void GoodsManage::editGoods() {
    Goods G;
    cout << "��������Ʒ���ţ�";
    cin >> G.id;
    if (gsList->isExist(G)) {
        int pos = gsList->search(G);
        cout << "������Ҫ�޸ĵ���Ϣ���������";
        G = (*gsList)[pos];
        cin >> G.inventory;
        gsList->update(pos, G);
    } else {
        cout << "δ�ҵ���Ʒ�������һ���¼�¼��" << endl;
        addGoods();
    }
    system("pause");
}

#endif // DS_HW_2_GOODSMANAGE