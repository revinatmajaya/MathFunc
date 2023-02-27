#include "./headers/linkedList.h"

template<typename T> Node<T>::Node(T value){
    this->next = nullptr;
    this->prev = nullptr;
    this->value = value;
}


template<typename T> List<T>::List(){
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename T> List<T>::List(Node<T>* node){
    this->head = node;
    this->tail = node;
}

template<typename T> void List<T>::add(T value){
    Node<T>* curr = this->head;
    if (curr == nullptr){
        this->head = new Node(value);
        this->tail = this->head;
    } else{
        while(curr->next){
            curr = curr->next;
        }
        curr->next = new Node(value);
        curr->next->prev = curr;
        this->tail = curr->next;
    }
}

template<typename T> void List<T>::print(){
    Node<T>* curr = this->head;
    while(curr){
        std::cout << curr->value << std::endl;
        curr = curr->next;
    }
}