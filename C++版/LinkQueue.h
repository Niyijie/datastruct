#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_
#include "iostream"
#include "string"
using namespace std;

struct LinkQueueNode
{
    LinkQueueNode *next;
};

class Queue
{
  public:
    void LinkQueue_create();
    void LinkQueue_Destroy();
    void LinkQueue_Clear();
    void LinkQueue_Append(LinkQueueNode *node); //void *item;
    LinkQueueNode *LinkQueue_Top();
    LinkQueueNode *LinkQueue_Retrieve();
    int LinkQueue_Length();

  private:
    LinkQueueNode *front;
    LinkQueueNode *rear;
    int length;
};

void Queue::LinkQueue_create()
{
    this->front = new LinkQueueNode;
    this->front->next = nullptr;
    this->rear = this->front;
    this->length = 0;
}

void Queue::LinkQueue_Destroy()
{
    while (this->front != this->rear)
    {
        this->LinkQueue_Retrieve();
    }
    delete this->front;
}

//清空链表，内存由调用者(上层应用）释放
void Queue::LinkQueue_Clear()
{
   while (this->front != this->rear)
    {
        this->LinkQueue_Retrieve();
    }
}

void Queue::LinkQueue_Append(LinkQueueNode *node)
{
    if (this->front == nullptr)
    {
        cout<<"Queue not create!"<<endl;
        return;
    }
    else
    {
        node->next = this->rear->next;
        this->rear->next = node;
        this->rear = node;
    }
    this->length++;
}

LinkQueueNode *Queue::LinkQueue_Retrieve()
{
    if (this->front->next == nullptr)
    {
        cout << "stack empty!!" << endl;
        return nullptr;
    }
    else
    {
        LinkQueueNode *current = this->front->next;
        this->front->next = current->next;
        this->length--;
        return current;
    }
}

int Queue::LinkQueue_Length()
{
    return this->length;
}

LinkQueueNode *Queue::LinkQueue_Top()
{
    if (this->front->next == nullptr)
        cout << "stack empty" << endl;
    return this->front;
}
#endif