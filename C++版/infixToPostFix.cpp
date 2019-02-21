#include "iostream"
#include "LinkStack.h"
#include "string"
using namespace std;

struct opeNode
{
    LinkStackNode node;
    char ch;
    int priority;
};

int isDigital(char s)
{
    if (s >= '0' && s <= '9')
        return 1;
    else
        return 0;
}

opeNode *isOperator(char s)
{
    opeNode *node = nullptr;
    switch (s)
    {
    case '+':
        node = new opeNode;
        node->ch = '+';
        node->priority = 1;
        return node;
    case '-':
        node = new opeNode;
        node->ch = '-';
        node->priority = 1;
        return node;
    case '*':
        node = new opeNode;
        node->ch = '*';
        node->priority = 2;
        return node;
    case '/':
        node = new opeNode;
        node->ch = '/';
        node->priority = 2;
        return node;
    case '(':
        node = new opeNode;
        node->ch = '(';
        node->priority = 0;
        return node;

    default:
        break;
    }
    return nullptr;
}

string change(Stack stack, string str)
{
    string list;
    for (auto s : str)
    {
        if (isDigital(char(s)))
        {
            list.push_back(s);
            continue;
        }

        if (s == ')')
        {
            auto ch = reinterpret_cast<opeNode *>(stack.LinkStack_Top())->ch;
            while (ch != '(')
            {
                list.push_back(ch);
                stack.LinkStack_Pop();
                ch = reinterpret_cast<opeNode *>(stack.LinkStack_Top())->ch;
            }
            if (ch == '(')
                stack.LinkStack_Pop();
            continue;
        }

        if (isOperator(char(s)) != nullptr)
        {
            auto node = isOperator(char(s));

            if (stack.LinkStack_Size() == 0)
            {
                stack.LinkStack_Push(&node->node);
            }
            else
            {
                if (s == '(')
                {
                    stack.LinkStack_Push(&node->node);
                    continue;
                }

                while (stack.LinkStack_Size() != 0)
                {
                    auto pro = reinterpret_cast<opeNode *>(stack.LinkStack_Top())->priority;
                    if (pro >= node->priority)
                    {
                        list.push_back(reinterpret_cast<opeNode *>(stack.LinkStack_Top())->ch);
                        stack.LinkStack_Pop();
                        if (pro == node->priority)
                            break;
                        else
                            continue;
                    }
                    else
                    {
                        break;
                    }
                }
                stack.LinkStack_Push(&node->node);
            }
        }
    }

    while (reinterpret_cast<opeNode *>(stack.LinkStack_Top() != nullptr))
    {
        list.push_back(reinterpret_cast<opeNode *>(stack.LinkStack_Top())->ch);
        stack.LinkStack_Pop();
        continue;
    }
    return list;
}

int main()
{
    string str = "1+(2-3)*4+10/5";
    Stack stack;
    cout << str << endl;

    stack.LinkStack_create();
    cout << change(stack, str) << endl;
}

//123-4*+105/+
