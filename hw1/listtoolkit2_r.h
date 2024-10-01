#ifndef __LISTTOOLKIT2__H__
#define __LISTTOOLKIT2__H__
#include "Dnode_r.h"
#include <cstdlib>
template<class T>
int list_length(const Dnode<T>*& head);
//리스트의 길이를 반환한다.

template<class T>
const Dnode<T>* list_search(const Dnode<T>*& head,const T data);
//data를 가진 node를 탐색한다. 있다면 그 노드를 반환하고, 없으면 NULL을 반환한다. 이것으로 반환 받은 node는 참조하는 곳의 데이터를 변경할 수 없다.

template<class T>
Dnode<T>* list_search(Dnode<T>*& head,const T data);
//data를 가진 node를 탐색한다. 있다면 그 노드를 반환하고, 없으면 NULL을 반환한다.

template<class T>
const Dnode<T>* list_locate(const Dnode<T>*& head,const int pos);
//list에 pos번 째에 있는 node를 반환한다. pos 위치에 node가 없으면 NULL을 반환한다.
//이것으로 반환받은 node는 참조하는 곳의 데이터를 변경할 수 없다.

template<class T>
Dnode<T> list_locate(Dnode<T>*& head,const int pos);
//list에 pos번 째에 있는 node를 반환한다. pos 위치에 node가 없으면 NULL을 반환한다.

template<class T>
void list_head_insert(Dnode<T>*& head,T data);
//head의 앞쪽에 새로운 노드를 추가한다.

template<class T>
void list_insert(Dnode<T>*& target,T data);
//target의 뒤쪽에 새로운 노드를 추가한다.

template<class T>
void list_head_remove(Dnode<T>*& head);
//head를 제거한다.

template<class T>
void list_remove(Dnode<T>*& target);
//target이 된 노드를 제거한다.

template<class T>
void list_clear(Dnode<T>*& head);
//list의 노드를 전부 제거한다.

template<class T>
void list_copy(Dnode<T>* src_head,Dnode<T>*& des_head,Dnode<T>*& des_tail);
//list를 deep copy하여 des_head가 src_head와 같아지도록 한다.


template<class T>
void list_copy(Dnode<T>* src_head,Dnode<T>*& des_head,Dnode<T>*& des_tail){
    if(src_head==NULL){
        return ;
    }
    des_head=NULL;
    des_tail=NULL;

    list_head_insert(des_head,src_head->getData());
    des_tail=des_head;
    src_head=src_head->getNext();

    while(src_head!=NULL){
        list_insert(des_tail,src_head->getData());
        des_tail=des_tail->getNext();
        src_head=src_head->getNext();
    }
}

template<class T>
void list_clear(Dnode<T>*& head){
    while(head!=NULL){
        list_head_remove(head);
    }
}

template<class T>
void list_remove(Dnode<T>*& target){
    if(target==NULL){
        return;
    }
    Dnode<T>* next=target->getNext();
    Dnode<T>* prev=target->getPrev();

    if(prev!=NULL){
        prev->setNext(next);
    }
    if(next!=NULL){
        next->setPrev(prev);
    }

    target->setNext(NULL);
    target->setPrev(NULL);
    delete target;
}

template<class T>
void list_head_remove(Dnode<T>*& head){
    if(head==NULL){
        return ;
    }
    Dnode<T>* tmp=head;
    head=head->getNext();
    if(head!=NULL){
        head->setPrev(NULL);
    }
    tmp->setNext(NULL);
    delete tmp;
}

template<class T>
void list_insert(Dnode<T>*& target,T data){
    if(target==NULL){
        return;
    }
    Dnode<T>* next=target->getNext();
    target->setNext(new Dnode<T>(data,target->getNext(),target));
    if(next!=NULL){
        next->setPrev(target->getNext());
    }
}

template<class T>
void list_head_insert(Dnode<T>*& head,T data){

    head=new Dnode<T>(data,head,NULL);
}

template<class T>
Dnode<T> list_locate(Dnode<T>*& head,const int pos){
    if(pos<=0){
        return NULL;
    }
    Dnode<T>* cur=head;
    int i;
    for(i=1;i<pos && cur!=NULL;i++){
        cur=cur->getNext();
    }
}

template<class T>
const Dnode<T>* list_locate(const Dnode<T>*& head,const int pos){
    if(pos<=0){
        return NULL;
    }
    const Dnode<T>* cur=head;
    int i;
    for(i=1;i<pos && cur!=NULL;i++){
        cur=cur->getNext();
    }
    return cur;
}

template<class T>
Dnode<T>* list_search(Dnode<T>*& head,const T data){
    Dnode<T>* cur=head;
    while(cur!=NULL){
        if(cur->getData()==data){
            return cur;
        }
        cur=cur->getNext();
    }
    return NULL;
}

template<class T>
const Dnode<T>* list_search(const Dnode<T>*& head,const T data){
    const Dnode<T>* cur=head;
    while(cur!=NULL){
        if(cur->getData()==data){
            return cur;
        }
        cur=cur->getNext();
    }
    return NULL;
}

template<class T>
int list_length(const Dnode<T>*& head){
    const Dnode<T>* cur;
    int cnt=0;
    for(cur=head;cur!=NULL;cur=cur->getNext()){
        cnt++;
    }
    return cnt;
}

#endif