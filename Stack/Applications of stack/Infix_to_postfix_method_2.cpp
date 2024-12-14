//method 2 - it also pushes the operands in the stack and pops based on their precedance, operands has highest precedance

#include <iostream>
#include <string.h>
using namespace std;

#define SIZE 100

class stack
{
    int top;
    char s[SIZE];

public:
    stack() { top = -1; }
    char pop();
    void push(char x);
    char peek();
    int isEmpty();
    int isFull();
};

int stack::isEmpty()
{
    return top == -1;
}

int stack::isFull()
{
    return top == SIZE - 1;
}

char stack::pop()
{
    if (!isEmpty())
    {
        return s[top--];
    }
    return -1;
}

void stack::push(char x)
{
    if (!isFull())
    {
        s[++top] = x;
    }
}

char stack::peek()
{
    if (isEmpty())
        return -1;
    return s[top];
}

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

int Precedance(char c)
{
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') return 4;
    return 0;
}

char *convert(const char *inf)
{
    char *postfix = new char[strlen(inf)+1];
    char x;
    int j = 0;
    stack s;
    for (int i = 0; inf[i] != '\0'; i++)
    {
        x = inf[i];
        if (x == '(')
        {
            s.push('(');
        }
        else if (x == ')')
        {
            while (s.peek() != '(')
            {
                postfix[j++] = s.pop();
            }
            s.pop();
        }
        else if (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z')
        {
            s.push(x);
        }
        else if (isOperator(x))
        {
            while (!s.isEmpty() && Precedance(x) <= Precedance(s.peek()))
            {
                postfix[j++] = s.pop();
            }
            s.push(x);
        }
    }
    while (!s.isEmpty())
    {
        postfix[j++] = s.pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    const char *infix = "a+b*c";
    char *postfix = convert(infix);
    cout << postfix;
    delete[] postfix;

    return 0;
}