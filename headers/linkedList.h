// linkedList.cpp header file
#include <iostream>

template<typename T> class Node {
    public:
    Node<T>* next;
    Node<T>* prev;
    T value;

    Node(T value);
};

// this is a basic templated linked list, nothing special:/
template<typename T> class List {
    public:
    Node<T>* head;
    Node<T>* tail;

    List(Node<T>* node);
    void add(T value);
    void print();

};
