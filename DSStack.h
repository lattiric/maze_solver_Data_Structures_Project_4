//
// Created by Rick Lattin on 3/26/21.
//

#ifndef PA04_AMAZING_DSSTACK_H
#define PA04_AMAZING_DSSTACK_H

#include "DSVector.h"
#include "DSList.h"

template <class T>
class DSStack{
    private:
        DSList<T> linList;
    public:
        DSStack();
        void push(T);
        T pop();
        T peek();
        bool isEmpty();
        bool contains(T);
};

template <class T>
DSStack<T>::DSStack(){

};

template <class T>
void DSStack<T>::push(T item){
//    stack.insert(item);
    linList.addNode(item);
};

template <class T>
T DSStack<T>::pop(){
            T bad = linList.getTail()->data;
            //linList.removeNode(bad);
            linList.deleteNode(linList.getTail());
            return bad;
};

template <class T>
//T* DSStack<T>::peek(){
T DSStack<T>::peek(){
        return linList.getTail()->data;
};

template <class T>
bool DSStack<T>::isEmpty(){
    if(linList.isEmpty())
        return true;
    return false;
};

template <class T>
bool DSStack<T>::contains(T val) {
    linList.intIterator();
    bool answer = false;
    for(int i = 0; i<linList.getSize(); i++){
        if(linList.getItr()->data == val) {
            answer = true;
            i = linList.getSize();
        }
        else {
            answer = false;
        }
        linList.moveItr();
    }
    return answer;
}

#endif //PA04_AMAZING_DSSTACK_H
