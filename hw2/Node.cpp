#include "Node.hpp"

Node::Node(int data = -10000, Node *prev = NULL, Node *next = NULL) {
    this->data = data;
    this->prev = prev;
    this->next = next;
}
int Node::getData() const { return data; }
int &Node::getData() { return data; }
Node *Node::getPrev() { return prev; }
Node *Node::getNext() { return next; }

void Node::setData(int data) { this->data = data; }
void Node::setPrev(Node *prev) { this->prev = prev; }
void Node::setNext(Node *next) { this->next = next; }
