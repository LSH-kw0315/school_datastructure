#include "Dlink.hpp"
#include <iostream>
Dlink::Dlink() {
    head = NULL;
    tail = NULL;
}

void Dlink::head_insert(int data) {
    if (head == NULL) {
        head = new Node(data, NULL, NULL);
        tail = head;
    } else {
        head->setPrev(new Node(data, NULL, head));
        head = head->getPrev();
    }
}
void Dlink::tail_insert(int data) {
    if (tail == NULL) {
        head_insert(data);
        return;
    }
    tail->setNext(new Node(data, tail, NULL));
    tail = tail->getNext();
}
void Dlink::insert(int data, int pos) {
    if (pos < 0) {
        return;
    }
    Node *cur = head;
    for (int i = 0; i < pos; i++) {
        if (cur == NULL) {
            return;
        }
        cur = cur->getNext();
    }
    if (cur == tail) {
        tail_insert(data);
        return;
    }
    Node *next = cur->getNext();
    cur->setNext(new Node(data, cur, next));
    if (next != NULL) {
        next->setPrev(cur->getNext());
    }
}

void Dlink::head_remove() {
    if (head == NULL) {
        return;
    }
    Node *cur = head;
    head = head->getNext();
    if (head != NULL) {
        head->setPrev(NULL);
    }
    delete cur;
    cur = NULL;
}

void Dlink ::tail_remove() {
    if (tail == NULL) {
        return;
    }
    Node *cur = tail;
    tail = tail->getPrev();
    if (tail != NULL) {
        tail->setNext(NULL);
    }
    delete cur;
    cur = NULL;
}

void Dlink::remove(int pos) {
    if (pos < 0) {
        return;
    }
    Node *cur = head;
    for (int i = 0; i < pos; i++) {
        if (cur == NULL) {
            return;
        }
        cur = cur->getNext();
    }
    if (cur == head) {
        head_remove();
        return;
    } else if (cur == tail) {
        tail_remove();
        return;
    }
    Node *prev = cur->getPrev();
    Node *next = cur->getNext();
    if (prev != NULL) {
        prev->setNext(next);
    }
    if (next != NULL) {
        next->setPrev(prev);
    }
    cur->setNext(NULL);
    cur->setPrev(NULL);
    delete cur;
    cur = NULL;
}

void Dlink::clear() {
    while (head != NULL) {
        head_remove();
    }
}

void Dlink::swap(Dlink &src) {
    Node *copy_head = head;
    Node *copy_tail = tail;

    head = src.head;
    tail = src.tail;

    src.head = copy_head;
    src.tail = copy_tail;
}

int Dlink::size() {
    Node *cur;
    int res = 0;
    for (cur = head; cur != NULL; cur = cur->getNext()) {
        res++;
    }
    return res;
}

bool Dlink::empty() { return size() == 0; }
int &Dlink::front() {
    if (head != NULL) {
        return head->getData();
    }
}
int &Dlink::back() {
    if (tail != NULL) {
        return tail->getData();
    }
}

Node *Dlink::search(int pos) {
    if (pos < 0) {
        return NULL;
    }
    Node *cur = head;
    for (int i = 0; i < pos; i++) {
        cur = cur->getNext();
    }
    return cur;
}
