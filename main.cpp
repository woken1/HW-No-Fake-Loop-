#include "bilist.h"
#include <iostream>

int main() {
    char arr[] = {'A', 'B', 'C', 'D'};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);
    
    BiList<char>* head = nullptr;
    BiList<char>* tail = nullptr;
    
    std::cout << "Массив: ";
    for (size_t i = 0; i < arr_size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    head = array_to_list(arr, arr_size, tail);
    
    std::cout << "Список: ";
    print(head);
    std::cout << "Размер: " << size(head) << std::endl;
    
    std::cout << "Обратный: ";
    BiList<char>* current = tail;
    while (current != nullptr) {
        std::cout << current->data;
        if (current->prev != nullptr) {
            std::cout << " <-> ";
        }
        current = current->prev;
    }
    std::cout << std::endl;
    
    std::cout << "Добавить Z в начало" << std::endl;
    head = push_front(head, tail, 'Z');
    print(head);
    
    std::cout << "Добавить E в конец" << std::endl;
    head = push_back(head, tail, 'E');
    print(head);
    
    std::cout << "Удалить из начала" << std::endl;
    head = pop_front(head, tail);
    print(head);
    
    std::cout << "Удалить из конца" << std::endl;
    head = pop_back(head, tail);
    print(head);
    
    std::cout << "Очистка..." << std::endl;
    clear(head);
    head = nullptr;
    tail = nullptr;
    
    std::cout << "Готово. Пуст: " << (head == nullptr ? "да" : "нет") << std::endl;
    
    return 0;
}