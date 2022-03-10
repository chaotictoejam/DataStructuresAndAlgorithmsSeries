#ifndef NODE
#define NODE
  
template<class T>
struct Node { 
public: 
    T data; 
    Node* next; //By having a reference to itself this is an example of an self-referential object
    Node* prev;
    Node(){
        next = NULL;
        prev = NULL;
    }
    //Constructor defaults next to NULL if not passed
    //Constructor defaults prev to NULL if not passed
    Node(T d, Node *n = NULL, Node *p = NULL){
        data = d;
        next = n;
        prev = p;
    }
}; 

#endif