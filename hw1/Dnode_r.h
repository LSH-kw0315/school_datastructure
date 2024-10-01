#ifndef __DNODE__H__
#define __DNODE__H__
#include <cstdlib>

template<class T>
class Dnode{
    public:
        Dnode();
        //기본 생성자. 모든 값을 NULL로 초기화 한다.

        Dnode(T data,Dnode* nextlink,Dnode* prevlink);
        //매개변수 생성자. 데이터, next link , previous link 순서로 인자를 받는다 

        T getData() const;
        //T를 반환한다. 복사본을 반환한다.

        void setData(T input);
        //data를 를 바꾼다.

        Dnode* getNext();
        //다음 노드의 주소를 반환한다.
        const Dnode* getNext() const;
        //다음 노드의 주소를 반환한다. 이것으로 반환받은 주소로는 참조하는 곳의 데이터를 바꿀 수 없다.
        void setNext(Dnode* nextlink);
        //다음 노드의 주소를 변경한다.

        Dnode* getPrev();
        //이전 노드의 주소를 반환한다.
        const Dnode* getPrev() const;
        //이전 노드의 주소를 반환한다. 이것으로 반환받은 주소로는 참조받는 곳의 데이터를 바꿀 수 없다.
        void setPrev(Dnode* prevlink);
        //이전 노드의 주소를 변경한다.

    private:
        Dnode* next;
        Dnode* prev;
        T data;
};

template<class T>
Dnode<T>::Dnode(){
    next=NULL;
    prev=NULL;  
    data=NULL;
}

template<class T>
Dnode<T>::Dnode(T data,Dnode<T>* nextlink,Dnode<T>* prevlink){
    next=nextlink;
    prev=prevlink;
    this->data=data;
}

template<class T>
T Dnode<T>::getData() const{
    return data;
}

template<class T>
void Dnode<T>::setData(T input){
    data=input;
}

template<class T>
Dnode<T>* Dnode<T>::getNext(){
    return next;
}

template<class T>
const Dnode<T>* Dnode<T>::getNext() const{
    return next;   
}

template<class T>
void Dnode<T>::setNext(Dnode* nextlink){
    next=nextlink;
}

template<class T>
Dnode<T>* Dnode<T>::getPrev(){
    return prev;
}

template<class T>
const Dnode<T>* Dnode<T>::getPrev() const{
    return prev;
}

template<class T>
void Dnode<T>:: setPrev(Dnode* prevlink){
    prev=prevlink;
}

#endif