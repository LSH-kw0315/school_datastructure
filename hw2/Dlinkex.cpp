#include "Dlink.hpp"
#include <iostream>
using namespace std;

int main() {
    Dlink list1;
    cout << "size of list1: " << list1.size()
         << ",list1 is empty? : " << list1.empty() << endl
         << endl;
    list1.head_insert(0);
    list1.head_insert(1);
    list1.head_insert(2);
    cout << "after head insert" << endl;
    cout << "list1 size: " << list1.size()
         << ", list1 front(): " << list1.front()
         << ", list1 back():" << list1.back() << endl
         << endl;
    ;

    list1.tail_insert(3);
    list1.tail_insert(4);

    cout << "after tail insert" << endl;
    cout << "list1 size: " << list1.size()
         << ", list1 front(): " << list1.front()
         << ", list1 back():" << list1.back() << endl
         << endl;
    ;

    list1.head_remove();
    list1.tail_remove();
    cout << "after tail insert" << endl;
    cout << "list1 size: " << list1.size()
         << ", list1 front(): " << list1.front()
         << ", list1 back():" << list1.back() << endl
         << endl;

    Dlink list2;

    cout << "size of list2: " << list2.size()
         << ",list2 is empty? : " << list2.empty() << endl;

    list2.tail_insert(100);
    list2.tail_insert(200);
    list2.tail_insert(300);
    list2.tail_insert(400);
    cout << "after tail insert" << endl;
    cout << "list2 size: " << list2.size()
         << ", list2 front(): " << list2.front()
         << ", list2 back():" << list2.back() << endl
         << endl;

    list1.swap(list2);

    cout << "after swap" << endl;
    cout << "list1 size: " << list1.size()
         << ", list1 front(): " << list1.front()
         << ", list1 back():" << list1.back() << endl
         << endl;
    cout << "list2 size: " << list2.size()
         << ", list2 front(): " << list2.front()
         << ", list2 back():" << list2.back() << endl
         << endl;

    list1.insert(-100, 2);
    list1.insert(-200, 1);
    list2.insert(-1000, 2);
    list2.insert(-2000, 1);
    cout << "after insert" << endl;
    cout << "list1 size: " << list1.size()
         << ", list1 front(): " << list1.front()
         << ", list1 back():" << list1.back() << endl
         << endl;
    cout << "list2 size: " << list2.size()
         << ", list2 front(): " << list2.front()
         << ", list2 back():" << list2.back() << endl
         << endl;
    list1.remove(1);
    list1.remove(2);

    list2.remove(1);
    list2.remove(2);
    cout << "after remove" << endl;
    cout << "list1 size: " << list1.size()
         << ", list1 front(): " << list1.front()
         << ", list1 back():" << list1.back() << endl
         << endl;
    cout << "list2 size: " << list2.size()
         << ", list2 front(): " << list2.front()
         << ", list2 back():" << list2.back() << endl
         << endl;

    Node *c1 = list1.search(-200);
    Node *c2 = list2.search(-200);
    if (c1 != NULL && c2 != NULL) {
        cout << "after search" << endl;
        cout << "c1 : " << c1->getData() << ", c2 :" << c2->getData() << endl
             << endl;
    }

    list1.clear();

    cout << "after clear" << endl;
    cout << "list1 size: " << list1.size()
         << ", list is empty?: " << list1.empty() << endl;

    return 0;
}
