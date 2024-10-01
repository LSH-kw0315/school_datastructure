#include "Queue.hpp"

Queue::Queue() { list; }
bool Queue::empty() { return list.size() == 0; }
int Queue::size() { return list.size(); }
void Queue::pop() { list.head_remove(); }

void Queue::push(const int &val) { list.tail_insert(val); }

void Queue::swap(Queue &src) {
    Dlink tmp = list;
    list = src.list;
    src.list = tmp;
}
