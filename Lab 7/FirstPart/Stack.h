#pragma once

struct Stack
{
	int value;
	Stack* next;
};

void Push(Stack*& stack, int value);
void Show(Stack*& stack);
int Pop(Stack*& stack);
void Clear(Stack*& stack);
void ExportToFile(Stack*& stack);
void ImportFromFile(Stack*& stack);
void NewStack(Stack*& stack, Stack*& stack_1, Stack*& stack_2);