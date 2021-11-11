#include <iostream>
#include "g_list.h"

using namespace std;

int main() {
    GList<int> gList1("(a, b)");
    GList<int> gList2("(a)");

    GList<int> gList4("(a, ())");
    GList<int> gList3("(a, (a, (), (a)), b)");

    cout << gList1.isSame(gList2) << endl;
    return 0;
}
