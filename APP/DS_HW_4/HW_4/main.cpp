#include <iostream>
#include "LinkStack.h"
using namespace std;

template <typename T>
class Queue {
    LinkStack<T> stk1;
    LinkStack<T> stk2;
public:
    // 入队
    void push(T x) {
        stk1.Push(x);
    }
    // 出队
    T pop() {
        if ( ! stk2.Empty() ) {
            return stk2.Pop();
        } else {
            while ( !stk1.Empty() ) {
                stk2.Push(stk1.Pop());
            }
            return stk2.Pop();
        }
    }
};

int main(int argc, char const *argv[])
{
    Queue<int> queue;
    queue.push(10);
    cout << queue.pop() << endl;
    return 0;
}
