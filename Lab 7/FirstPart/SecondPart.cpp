#include <iostream>
#include <fstream>
#include "Stack.h"

using namespace std;

void Push(Stack*& stack, int value)
{
    Stack* tmp = new Stack;
    tmp->value = value;
    tmp->next = stack;
    stack = tmp;
}

int Pop(Stack*& stack)
{
    if (stack == NULL)
    {
        cout << "Стек пуст!";
        return -1;
    }
    else
    {
        int value;

        Stack* tmp = stack;
        value = stack->value;
        if (stack)
        {
            stack = stack->next;
        }

        delete tmp;
        return value;
    }
}

void Show(Stack*& stack)
{
    if (stack == NULL)
    {
        cout << "Стек пуст!";
        return;
    }
    else
    {
        Stack* tmp = stack;
        cout << "Стек:" << endl;
        while (tmp != NULL)
        {
            cout << tmp->value << endl;
            tmp = tmp->next;
        }
    }
}

void ExportToFile(Stack*& stack)
{
    ofstream file("file.txt", ios::trunc);

    Stack* tmp = stack;

    while (tmp != NULL)
    {
        file << tmp->value << endl;
        tmp = tmp->next;
    }
}

void Clear(Stack*& stack)
{
    while (stack != NULL)
    {
        Stack* tmp = stack;
        stack = stack->next;
        delete tmp;
    }
}

void Reverse(Stack*& stack)
{
    Stack* tmp = stack;
    Stack* ptr = stack;

    int arr[50], lastElem;

    for (int i = 0; ptr != NULL; i++)
    {
        arr[i] = ptr->value;
        ptr = ptr->next;
        lastElem = i;
    }

    for (int i = lastElem; tmp != NULL; i--)
    {
        tmp->value = arr[i];
        tmp = tmp->next;
    }
}

void ImportFromFile(Stack*& stack)
{
    ifstream file("file.txt");

    int value;

    while (file.eof() == false)
    {
        file >> value;
        Push(stack, value);
    }
    Pop(stack);
    Reverse(stack);
}

void NewStack(Stack*& stack, Stack*& stack1, Stack*& stack2) 
{
    bool check = true;
    Stack* tmpStack;
    Stack* HeaderPointerStack2 = stack2;
    Stack* PointerToElementNewStack = stack;

    stack->next = NULL;

    while (stack1 = stack1->next) {
        while ((stack2 = stack2->next) && check) {
            if (stack1->value != stack2->value)
                while (stack) {
                    if (stack->value == stack1->value)
                        check = false;
                    stack = stack->next;
                }
            else
                check = false;
        }

        stack = PointerToElementNewStack;

        if (check) {
            stack->value = stack1->value;
            tmpStack = new Stack;
            tmpStack->next = stack;
            stack = tmpStack;

            PointerToElementNewStack = stack;
        }

        check = true;

        stack2 = HeaderPointerStack2;
    }
}