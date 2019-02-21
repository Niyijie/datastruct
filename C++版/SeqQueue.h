#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_
#include "iostream"
#include "string"
using namespace std;

class Queue
{
  public:
    void SeqQueue_create(int capacity);
    void SeqQueue_Destroy();
    void SeqQueue_Clear();
    void SeqQueue_Append(int value);
    void SeqQueue_Retrieve();
    int SeqQueue_Top();
    int SeqQueue_Length();

  private:
    int capacity;
    int front;
    int rear;
    int *Queue;
};

void Queue::SeqQueue_create(int capacity)
{
    this->capacity = capacity;
    this->front = 0;
    this->rear = 0;
    this->Queue = new int[capacity];
}

void Queue::SeqQueue_Destroy()
{
    //如果是空指针
    if (this->Queue == nullptr)
        return;

    delete[] this->Queue;
}

void Queue::SeqQueue_Clear()
{
    if (this->Queue == nullptr)
        return;
    //清除所有数据
    for (int i = 0; i < this->SeqQueue_Length(); i++)
    {
        this->SeqQueue_Retrieve();
    }
}

void Queue::SeqQueue_Append(int value)
{
    if (this->rear + 1 == this->front)
    {
        cout << "Queue full!" << endl;
        return;
    }

    this->Queue[this->rear] = value;
    this->rear = (this->rear + 1) % capacity;
}

void Queue::SeqQueue_Retrieve()
{
    if (this->rear == this->front)
    {
        cout << "Queue empty!!" << endl;
        return;
    }
    this->Queue[this->front] = 0;
    this->front = (this->front + 1) % capacity;
}

int Queue::SeqQueue_Top()
{
    return this->Queue[this->front];
}

int Queue::SeqQueue_Length()
{
    int length = (this->rear - this->front + this->capacity) % this->capacity;
    return length;
}

#endif