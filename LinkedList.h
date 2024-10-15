#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template <typename T>
class Node{
    public:
    T element;
    Node* next;
    Node* prev;
};

template <typename T>
class List{
    private:
        Node<T> *head;
        Node<T> *tail;
    public:
    List(){
        head = NULL;
        tail = NULL;
    }
    ~List(){
        makeEmpty();
    }


    void insert(const T& data, Node<T>* p){
        if(p != NULL){
            Node<T>* newNode = new Node<T>(data, p->next);
            p->next = newNode;
        }
        else{
            Node<T>* newNode = new Node<T>(data, head);
            head = newNode;
        }
    }

    Node<T>* find(const T& data){
        Node<T>* p = first();
        while(p!= NULL){
            if(p->element == data){
                return p;
            p = p->next;
            }
        return NULL;
        }
    }

    Node<T>* findPrevious(const T& data){
        Node<T>* p = zeroth();

        while(p->next){
            if(p->next->element == data){
                return p;
            }
        p = p->next;
        }
        return NULL;
    }
    void remove(const T& data){
        Node<T>* p = findPrevious(data);

        if(p != NULL){
            Node<T>* tmp = p->next;
            p->next = tmp->next;
            delete tmp;
        }
    }

    bool isEmpty(){
        return first() == NULL;
    }
    
    void makeEmpty(){
        while(!isEmpty()){
            remove(first()->element());
        }

    }
};

#endif