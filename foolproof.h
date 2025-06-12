#ifndef FOOLPROOF_H
#define FOOLPROOF_H

#include <iostream>    
#include <string>
#include <limits>    
#include <cctype>

using namespace std;

// Проверка, является ли строка числом
bool IsNumber(const string & str);

// Проверка корректности имени файла
bool IsValidFilename(const string & filename);

// Проверка корректности выбора в меню
int GetMenuChoice(int minChoice, int maxChoice);

// Проверка корректности ввода положительного числа
int GetPositiveInteger(const string & prompt);

// Проверка допустимости символов и структуры выражения
bool IsValidExpression(const string & expression);

#endif // FOOLPROOF_H

