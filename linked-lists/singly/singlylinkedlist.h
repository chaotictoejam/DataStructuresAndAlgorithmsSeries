#include "node.h"

#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

template<class T>
class SinglyLinkedList{
    public:
        Node<T> *head;
        Node<T> *tail;
        SinglyLinkedList(){
            head = NULL;
            tail = NULL;
        }
        ~SinglyLinkedList();
        void Insert(T data);
        void Delete(Node<T> *n);
        void Search(T data);
        void PrintList();
};

#endif