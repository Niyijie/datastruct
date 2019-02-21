#include "SeqStack.h"
#include "iostream"
using namespace std;

int isNumber(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

int isOperator(char ch)
{
    switch (ch)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 1;
    case '/':
        return 1;
    default:
        break;
    }
    return 0;
}

int count(Stack stack, string exp)
{
    for (auto s : exp)
    {
        if (isNumber(char(s)))
        {
            stack.SeqStack_Push((s - '0'));
            continue;
        }
        if (isOperator(char(s)))
        {
            int right = stack.SeqStack_Top();
            stack.SeqStack_Pop();
            int left = stack.SeqStack_Top();
            stack.SeqStack_Pop();
            int result = 0;
            switch (s)
            {
            case '+':
                result = right + left;
                break;
            case '-':
                result = left - right;
                break;
            case '*':
                result = right * left;
                break;
            case '/':
                result = left / right;
                break;
            default:
                break;
            }
            stack.SeqStack_Push(result);
        }
    }
    return stack.SeqStack_Top();
}

int main()
{
    Stack stack;
    stack.SeqStack_create(20);
    string str = "9 3 1-3*+ 4 2/+";
    cout << count(stack, str) << endl;
}