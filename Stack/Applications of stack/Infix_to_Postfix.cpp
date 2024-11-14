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

int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return false;
    return true;
}

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

char * InfixToPostfix(const char * inf){
    int i=0,j=0;
    int len = strlen(inf);
    char * postfix = new char[len+1];
    stack st;

    while(inf[i]!='\0'){
        if(isOperand(inf[i])){
            postfix[j++] = inf[i++];
        }
        else{
            while (!st.isEmpty() && precedence(inf[i]) <= precedence(st.peek())) {
                postfix[j++] = st.pop();
            }
            st.push(inf[i++]);
        }
    }
    while(!st.isEmpty()){
        postfix[j++] = st.pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    const char *infix = "a+b*c";
    char *postfix = InfixToPostfix(infix);
    cout<<postfix;
    delete[] postfix;

    return 0;
}
