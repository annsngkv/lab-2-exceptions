#include <QCoreApplication>
#include "stack.h"
#include <iostream>
#include "exception.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Stack <int> stack(2);
    int b = 3;
    int c = 4;
    int d = 5;

    int *ptr1 = &b;
    int *ptr2 = &c;
    int *ptr3 = &d;

    std::cout << "Размер стека: " << stack.getStackSize() << std::endl;

    try { // вызовы операций, которые генерируют исключения
        stack.push(ptr1);
        stack.push(ptr2);
       // stack.push(ptr3);
        stack.pop();
        stack.pop();
        stack.pop();
    } catch (const exc::EStackException& e) {// ловим все исключения типа EStackException
        std::cout << e.what() << std::endl; // обработка исключений
    }

    return a.exec();
}
