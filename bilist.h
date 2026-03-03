#ifndef BILIST_H
#define BILIST_H

#include <cstddef>
#include <iostream>

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
BiList<T>* pop_front(BiList<T>* head, BiList<T>*& tail) {
    if (head == nullptr) {
        return nullptr;
    }
    
    BiList<T>* newHead = head->next;
    
    if (newHead != nullptr) {
        newHead->prev = nullptr;
    } else {
        tail = nullptr;
    }
    
    delete head;
    return newHead;
}

template< class T >
BiList<T>* pop_back(BiList<T>* head, BiList<T>*& tail) {
    if (tail == nullptr) {
        return nullptr;
    }
    
    BiList<T>* newTail = tail->prev;
    
    if (newTail != nullptr) {
        newTail->next = nullptr;
    } else {
        head = nullptr;
    }
    
    delete tail;
    return head;
}

template< class T >
BiList<T>* push_front(BiList<T>* head, BiList<T>*& tail, const T& value) {
    BiList<T>* newNode = create_node(value);
    
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    
    return head;
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

template< class T >
void print(const BiList<T>* head) {
    const BiList<T>* current = head;
    
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << " <-> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

template< class T >
BiList<T>* array_to_list(const T* arr, size_t size, BiList<T>*& tail) {
    BiList<T>* head = nullptr;
    tail = nullptr;
    
    for (size_t i = 0; i < size; ++i) {
        head = push_back(head, tail, arr[i]);
    }
    
    return head;
}

template< class T >
void clear(BiList<T>* head) {
    while (head != nullptr) {
        BiList<T>* next = head->next;
        delete head;
        head = next;
    }
}

#endif