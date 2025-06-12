#include "header.h"

// Реализация конструктора стека
MyStack::MyStack()
{
    TopNode = nullptr;
}

// Деструктор освобождает память
MyStack::~MyStack()
{
    while (!IsEmpty())
    {
        Pop();
    }
}

// Добавление элемента в стек
void MyStack::Push(const string & value)
{
    StackNode * newNode = new StackNode(value);
    newNode->Next = TopNode;
    TopNode = newNode;
}

// Удаление верхнего элемента
void MyStack::Pop()
{
    if (!IsEmpty())
    {
        StackNode * temp = TopNode;
        TopNode = TopNode->Next;
        delete temp;
    }
}

// Возврат верхнего элемента
string MyStack::Top() const
{
    if (!IsEmpty())
    {
        return TopNode->Value;
    }
    else
    {
        throw runtime_error("Попытка получить элемент из пустого стека.");
    }
}

// Проверка на пустоту
bool MyStack::IsEmpty() const
{
    return TopNode == nullptr;
}

// Проверка, является ли символ цифрой
bool IsDigit(char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

// Вычисление выражения стек
int EvaluateExpression(const string & expression)
{
    MyStack tokens;
    string buffer;

    for (int i = expression.length() - 1; i >= 0; --i)
    {
        char ch = expression[i];

        if (IsDigit(ch))
        {
            buffer = ch + buffer;
        }
        else if (ch == ',')
        {
            if (!buffer.empty())
            {
                tokens.Push(buffer);
                buffer.clear();
            }
        }
        else if (ch == 'm' || ch == 'M')
        {
            if (!buffer.empty())
            {
                tokens.Push(buffer);
                buffer.clear();
            }

            // Пропускаем лишние скобки
            while (!tokens.IsEmpty() && tokens.Top() == "(")
            {
                tokens.Pop();
            }

            // Извлекаем два аргумента
            int arg1 = stoi(tokens.Top()); tokens.Pop();
            int arg2 = stoi(tokens.Top()); tokens.Pop();

            int result = (ch == 'm') ? min(arg1, arg2) : max(arg1, arg2);
            tokens.Push(to_string(result));
        }
        else if (ch == '(' || ch == ')')
        {
            continue;
        }
        else
        {
            if (!buffer.empty())
            {
                tokens.Push(buffer);
                buffer.clear();
            }

            buffer = ch;
        }
    }

    if (!buffer.empty())
    {
        tokens.Push(buffer);
    }

    return stoi(tokens.Top());
}

// Генерация случайного числа в диапазоне
int GetRandomNumber(int minValue, int maxValue)
{
    return rand() % (maxValue - minValue + 1) + minValue;
}

// Рекурсивная генерация случайного выражения
string GenerateRandomExpression(int depth)
{
    if (depth <= 0)
    {
        return to_string(GetRandomNumber(1, 100));
    }

    string left = GenerateRandomExpression(depth - 1);
    string right = GenerateRandomExpression(depth - 1);
    string op = (rand() % 2 == 0) ? "m" : "M";

    return op + "(" + left + "," + right + ")";
}

// Получение выражения от пользователя вручную
string InputExpressionManually()
{
    string expr;
    cout << "Введите выражение: ";
    getline(cin, expr);
    return expr;
}

// Чтение выражения из файла
string ReadExpressionFromFile(const string & filename)
{
    ifstream file(filename);
    string expression;

    if (file.is_open())
    {
        getline(file, expression);
        file.close();
    }
    else
    {
        cout << "Ошибка: не удалось открыть файл." << endl;
    }

    return expression;
}

