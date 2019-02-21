#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_
#include "iostream"
#include "string"
using namespace std;

class Stack
{
  public:
    void SeqStack_create(int capacity);
    void SeqStack_Destroy();
    void SeqStack_Clear();
    void SeqStack_Push(int value);
    void SeqStack_Pop();
    int SeqStack_Top();
    int SeqStack_Size();

  private:
    int capacity;
    int size;
    int top;
    int *Stack;
};

void Stack::SeqStack_create(int capacity)
{
    this->capacity = capacity;
    this->size = 0;
    this->top = 0;
    this->Stack = new int[capacity];
}

void Stack::SeqStack_Destroy()
{
    //如果是空指针
    if (this->Stack == nullptr)
        return;

    this->capacity = 0;
    this->size = 0;
    delete[] this->Stack;
}

void Stack::SeqStack_Clear()
{
    if (this->Stack == nullptr)
        return;
    //清除所有数据
    for (int i = 0; i < this->size; i++)
    {
        this->SeqStack_Pop();
    }
    this->size = 0;
}

void Stack::SeqStack_Push(int value)
{
    if (this->size == this->capacity)
    {
        cout << "Stack full!" << endl;
        return;
    }

    this->Stack[this->top + 1] = value;
    this->top++;
    this->size++;
}

void Stack::SeqStack_Pop()
{
    if (this->size <= 0)
    {
        cout << "Stack empty!!" << endl;
        return;
    }
    this->Stack[this->top] = 0;
    this->top--;
    this->size--;
}

int Stack::SeqStack_Top()
{
    return this->Stack[this->top];
}

int Stack::SeqStack_Size()
{
    return this->size;
}
#endif