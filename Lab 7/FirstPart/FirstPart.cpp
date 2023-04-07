#include <iostream>
#include "Stack.h"

using namespace std;

void Menu()
{
    setlocale(0, "");

    int choice, value, choiceStack;
    Stack* stack = new Stack;
    Stack* stack_1 = new Stack;
    Stack* stack_2 = new Stack;
    stack = NULL;
    stack_1 = NULL;
    stack_2 = NULL;

    do
    {
        system("cls");

        cout << "0 - Выход" << endl;
        cout << "1 - Вывести стек" << endl;
        cout << "2 - Добавить элемент в стек" << endl;
        cout << "3 - Извель элемент" << endl;
        cout << "4 - Экспортировать в файл" << endl;
        cout << "5 - Импортировать из файла" << endl;
        cout << "6 - Заполнить стек из двух других" << endl;
        cout << endl;

        cin >> choice;

        system("cls");

        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "Какой стек вывести: 1 - Основной\t2 - Первый не основной\t3 - Второй не основной" << endl; cin >> choiceStack;

            if (choiceStack == 1)
            {
                Show(stack);
            }
            else if (choiceStack == 2)
            {
                Show(stack_1);
            }
            else
            {
                Show(stack_2);
            }
            break;
        case 2:
            cout << "Введите значение: "; cin >> value;
            cout << "В какой стек добавить элемент: 1 - Основной\t2 - Первый не основной\t3 - Второй не основной" << endl; cin >> choiceStack;
            if (choiceStack == 1)
            {
                Push(stack, value);
            }
            else if (choiceStack == 2)
            {
                Push(stack_1, value);
            }
            else
            {
                Push(stack_2, value);
            }
            break;
        case 3:
            value = Pop(stack);
            cout << "Извлечённое значение: " << value;
            break;
        case 4:
            ExportToFile(stack);
            break;
        case 5:
            Clear(stack);
            ImportFromFile(stack);
            break;
        case 6:
            Clear(stack);
            NewStack(stack, stack_1, stack_2);
            break;
        default:
            cout << "Не точный пункт!" << endl;
            break;
        }
        cout << endl << endl;
        system("pause");

    } while (choice);
}

int main()
{
    Menu();
}