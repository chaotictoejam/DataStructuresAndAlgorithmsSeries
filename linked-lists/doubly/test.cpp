// A simple C++ program to illustrate doubly linked lists
// To run: 
//    make -f MakeFile
//    ./main

#include <iostream>
#include "doublylinkedlist.h"

using namespace std;

int main() {
    DoublyLinkedList<int> list;

    cout << (list.head == NULL) << endl;

    list.Insert(1);

    cout << (list.head == NULL) << endl;
    
    list.Insert(2);

    list.PrintList();
    
    list.Insert(3);
    
    list.PrintList();

    list.Search(2);

    list.Delete(list.head->next);
    
    list.PrintList();
    
    list.Search(2);
}

template class DoublyLinkedList<int>;
