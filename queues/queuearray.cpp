// A simple C++ program that implements a queue using an array
// To run:
//    g++ -o queue queuearray.cpp (this commmand compiles the code)
//    ./queue (this runs the file we declared as the output)
#include <iostream>
using namespace std;

template<class T, int size = 5>
class Queue {
    private:
        int first, last; // Markers for the first and last item in the queue
        T storage[size]; // Initialize the array to store type T elements in the Array
    public:
        Queue() {
            first = last = -1; // The queue is initially empty so set first and last to -1
        }
        void clear() {
            first = last = -1; // Set first and last to -1 to "clear" the queue
        }
        bool isEmpty() {
            return first == -1;
        }
        bool isFull() {
            // The queue is full if the first item is first in the array and last is last item
            // or the first item is next to the last item (circular array)
            return ((first == 0 && last == size-1) || first == last + 1);
        }
        void enqueue(T el);
        T dequeue();
        T firstEl();
};

template<class T, int size>
void Queue<T, size>::enqueue(T el) {
    // Check to make sure queue is not full
    if(!isFull())
    { 
        // If the array is empty add el to the first item in the list
        if(isEmpty()){
            first = last = 0;
            storage[0] = el;
        } else if(last == size-1){ // If last is the last item in the array add el to the first item in the list
            last = 0;
            storage[0] = el;
        }
        else
        {
            storage[++last] = el;
        }
    }
    else
    {
        cout << "Queue is full!" << endl;
    }
}

template <class T, int size>
T Queue<T, size>::dequeue(){
    T dequeuedItem = storage[first];
    // If only one item in the queue
    if(first == last) {
        // Make queue empty
        first = last = -1;
    }
    else if (first == size - 1) { // If first is at the end of the array
        first = 0;
    }
    else {
        first++;
    }
    return dequeuedItem;
}

template <class T, int size>
T Queue<T, size>::firstEl() {
    return storage[first];
}

int main() {
    Queue<int> queue;

    cout << queue.isEmpty() << endl; // 1
    queue.enqueue(1);
    cout << queue.isEmpty() << endl; // 0
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6); // Queue is full!
    cout << queue.dequeue() << endl; // 1
    cout << queue.firstEl() << endl; // 2
    queue.clear();
    cout << queue.isEmpty() << endl; // 1
}