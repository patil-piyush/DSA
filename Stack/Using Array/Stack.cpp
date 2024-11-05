#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *s;
};

void create(struct stack *st)
{
    cout << "Enter the size of the stack: ";
    cin >> st->size;
    st->s = new int[st->size];
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

void push(struct stack *st, int x)
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

int main()
{
    stack st;
    create(&st);

    push(&st,10);
    push(&st,4);
    push(&st,6);
    push(&st,5);

    pop(&st);

    cout<<peek(st,10)<<endl;
    cout<<stackTop(st)<<endl;;
    Display(st);
    return 0;
}