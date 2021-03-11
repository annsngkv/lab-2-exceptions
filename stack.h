#ifndef STACK_H
#define STACK_H

#include "exception.h"
#include <iostream>

template <class T>

class Stack
{
    private:
            T** stack; //массив указателей на объекты
            int maxSize = 1024; //дефолтный размер стэка
            int topIdx = 0; //индекс верхнего элемента массива
    public:
        Stack(); //конструктор по умолчанию
        Stack(int size); //конструктор с параметром
        ~Stack(); //деструктор
        void push(T* obj); //функция добавления объекта в стэк
        void pop(); //функция извлечения объекта из стэка
        int getStackSize(); //функция получения размера стэка
};

template <class T>
Stack<T>::Stack()
{
    stack = new T*[maxSize];
}

template <class T>
Stack<T>::Stack(int size)
{
    maxSize = size;
    stack = new T*[size];
}

template <class T>
Stack<T>::~Stack()
{
    delete [] stack;
}

template <class T>
void Stack<T>::push(T* obj)
{
    if (topIdx >= maxSize) {
        throw exc::EStackOverflow("Ошибка: cтек переполнен"); // генерируем исключение типа EStackOverflow, если стэк переполнен
    }

    stack[topIdx] = obj;
    topIdx++;
}

template <class T>
void Stack<T>::pop()
{
     topIdx--;

     if (topIdx < 0) {
         throw exc::EStackEmpty("Ошибка: cтек пуст"); // генерируем исключение типа EStackEmpty, если стэк пуст
     }
}

template <class T>
int Stack<T>::getStackSize()
{
    return maxSize;
}

#endif // STACK_H
