#include<iostream>
using namespace std;
# define MAX 10
int top=-1;
int a[MAX];
void push(int value)
{
    if(top>=MAX-1)
        cout<<"Stack is Full";
    else
    {
        top++;
        a[top]=value;
    }
}

void pop()
{
    if(top==-1)
        cout<<"Stack is Empty";
    else
    {
        cout<<"Deleted Element is: "<<a[top];
        top--;
    }
}

void peek()
{
    cout<<a[top];
}

void print()
{
    for(int i=top; i>=0; i--)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    push(10);
    cout<<endl;
    push(3);
    cout<<endl;
    peek();
    cout<<endl;
    print();
    cout<<endl;
    pop();
}
