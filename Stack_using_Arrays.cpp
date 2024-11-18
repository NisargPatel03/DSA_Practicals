#include<iostream>
using namespace std;
#define MAX 100

class Stack
{
    private:
        int top;
    public:
        int a[MAX];
        Stack()
        {
            top=-1;
        }
        void push(int value)
        {
            if(top>=MAX-1)
                cout<<"Stack is Full";
            else
            {
                top++;
                a[top]=value;
                cout<<"Inserted Element is: "<<value<<endl;
            }
        }
        void pop()
        {
            if(top==-1)
                cout<<"Stack is Empty";
            else
            {
                cout<<"Deleted Element is: "<<a[top]<<endl;
                top--;
            }
        }
        void peek()
        {
            if(top<0)
                cout<<"Stack is Empty";
            else
                cout<<"Peek Element is: "<<a[top]<<endl;
        }
        void print()
        {
            for(int i=top; i>=0; i--)
            {
                cout<<a[i]<<endl;
            }
        }

};

int main()
{
    Stack S;
    S.push(10);
    S.push(3);
    S.push(11);
    S.push(29);
    S.pop();
    S.peek();
    S.push(14);
    S.print();
}
