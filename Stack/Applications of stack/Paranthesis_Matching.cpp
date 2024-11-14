#include <iostream>
#include <string.h>
using namespace std;

struct stack
{
    int size;
    int top;
    char *s;
};

void create(struct stack *st)
{
    cout << "Enter the size of the stack: ";
    cin >> st->size;
    st->s = new char[st->size];
    st->top = -1;
}

void Display(struct stack st)
{
    for (int i = st.top; i >= 0; i--)
    {
        cout << st.s[i] << " ";
    }
    cout << endl;
}

int isEmpty(struct stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}

int isFull(struct stack st)
{
    if (st.top == st.size - 1)
        return 1;
    return 0;
}

void push(struct stack *st, char x)
{
    if (st->top == st->size - 1)
    {
        cout << "stack overflow\n";
        return;
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        cout << "stack underflow\n";
        return x;
    }
    else
    {
        x = st->s[st->top];
        st->top--;
        return x;
    }
}

int peek(struct stack st,int pos){
    int x=-1;
    if(st.top - pos+1<0){
        cout << "invalid position\n";
    }
    else{
        x = st.s[st.top - pos+1];
    }
    return x;
}

int stackTop(struct stack st){
    int x=-1;
    if(isEmpty(st)){
        cout << "stack underflow\n";
    }
    else{
        x=st.s[st.top];
    }
    return x;
}

int isBalanced(char *exp){
    stack st;
    st.size = strlen(exp);
    st.top= -1;
    st.s = new char[st.size];

    for(int i=0; exp[i] != '\0'; i++){
        if(exp[i]=='('){
            push(&st,'(');
        }
        else if(exp[i]==')'){
            if(isEmpty(st)){
                return 0;
            }
            else{
                pop(&st);
            }
        }
    }
    if(isEmpty(st))
        return 1;
    return 0;
}

int main()
{
    stack st;
    return 0;
}