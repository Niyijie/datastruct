#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include "iostream"
#include "string"
using namespace std;

struct stu
{
    string name;
    int age;
};

struct SeqListNode
{
    stu *stu;
};

class List
{
  public:
    void SeqList_create(int capacity);
    void SeqList_Destroy();
    void SeqList_Clear();
    void SeqList_Insert(stu *node, int pos);
    void SeqList_Delete(int pos);
    stu *SeqList_Get(int pos);
    int SeqList_Length();
    void ShowList();

  private:
    int capacity;
    int length;
    SeqListNode *listArr;
};

void List::SeqList_create(int capacity)
{
    this->capacity = capacity;
    this->length = 0;
    this->listArr = new SeqListNode[capacity];
}

void List::SeqList_Destroy()
{
    //如果是空指针
    if (this->listArr == nullptr)
        return;
    
    this->capacity = 0;
    this->length = 0;
    delete[] this->listArr;
}

void List::SeqList_Clear()
{
    if (this->listArr == nullptr)
        return;
    //清除所有数据
    for (int i = 0; i < this->length; i++)
    {
        delete this->listArr[i].stu;
    }
    this->length = 0;
}

void List::SeqList_Insert(stu *node, int pos)
{
    if (this->length == this->capacity)
    {
        cout << "list full!" << endl;
        return;
    }
    //将所有pos右边的元素移1个位置
    for (int i = this->length; i > pos; i--)
        this->listArr[i - 1] = this->listArr[i];

    //插入元素
    this->listArr[pos].stu = node;

    this->length ++;
}

void List::SeqList_Delete(int pos)
{
    if (this->length < pos + 1)
        return;

    delete this->listArr[pos].stu;
    for (int i = pos; i < this->length - 1; i++)
        this->listArr[i] = this->listArr[i + 1];

    this->length --;
}

stu *List::SeqList_Get(int pos)
{
    if (pos < 0 || pos > this->length - 1)
        return nullptr;
    else
        return this->listArr[pos].stu;
}

int List::SeqList_Length()
{
    return this->length;
}

void List::ShowList()
{
    if (this->listArr == nullptr)
        return;

    for (int i = 0; i < this->length; i++)
    {
        cout << "name: " << this->listArr[i].stu->name << endl;
        cout << "age: " << this->listArr[i].stu->age << endl;
    }
}

#endif