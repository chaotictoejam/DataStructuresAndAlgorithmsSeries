// A simple C++ program that uses vectors to implement a stack
// To run:
//    g++ -o stackvector stackvector.cpp (this commmand compiles the code)
//    ./stackvector (this runs the file we declared as the output)
#ifndef STACK
#define STACK

#include <vector>
#include <iostream>
using namespace std;

template <class T, int capacity = 30>
class Stack
{
private:
    vector<T> v; // Vectors are sequence containers representing arrays that can change in size

public:
    Stack()
    {
        v.reserve(capacity); // Requests that the vector capacity be at least enough to contain n elements.
    }
    void clear()
    {
        v.clear();
    }
    bool isEmpty() const
    {
        return v.empty();
    }
    void push(const T &el)
    {
        v.push_back(el); // Adds a new element at the end of the vector, after its current last element.
    }
    T pop()
    {
        T el = v.back();
        v.pop_back(); // Removes the last element in the vector, effectively reducing the container size by one.
        return el;
    }
    T &peek()
    {
        return v.back(); // Returns a reference to the last element in the vector.
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