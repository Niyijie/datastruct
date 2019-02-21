#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_
#include "iostream"
#include "string"
using namespace std;

struct LinkStackNode
{
    LinkStackNode *next;
};

class Stack
{
  public:
    void LinkStack_create();
    void LinkStack_Destroy();
    void LinkStack_Clear();
    void LinkStack_Push(LinkStackNode *node); //void *item;
    LinkStackNode *LinkStack_Top();
    LinkStackNode *LinkStack_Pop();
    int LinkStack_Size();

  private:
    LinkStackNode *top;
    int size;
};

void Stack::LinkStack_create()
{
    this->top = nullptr;
    this->size = 0;
}

void Stack::LinkStack_Destroy()
{
     while (this->top != nullptr)
    {
       auto node = this->LinkStack_Pop();
       delete node;
    }
}

//清空链表，内存由调用者(上层应用）释放
void Stack::LinkStack_Clear()
{
    while (this->top != nullptr)
    {
        this->LinkStack_Pop();
    }
}

void Stack::LinkStack_Push(LinkStackNode *node)
{
    if (this->top == nullptr)
    {
        this->top = node;
        this->top->next = nullptr;
    }
    else
    {
        node->next = this->top;
        this->top = node;
    }
    this->size++;
}

LinkStackNode *Stack::LinkStack_Pop()
{
    if (this->top == nullptr)
    {
        cout << "stack empty!!" << endl;
        return nullptr;
    }
    else
    {
        LinkStackNode *current = this->top;
        this->top = this->top->next;
        this->size--;
        return current;
    }
}

int Stack::LinkStack_Size()
{
    return this->size;
}

LinkStackNode *Stack::LinkStack_Top()
{
    if (this->top == nullptr)
        cout << "stack empty" << endl;
    return this->top;
}
#endif