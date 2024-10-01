#ifndef __DLINK_H__
#define __DLINK_H__
#include "Node.hpp"

class Dlink {
  private:
    Node *head;
    Node *tail;

  public:
    Dlink();
    void head_insert(int data);
    void tail_insert(int data);
    void insert(int data, int pos);
    void head_remove();
    void tail_remove();
    void remove(int pos);
    void clear();
    void swap(Dlink &src);
    Node *search(int data);
    bool empty();
    int size();
    int& front();
    int& back();
};
#endif
