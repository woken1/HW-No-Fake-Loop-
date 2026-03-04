## Задача 0. Соглашение о структуре

Используется стандартное соглашение (без псевдоузлов и цикличности):

1. За последним узлом нет узлов (tail->next = nullptr)
2. Начало списка — начало данных (head указывает на первый элемент)
3. Первый узел: prev = nullptr
4. Последний узел: next = nullptr
5. Пустой список: head = nullptr, tail = nullptr

### Структура узла

template< class T >
struct BiList {
    T data;
    BiList<T>* next;
    BiList<T>* prev;
};

## Задача 1. Неявный интерфейс

create_node(value)  Создать новый узел 
push_front(head, tail, value) Добавить в начало 
push_back(head, tail, value) Добавить в конец
pop_front(head, tail) Удалить из начала
pop_back(head, tail) Удалить из конца
size(head) Количество элементов
empty(head) Проверка на пустоту
clear(head) Очистить список
array_to_list(arr, size, tail) Массив → список
print(head) | Вывод на экран

---

## Задача 2. Упрощённый интерфейс

// Создание
BiList<T>* create_node(const T& value);

// Добавление
BiList<T>* push_front(BiList<T>* head, BiList<T>*& tail, const T& value);
BiList<T>* push_back(BiList<T>* head, BiList<T>*& tail, const T& value);

// Удаление
BiList<T>* pop_front(BiList<T>* head, BiList<T>*& tail);
BiList<T>* pop_back(BiList<T>* head, BiList<T>*& tail);

// Информация
size_t size(const BiList<T>* head);
bool empty(const BiList<T>* head);

// Управление
void clear(BiList<T>* head);
void print(const BiList<T>* head);

// Конвертация
BiList<T>* array_to_list(const T* arr, size_t size, BiList<T>*& tail);

---

## Задача 3. Реализация

- Шаблоны — работает с любым типом T
- head передаётся по значению, tail по ссылке
- Каждый узел выделяется через new

---

## Задача 4. Конвертация массива

### Пример

#include "bilist.h"
#include <iostream>

int main() {
    char arr[] = {'A', 'B', 'C', 'D'};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);
    
    BiList<char>* head = nullptr;
    BiList<char>* tail = nullptr;
    
    head = array_to_list(arr, arr_size, tail);
    print(head);
    
    clear(head);
    head = nullptr;
    tail = nullptr;
    
    return 0;
}

### Вывод программы

Массив: A B C D \
Список: A <-> B <-> C <-> D \
Размер: 4 \
Обратный: D <-> C <-> B <-> A \
Добавить Z в начало \
Z <-> A <-> B <-> C <-> D \
Добавить E в конец \
Z <-> A <-> B <-> C <-> D <-> E \
Удалить из начала \ 
A <-> B <-> C <-> D <-> E \
Удалить из конца \
A <-> B <-> C <-> D \
Очистка... \
Готово. Пуст: да 

---

## Освобождение памяти

template< class T >
void clear(BiList<T>* head) {
    while (head != nullptr) {
        BiList<T>* next = head->next;
        delete head;
        head = next;
    }
}


После очистки:

clear(head);
head = nullptr;
tail = nullptr;


---

## Компиляция и запуск

g++ -std=c++11 -o bilist main.cpp
./bilist

---