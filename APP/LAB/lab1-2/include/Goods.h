#ifndef DS_HW_2_GOODS
#define DS_HW_2_GOODS

#include <iostream>
#include <string>

typedef unsigned pri;

class Goods {
public:
    std::string id;      // 代号
    std::string name;    // 名称
    pri price;  // 价格
    unsigned inventory;  // 库存
public:
    Goods(std::string d = "", std::string na = "", pri pri = 0, unsigned tory = 0) {
        id = d; name = na; price = pri; inventory = tory;
    }
    Goods(const Goods & temp) {
        id = temp.id; name = temp.name; price = temp.price; inventory =temp.inventory;
    }
    Goods& operator=(const Goods& temp) {
        id = temp.id; name = temp.name; price = temp.price; inventory = temp.inventory;
        return *this;
    }
    bool operator==(const Goods& temp) {
        return (id == temp.id) ? true : false;
    }
    bool operator<(const Goods& temp) {
        return (id < temp.id) ? true : false;
    }
    bool operator>(const Goods& temp) {
        return (id > temp.id) ? true : false;
    }
    friend std::ostream& operator<<(std::ostream& os, const Goods & temp) {
        os << "{ " << "id: " << temp.id << ", name: " << temp.name << ", price: " << temp.price << ", inventory: " << temp.inventory << " }";
        return os;
    }
    friend std::istream& operator>>(std::istream &is, Goods & temp) {
        is >> temp.id >> temp.name >>temp.price >> temp.inventory;
        return is;
    }
};

#endif // DS_HW_2_GOODS