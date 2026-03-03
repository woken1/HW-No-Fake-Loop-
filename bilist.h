#ifndef BILIST_H
#define BILIST_H

#include <cstddef>

template< class T >
struct BiList {
    T data;
    BiList<T>* next;
    BiList<T>* prev;
};

template< class T >
BiList<T>* create_node(const T& value) {
    BiList<T>* node = new BiList<T>;
    node->data = value;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}

template< class T >
BiList<T>* push_back(BiList<T>* head, BiList<T>*& tail, const T& value) {
    BiList<T>* newNode = create_node(value);
    
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    
    return head;
}

#endif