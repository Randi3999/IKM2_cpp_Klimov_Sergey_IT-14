#include "foolproof.h"

using namespace std;

// Проверка, является ли строка числом
bool IsNumber(const string & str)
{
    if (str.empty()) return false;
    for (char ch : str)
    {
        if (!isdigit(ch))
        {
            return false;
        }
    }
    return true;
}

// Проверка имени файла — допустимы только латиница, цифры, точка, подчёркивание
bool IsValidFilename(const string & filename)
{
    for (char c : filename)
    {
        if (!isalnum(c) && c != '.' && c != '_')
        {
            return false;
        }
    }
    return !filename.empty();
}

// Получение корректного пункта меню в диапазоне [minChoice, maxChoice]
int GetMenuChoice(int minChoice, int maxChoice)
{
    string input;
    int choice;

    while (true)
    {
        cout << "Введите пункт меню (" << minChoice << "-" << maxChoice << "): ";
        getline(cin, input);

        if (!IsNumber(input))
        {
            cout << "Ошибка: введите целое число от " << minChoice << " до " << maxChoice << "." << endl;
            continue;
        }

        choice = stoi(input);

        if (choice < minChoice || choice > maxChoice)
        {
            cout << "Ошибка: пункт вне диапазона." << endl;
        }
        else
        {
            return choice;
        }
    }
}

// Получение положительного целого числа от пользователя
int GetPositiveInteger(const string & prompt)
{
    string input;
    int number;

    while (true)
    {
        cout << prompt;
        getline(cin, input);

        if (!IsNumber(input))
        {
            cout << "Ошибка: введите положительное целое число." << endl;
            continue;
        }

        number = stoi(input);

        if (number <= 0)
        {
            cout << "Ошибка: число должно быть больше нуля." << endl;
        }
        else
        {
            return number;
        }
    }
}

// Проверка допустимости символов и структуры выражения
bool IsValidExpression(const string & expression)
{
    int balance = 0;

    for (char ch : expression)
    {
        if (isdigit(ch) || ch == 'm' || ch == 'M' || ch == '(' || ch == ')' || ch == ',')
        {
            if (ch == '(') balance++;
            else if (ch == ')') balance--;
            if (balance < 0) return false;
        }
        else
        {
            return false; // Недопустимый символ
        }
    }

    return balance == 0 && !expression.empty();
}

