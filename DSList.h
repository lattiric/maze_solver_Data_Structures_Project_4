//
// Created by Rick Lattin on 3/25/21.
//

#ifndef PA04_AMAZING_DSLIST_H
#define PA04_AMAZING_DSLIST_H

#include <iostream>

template <class T>
struct node{
    T data;
    node *next;
    node *prev;
};

template <class T>
class DSList{
    private:
        node<T> *head;
        node<T> *tail;
        node<T> *itr;
        int size;

    public:
        DSList();
        DSList(DSList&);
        ~DSList();
        DSList& operator= (DSList&);
        void addNode(T);
        void removeNode(T);
        node<T>* getTail();
        node<T>* getHead();
        int getSize();
        bool isEmpty();
        void deleteNode(node<T>*);

        void intIterator();     //iterator functions
        void moveItr();
        void resetItr();
        node<T>* getItr();
};
//https://www.youtube.com/watch?v=P_F-oEeBT8k
//https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/

template <class T>
DSList<T>::DSList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
DSList<T>::DSList(DSList& curr){
    head = nullptr;
    tail = nullptr;
    size = 0;

    if(curr.getHead()== nullptr)
        return;

    node<T>* n = curr.getHead();
    while(n != nullptr){
        addNode(n->data);
        if(n->next)
            n = n->next;
        else
            n = nullptr;
    }

}

template <class T>
DSList<T>::~DSList(){
   while(size > 0){
       deleteNode(head);
   }
}

template <class T>
DSList<T>& DSList<T>::operator=(DSList<T>& old) {
    head = old.getHead();
    tail = old.getTail();
    size = old.getSize();

    return* this;
}

template <class T>
void DSList<T>::addNode(T nData) {
    node<T>* n = new node<T>;
    n->data = nData;
    n->next = nullptr;

    n->prev = tail;
    if(n->prev)
        n->prev->next = n;
    tail = n;

    if(head == nullptr)
        head = n;

    size++;
}

template <class T>
void DSList<T>::removeNode(T dat) {
    node<T>* currNode = head;
    node<T>* badNode = nullptr;

    for(int i = 0; i<size; i++){
        if(currNode->data == dat)
            badNode = currNode;
        else{
            currNode = currNode->next;
        }
    }

    if(badNode == nullptr){
        std::cout<<"Remove didn't find anything"<<std::endl;
        return;
    }
    else{
        deleteNode(badNode);
    }
}

template <class T>
node<T>* DSList<T>::getTail() {
    return tail;
}

template <class T>
node<T>* DSList<T>::getHead() {
    return head;
}

template <class T>
int DSList<T>::getSize(){
    return size;
}

template <class T>
bool DSList<T>::isEmpty() {
    if(head == nullptr && tail == nullptr)
        return true;
    else
        return false;
}

template <class T>
void DSList<T>::deleteNode(node<T>* curNode) {
    if(curNode != nullptr) {
        if (curNode->next)
            curNode->next->prev = curNode->prev;
        if (curNode->prev)
            curNode->prev->next = curNode->next;
        if (head == curNode)
            head = curNode->next;
        if (tail == curNode)
            tail = curNode->prev;
    }
    size--;
}

template <class T>
void DSList<T>::intIterator() {
    itr = head;
}

template <class T>
void DSList<T>::moveItr() {
    itr = itr->next;
}

template <class T>
void DSList<T>::resetItr() {
    itr = head;
}

template <class T>
node<T>* DSList<T>::getItr() {
    return itr;
}

#endif //PA04_AMAZING_DSLIST_H
