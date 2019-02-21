#include "LinkStack.h"
#include "iostream"
#include "string"
using namespace std;

struct charNode
{
    LinkStackNode node;
    char s;
};

int isLeft(char s)
{
    switch (s)
    {
    case '(':
        return 1;
    case '{':
        return 1;
    case '<':
        return 1;
    case '[':
        return 1;
    }
    return 0;
}

int isRight(char s)
{
    switch (s)
    {
    case ')':
        return 1;
    case '}':
        return 1;
    case '>':
        return 1;
    case ']':
        return 1;
    }
    return 0;
}

int match(char left, char right)
{
    switch (left)
    {
    case '{':
        if (right == '}')
            return 1;
        break;
    case '(':
        if (right == ')')
            return 1;
        break;
    case '[':
        if (right == ']')
            return 1;
        break;
    case '<':
        if (right == '>')
            return 1;
        break;
    }
    return 0;
}

string parentChecking(Stack *stack, string str)
{
    for (auto s : str)
    {
        if (isLeft(s))
        {
            charNode *node = new charNode;
            node->s = static_cast<char>(s);
            stack->LinkStack_Push(&node->node);
        }

        if (isRight(s))
        {
            auto node = stack->LinkStack_Pop();
            if (node == nullptr)
                return "invalid error";

            int ret = match(reinterpret_cast<charNode *>(node)->s, s);
            if (ret == 1)
            {
                continue;
            }
            else
            {
                return "invalid error";
            }
        }
    }
    if (stack->LinkStack_Size() != 0)
        return "invalid error";
    else
        return "success";
}

int main()
{
    Stack matchStack;
    string str = "int main(){ Stack matchStack;matchStack.LinkStack_create();auto ret = parentChecking(&matchStack, str);}";

    matchStack.LinkStack_create();
    auto ret = parentChecking(&matchStack, str);
    cout << ret << endl;
}