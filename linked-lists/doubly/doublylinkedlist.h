#include "node.h"

#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

template<class T>
class DoublyLinkedList{
    public:
        Node<T> *head;
        Node<T> *tail;
        DoublyLinkedList(){
            head = NULL;
            tail = NULL;
        }
        ~DoublyLinkedList();
        void Insert(T data);
        void Delete(Node<T> *n);
        void Search(T data);
        void PrintList();
};

#endif