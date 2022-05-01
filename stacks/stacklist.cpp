// A simple C++ program that uses a doubly linked list to implement a stack
// To run:
//    g++ -o stacklist stacklist.cpp (this commmand compiles the code)
//    ./stacklist (this runs the file we declared as the output)
#ifndef STACK
#define STACK

#include <list>
#include <iostream>
using namespace std;

template <class T>
class Stack
{
    private:
        list<T> lst;

    public:
        Stack()
        {
        }
        void clear()
        {
            lst.clear();
        }
        bool isEmpty() const
        {
            return lst.empty();
        }
        void push(const T &el)
        {
            lst.push_back(el); // Adds a new element at the end of list
        }
        T pop()
        {
            T el = lst.back();
            lst.pop_back(); // Removes the last element in the list,
            return el;
        }
        T& peek()
        {
            return lst.back(); // Returns a reference to the last element in the list.
        }
};

#endif

int main()
{
    Stack<int> s;

    cout << s.isEmpty() << endl; // 1
    s.push(5);
    cout << s.isEmpty() << endl; // 0
    cout << s.peek() << endl;    // 5
    s.push(10);
    cout << s.peek() << endl; // 10
    cout << s.pop() << endl;  // 10
    cout << s.peek() << endl; // 5
}