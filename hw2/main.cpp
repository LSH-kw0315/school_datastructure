#include "Node.hpp"
#include "Queue.hpp"
#include <iostream>
using namespace std;
int main() {
    Queue q1;
    cout << "size of q1: " << q1.size() << endl;
    cout << "q1 is empty? : " << q1.empty() << endl << endl;
    ;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    cout << "after push" << endl << endl;
    cout << "size of q1:" << q1.size() << ", front():" << q1.front()
         << ", back():" << q1.back() << endl
         << endl;

    q1.pop();
    q1.pop();

    cout << "after pop" << endl << endl;
    cout << "size of q1:" << q1.size() << ", front():" << q1.front()
         << ", back():" << q1.back() << endl
         << endl;
    Queue q2;
    cout << "size of q2: " << q2.size() << endl;
    cout << "q2 is empty? : " << q2.empty() << endl << endl;
    ;

    q2.push(10);
    q2.push(20);
    q2.push(30);

    cout << "after push" << endl;
    cout << "size of q2:" << q2.size() << ", front():" << q2.front()
         << ", back():" << q2.back() << endl
         << endl;

    q1.swap(q2);

    cout << "after swap" << endl;
    cout << "size of q1:" << q1.size() << ", front():" << q1.front()
         << ", back():" << q1.back() << endl
         << endl;

    cout << "size of q2:" << q2.size() << ", front():" << q2.front()
         << ", back():" << q2.back() << endl
         << endl;

    q1.pop();
    q2.pop();

    cout << "after pop" << endl;
    cout << "size of q1:" << q1.size() << ", front():" << q1.front()
         << ", back():" << q1.back() << endl
         << endl;

    cout << "size of q2:" << q2.size() << ", front():" << q2.front()
         << ", back():" << q2.back() << endl
         << endl;

    return 0;
}
