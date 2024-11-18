#include<iostream>
using namespace std;
# define MAX 10
int a[MAX];
int front=-1;
int rear=-1;
void Enqueue(int value)
{
    if(rear==MAX-1)
        cout<<"Queue is full";
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        a[rear]=value;
    }
    else
    {
        rear++;
        a[rear]=value;
    }
}
void Dequeue()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is empty";
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        cout<<"Deleted Element is: "<<a[front]<<endl;
        front++;
    }
}
void display()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is empty";
    }
    else
    {
        for(int i=front; i<rear+1; i++)
        {
            cout<<a[i]<<endl;
        }
    }
}
void peek()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is empty";
    }
    else
    {
        cout<<a[front]<<endl;
    }
}

int main()
{
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    display();
    peek();
    Dequeue();
    peek();
    display();
}
