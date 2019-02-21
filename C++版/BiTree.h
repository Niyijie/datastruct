#ifndef _BITREE_H_
#define _BITREE_H_
#include "iostream"
#include "stack"
using namespace std;
typedef enum
{
    Link,
    Thread
} PointerTag;

struct BitNode //结点结构
{
    char data;                //结点数据
    BitNode *lchild, *rchild; //左右孩子指针
    PointerTag LTag;
    PointerTag RTag;
};

void CreateBiTree(BitNode **T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
    {
        *T = nullptr;
        return;
    }
    else
    {
        *T = new BitNode;
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

void preOrderTraverse(BitNode **T)
{
    if (*T == nullptr)
    {
        return;
    }
    else
    {
        cout << (*T)->data << endl;
        preOrderTraverse(&(*T)->lchild);
        preOrderTraverse(&(*T)->rchild);
    }
}
//非递归先序遍历
void noPreOrderTraverse(BitNode **T)
{
    BitNode *temp = *T;
    if (temp == nullptr)
        return;
    stack<BitNode *> stack;
    while (temp != nullptr || stack.size() != 0)
    {
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            stack.push(temp);
            temp = temp->lchild;
        }
        if (stack.size() != 0)
        {
            temp = stack.top();
            stack.pop();
            temp = temp->rchild;
        }
    }
}

void inOrderTraverse(BitNode **T)
{
    if (*T == nullptr)
        return;
    else
    {
        inOrderTraverse(&(*T)->lchild);
        cout << (*T)->data << endl;
        inOrderTraverse(&(*T)->rchild);
    }
}
//非递归中序遍历
void noInOrderTraverse(BitNode **T)
{
    stack<BitNode *> stack;
    BitNode *temp = *T;
    if (temp == nullptr)
        return;
    while (temp != nullptr || stack.size() != 0)
    {
        while (temp != nullptr)
        {
            stack.push(temp);
            temp = temp->lchild;
        }
        if (stack.size() != 0)
        {
            temp = stack.top();
            stack.pop();
            cout << temp->data << endl;
            temp = temp->rchild;
        }
    }
}

void postOrderTraverse(BitNode **T)
{
    if (*T == nullptr)
        return;
    else
    {
        postOrderTraverse(&(*T)->lchild);
        postOrderTraverse(&(*T)->rchild);
        cout << (*T)->data << endl;
    }
}
//非递归后序遍历
void noPostOrderTraverse(BitNode **T)
{
    BitNode *temp = *T;
    if (temp == nullptr)
        return;
    BitNode *cur; //当前结点
    BitNode *pre = nullptr;

    stack<BitNode *> stack;
    stack.push(temp);

    while (stack.size() != 0)
    {
        cur = stack.top();
        if ((cur->lchild == nullptr && cur->rchild == nullptr) || (pre != nullptr && (pre == cur->lchild || pre == cur->rchild)))
        {
            cout << cur->data << endl;
            stack.pop();
            pre = cur;
        }
        else
        {
            if (cur->rchild != nullptr)
                stack.push(cur->rchild);
            if (cur->lchild != nullptr)
                stack.push(cur->lchild);
        }
    }
}
//删除一棵树
void deleteTree(BitNode **T)
{
    if (*T == nullptr)
        return;
    else
    {
        deleteTree(&(*T)->lchild);
        deleteTree(&(*T)->rchild);
        delete *T;
        *T = nullptr;
    }
}

BitNode *pre;

//线索化二叉树
void InThreading(BitNode **T)
{
    BitNode *temp = *T;
    if(temp)
    {

        InThreading(&(temp->lchild));
        if(temp->lchild)
        {
            temp->LTag = Thread;
            temp->lchild = pre;
        }
        if(!pre->rchild)
        {
            pre->RTag = Thread;
            pre->rchild = temp;
        }
        pre = temp;
        InThreading(&(temp->rchild));
    }
}

#endif
