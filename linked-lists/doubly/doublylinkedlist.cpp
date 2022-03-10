#include <iostream>
#include "doublylinkedlist.h"

using namespace std;

template<class T>
DoublyLinkedList<T>:: ~DoublyLinkedList() {
    Node<T> *p;
    while(head != NULL) {
        p = head->next;
        delete head;
        head = p;
    }
}

// O(1)
template<class T>
void DoublyLinkedList<T>:: Insert(T data) {
    Node<T> *n = new Node<T>(data);
    if(tail == NULL) {
        // List is empty
        head = n;
        tail = n;
    } else {
        n->prev = tail;
        tail->next = n;
        tail = tail->next;
    }
}

// O(1)
template<class T>
void DoublyLinkedList<T>:: Delete(Node<T> *nodeToDelete){
    if(head == NULL) {
        printf("List is empty!");
    } else {
        if(head == tail && head == nodeToDelete) {
            // Only one element in the list
            delete head;
            head = NULL;
            tail = NULL;
        } else if(head == nodeToDelete) {
            //If more than one node in the list, and node to delete is head
            head = head->next;
            head->prev = NULL;
        } else {
            nodeToDelete->prev->next = nodeToDelete->next;

            if(nodeToDelete->next != NULL) {
                nodeToDelete->next->prev = nodeToDelete->prev;
            }
        }

        // Deallocate memory
        delete nodeToDelete;
    }
}

// O(n)
template<class T>
void DoublyLinkedList<T>:: Search(T data){
    Node<T> *p = head;
    int counter = 0;
    while(p != NULL) {
        if(p->data == data) {
            break;
        }
        counter++;
        p = p->next;
    }
    if(p == NULL){
        cout << -1 << endl;
    }else {
        cout << counter << endl;
    }
} 

// Prints contents of this list
template<class T>
void DoublyLinkedList<T>:: PrintList(){
    Node<T> *p = head;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template class DoublyLinkedList<int>;