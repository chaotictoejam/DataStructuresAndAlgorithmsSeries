#include <iostream>
#include "singlylinkedlist.h"

using namespace std;

template<class T>
SinglyLinkedList<T>:: ~SinglyLinkedList() {
    Node<T> *p;
    while(head != NULL) {
        p = head->next;
        delete head;
        head = p;
    }
}

/* This inserts new node at end of list:
First, a new node is initialized. The data member of the node is set and next member is null.
Then, the current tail is then updated to point to the new node
If the list is initially empty, both head and tail would be set to point to the new node 
Time complexity of this is O(1) as it does constant amount of work.
*/
template<class T>
void SinglyLinkedList<T>:: Insert(T data) {
    Node<T> *n = new Node<T>(data);
    if(tail != NULL){
        tail->next = n;
        tail = tail->next;
    } else {
        head = n;
        tail = n;
    }
}

// Time complexity of DeleteNode() is O(n)
template<class T>
void SinglyLinkedList<T>:: Delete(Node<T> *nodeToDelete){
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
        } else {
            //If more than one node in the list find the predecessor
            Node<T> *pred = head;
            
            // Walk through the list to find the node before the tail
            while(pred->next != nodeToDelete) {
                pred = pred->next;
            }
            pred->next = nodeToDelete->next;
        }

        // Deallocate memory
        delete nodeToDelete;
    }
}

/* Searches for the first instance of data in the list, 
If it is in the list it outprints the index otherwise it outprints -1
Time complexity of Search() isO(n) 
*/
template<class T>
void SinglyLinkedList<T>:: Search(T data){
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
void SinglyLinkedList<T>:: PrintList(){
    Node<T> *p = head;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template class SinglyLinkedList<int>;