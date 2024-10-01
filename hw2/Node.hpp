#ifndef __NODE_H__
#define __NODE_H__
#include <cstdlib>
class Node {
  private:
    int data;
    Node *prev;
    Node *next;

  public:
    Node(int data, Node *prev, Node *next);
    int getData() const;
    int &getData();
    Node *getPrev();
    Node *getNext();

    void setData(int data);
    void setPrev(Node *prev);
    void setNext(Node *next);
};
#endif
