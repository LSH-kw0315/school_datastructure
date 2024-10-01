#ifndef __DLIST_H__
#define __DLIST_H__
#include "Dlink.hpp"
#include "Node.hpp"
#include <cstdlib>
class Queue {
  private:
    Dlink list;

  public:
    Queue();
    const int &front() { return list.front(); };
    const int &back() { return list.back(); };
    bool empty();
    int size();
    void pop();
    void push(const int &val);
    void swap(Queue &src);
};
#endif
