#include "header.h"
#include "foolproof.h"

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(time(0));

    cout << "================ М И Н И М У М   /   М А К С И М У М ================" << endl;
    cout << "Выражение состоит из операций m(x,y) – минимум и M(x,y) – максимум" << endl;
    cout << "====================================================================" << endl;

    cout << "Выберите способ ввода выражения:" << endl;
    cout << "1. С клавиатуры" << endl;
    cout << "2. Из файла" << endl;
    cout << "3. Случайное выражение" << endl;

    int choice = GetMenuChoice(1, 3);
    string expression;

    switch (choice)
    {
        case 1:
            expression = InputExpressionManually();

            if (!IsValidExpression(expression))
            {
                cout << "Ошибка: выражение содержит недопустимые символы или неправильную структуру." << endl;
                return 1;
            }
            break;

        case 2:
        {
            string filename;
            cout << "Введите имя файла: ";
            getline(cin, filename);

            while (!IsValidFilename(filename))
            {
                cout << "Ошибка: имя файла может содержать только буквы, цифры, точку и подчёркивание." << endl;
                cout << "Повторите ввод: ";
                getline(cin, filename);
            }

            expression = ReadExpressionFromFile(filename);

            if (expression.empty())
            {
                cout << "Выражение не было считано. Завершение программы." << endl;
                return 1;
            }

            if (!IsValidExpression(expression))
            {
                cout << "Ошибка: выражение в файле некорректно." << endl;
                return 1;
            }

            break;
        }

        case 3:
        {
            int depth = GetPositiveInteger("Введите глубину вложенности (например, 3): ");
            expression = GenerateRandomExpression(depth);
            cout << "Случайно сгенерированное выражение: " << expression << endl;

            if (!IsValidExpression(expression))
            {
                cout << "Ошибка: сгенерированное выражение некорректно." << endl;
                return 1;
            }

            break;
        }
    }

    int result = EvaluateExpression(expression);
    cout << "Результат вычисления выражения: " << result << endl;

    return 0;
}

