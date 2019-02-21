#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include "iostream"
#include "string"
using namespace std;

struct LinkListNode
{
    LinkListNode *next;
};

class LinkList
{
  public:
    void LinkList_create();
    void LinkList_Destroy();
    void LinkList_Clear();
    void LinkList_Push(LinkListNode *node);
    void LinkList_Insert(LinkListNode *node, int pos);
    LinkListNode *LinkList_Delete(int pos);
    LinkListNode *LinkList_Get(int pos);
    int LinkList_Length();
    void ShowLinkList();

  private:
    LinkListNode *firstNode;
    int length;
};

void LinkList::LinkList_create()
{
    this->firstNode = new LinkListNode;
    this->firstNode->next = nullptr;
    this->length = 0;
}

void LinkList::LinkList_Destroy()
{
    this->LinkList_Clear();
    delete this->firstNode;
    this->length = 0;
}
//清空链表，内存由调用者(上层应用）释放
void LinkList::LinkList_Clear()
{
    LinkListNode *current = this->firstNode->next;
    while (current != nullptr)
    {
        this->firstNode->next = current->next;
        delete current;
        current = this->firstNode->next;
    }
    this->length = 0;
}

void LinkList::LinkList_Push(LinkListNode *node)
{
    //头插法
    node->next = this->firstNode->next;
    this->firstNode->next = node;
    this->length++;
}

void LinkList::LinkList_Insert(LinkListNode *node, int pos)
{
    if (pos < 0 || pos > this->length)
        return;

    LinkListNode *current = this->firstNode;
    for (int i = 0; i < pos; i++)
        current = current->next;

    node->next = current->next;
    current->next = node;
    this->length++;
}

LinkListNode *LinkList::LinkList_Delete(int pos)
{
    if (pos < 0 || pos >= this->length)
        return nullptr;

    LinkListNode *current = this->firstNode;
    LinkListNode *deleteNode = nullptr;
    for (int i = 0; i < pos; i++)
        current = current->next;

    deleteNode = current->next;
    current->next = deleteNode->next;
    this->length--;
    //返回地址 让上层应用释放内存
    return deleteNode;
}

LinkListNode *LinkList::LinkList_Get(int pos)
{
    LinkListNode *node = nullptr;
    if (pos < 0 || pos >= this->length)
        return node;

    LinkListNode *current = this->firstNode;
    for (int i = 0; i < pos; i++)
        current = current->next;

    node = current->next;
    return node;
}

int LinkList::LinkList_Length()
{
    return this->length;
}

void LinkList::ShowLinkList()
{
    LinkListNode *current = this->firstNode->next;
    while (current != nullptr)
    {
        // cout << "name: " << reinterpret_cast<stu *>(current)->name << endl;
        // cout << "age: " << reinterpret_cast<stu *>(current)->age << endl;

        //current = current->next;
    }
}
#endif
