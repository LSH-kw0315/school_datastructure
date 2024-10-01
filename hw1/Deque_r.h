#ifndef __DEQUE__H__
#define __DEQUE__H__
#include "Dnode_r.h"
#include <cstdlib>
template <class T>
class Deque;
template <class T>
class Deque{    
    public:
        Deque();
        //디폴트 생성자. front와 rear을 NULL로 한다.

        Deque(const Deque<T>& src);
        //복사 생성자

        ~Deque();
        //소멸자

        Deque& operator=(const Deque<T>& src);
        //할당 연산자 오버로딩

        int size();
        //deque의 크기를 반환한다

        bool isempty();
        //deque가 비어있는지 참거짓으로 반환한다.

        void front_push(const T& entry);
        //front에 push한다

        T front_pop();
        //front에서 pop한다

        void rear_push(const T& entry);
        //rear에서 push한다

        T rear_pop();
        //rear에서 pop한다

        T front() const;
        //front의 data를 반환한다. 

        T rear() const;
        //rear의 data를 반환한다.


        Dnode<T>*& getFront();
        //front_ptr의 레퍼런스를 반환한다. front가 가리키는 곳을 바꿀 수도 있게 된다.

        Dnode<T>*& getRear();
        //rear_ptr의 레퍼런스를 반환한다. rear가 가리키는 곳을 바꿀 수도 있게 된다.


    private:
        Dnode<T>* front_ptr;
        Dnode<T>* rear_ptr;

};

template<class T>
Deque<T>::Deque(){
    front_ptr=NULL;
    rear_ptr=NULL;
}

template<class T>
Deque<T>::Deque(const Deque<T>& src){
    Dnode<T>*& src_front=src->getFront();
    list_copy(src_front,front_ptr,rear_ptr);
}

template<class T>
Deque<T>::~Deque(){
    list_clear(front_ptr);
}

template<class T>
Deque<T>& Deque<T>::operator=(const Deque<T>& src){
    if(this==&src){
        return *this;
    }
    list_clear(front_ptr);
    Dnode<T>*& src_front=src->getFront();
    list_copy(src_front,front_ptr,rear_ptr);
}

template<class T>
int Deque<T>::size(){
    const Dnode<T>* con_front=front_ptr;
    return list_length(con_front);
}

template<class T>
bool Deque<T>::isempty(){
    int length=size();
    return length==0;
}

template<class T>
void Deque<T>::front_push(const T& entry){
    if(front_ptr==NULL){
        list_head_insert(front_ptr,entry);
        rear_ptr=front_ptr;
    }else{
        list_head_insert(front_ptr,entry);
    }
}

template<class T>
T Deque<T>::front_pop(){
    if(isempty()){
        return NULL;
    }
    T res=front();
    list_head_remove(front_ptr);
    if(front_ptr==NULL){
        rear_ptr=front_ptr;
    }
    return res;
}

template<class T>
void Deque<T>::rear_push(const T& entry){
    if(rear_ptr==NULL){
        list_head_insert(front_ptr,entry);
        rear_ptr=front_ptr;
    }else{
        list_insert(rear_ptr,entry);
        rear_ptr=rear_ptr->getNext();
    }
}

template<class T>
T Deque<T>::rear_pop(){
    if(isempty()){
        return NULL;
    }
    T res=rear();
    Dnode<T>* prev=rear_ptr->getPrev();
    list_remove(rear_ptr);
    rear_ptr=prev;
    if(rear_ptr==NULL){
        front_ptr=NULL;
    }
    return res;
}

template<class T>
T Deque<T>::front() const{
    return front_ptr->getData();
}

template<class T>
T Deque<T>::rear() const{
    return rear_ptr->getData();
}

template<class T>
Dnode<T>*& Deque<T>::getFront(){
    return front_ptr;
}

template<class T>
Dnode<T>*& Deque<T>::getRear(){
    return rear_ptr;
}
#endif