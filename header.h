/*
Задача:
1. Используя структуру стека, вычислить выражение, содержащее две операции:
поиск минимума (обозначается m(<число1>,<число2>)) и поиск максимума
(обозначается М(<число1>,<число2>)). Операции могут быть вложенными,
например, M(15, m(16,8)) (в данном выражении ищем минимум из 16 и 8, а
потом ищем максимум от результата m(16,8) и 15, ответ 15). В качестве
аргументов могут использоваться только целые положительные числа.
Строка, вводимая пользователем, корректна и не содержит пробелов.
*/
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Класс узла для стека
struct StackNode
{
    string Value;
    StackNode * Next;

    StackNode(const string & val)
    {
        Value = val;
        Next = nullptr;
    }
};

// Стек на односвязном списке
class MyStack
{
private:
    StackNode * TopNode;

public:
    MyStack();
    ~MyStack();

    void Push(const string & value);
    void Pop();
    string Top() const;
    bool IsEmpty() const;
};

// Проверка, является ли символ цифрой
bool IsDigit(char symbol);

// Вычисление выражения с минимумом и максимумом с использованием собственного стека
int EvaluateExpression(const string & expression);

// Считывание выражения из файла
string ReadExpressionFromFile(const string & filename);

// Генерация случайного выражения
string GenerateRandomExpression(int depth = 3);

// Получение выражения от пользователя (ручной ввод)
string InputExpressionManually();

#endif // HEADER_H

