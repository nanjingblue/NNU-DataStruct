/*
 *  created by 20190408左士海  on 2021/09/27
 *  请确保编译环境支持 C++11
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <ctime>
using namespace std;

struct node {
    int x;
    int y;
};

int t, len, flag;
char str[10050];
// int 为序列中满足要求的十进制数，vector存其对应的索引 同值可能存在多个位置不同的序列
// 虽然题目要求只输出一组 但这里都存了
unordered_map< long long, vector<node> > hashTable;

// 获取满足长度要求的二进制转十进制
void getTen(char * str) {
    int m = len / 2;
    for (int k = len; k >= m; k--) {
        long long  num = 0;
        int j = 0;
        for (int i = k; i >= 1; i--) {
            num += (str[i] == '0') ? 0 : pow(2, j);
//            num += (str[i] - '0') * pow(2, j);
            node temp = {i, i + j};
            j++;
            if (j >= m)
                hashTable[num].push_back(temp);
        }

    }
}

int main() {
    cin >> t;
    clock_t startTime,endTime;
    startTime = clock();//计时开始
    while (t--) {
        hashTable.clear();
        flag = 0;
        cin >> len;
        for (int i = 1; i <= len; ++i) {
            cin >> str[i];
        }
        getTen(str);
//        for (auto &x: hashTable) {
//            cout << x.first << " ";
//            for (auto it = x.second.begin(); it < x.second.end(); ++it) {
//                cout << it->x << " " << it->y << endl;
//            }
//            cout << endl;
//        }
        for (auto& x: hashTable) {
            int num = x.first;
            if (hashTable[num].size() > 1) {
                cout << hashTable[num][0].x << " " << hashTable[num][0].y << " " << hashTable[num][1].x << " " << hashTable[num][1].y << endl;
                break;      // 序列中可能存在同值当不同位置的子串 即 k = 1，首先判断，存在就直接输出
            }
            // 对因子查哈希表
            for (int i = 1; i <= sqrt(num); i++) {  // 这里 i = 1, 代表 k = 1
                if (num % i == 0) {
                    auto it = hashTable.find(i);
                    if (it != hashTable.end()) {
                        cout << hashTable[num][0].x << " " << hashTable[num][0].y << " " << hashTable[i][0].x << " " << hashTable[i][0].y << endl;
                        flag = 1;
                        break;  // 查到即退
                    }
                }
            }
            if (flag == 1) break;
        }
    }
    endTime = clock();
    cout << "run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" <<endl;
    return 0;
}