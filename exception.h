#ifndef EXCEPTION_H
#define EXCEPTION_H

namespace exc {
    #include <string.h>

    class EStackException
    {
        private:
            char* message; //диагностическое сообщение

        public:
            //конструкторы с параметрами
            EStackException(const char* arg_message);
            EStackException(const EStackException& arg);
            //деструктор
            ~EStackException();
            const char* what() const { return message;} //функция вывода диагастического сообщения
    };

    //наследуемся от класса EStackException
    class EStackEmpty : public EStackException
    {
        public:
            explicit EStackEmpty(const char* arg) : EStackException(arg) {}
    };

    //наследуемся от класса EStackException
    class EStackOverflow : public EStackException
    {
        public:
            explicit EStackOverflow(const char* arg) : EStackException(arg) {}
    };

    EStackException::EStackException(const char* arg_message)
    {
        message = new char[strlen(arg_message)+1];

        strcpy(message, arg_message);
    }

    EStackException::EStackException(const EStackException& arg)
    {
        message = new char[strlen(arg.message)+1];
        strcpy(message, arg.message);
    }

    EStackException::~EStackException()
    {
        delete message;
    }
}

#endif
