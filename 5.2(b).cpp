#include<iostream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

class Queue
{
    private:
        Node* front;
        Node* rear;
    public:
        Queue()
        {
            front=nullptr;
            rear=nullptr;
        }
        bool isEmpty()
        {
            if (front == nullptr)
            {
                return true;
            }
            return false;
        }
        void enqueue(int x)
        {
            Node* temp=new Node();
            temp->data=x;
            temp->next=nullptr;
            if(isEmpty())
            {
                front=rear=temp;
            }
            else
            {
                rear->next=temp;
                rear=temp;
            }
        }

        int dequeue()
        {
            if(isEmpty())
            {
                cout<<"Queue is Empty"<<endl;
                return -1;
            }
            Node* temp=front;
            int deleted_ele = front->data;
            front=front->next;

            if(front==nullptr)
            {
                rear=nullptr;
            }
            delete temp;
            return deleted_ele;
        }

        int peek()
        {
            if(isEmpty())
            {
                cout<<"Queue is Empty"<<endl;
                return -1;
            }
            return front->data;
        }

        void display()
        {
            if(isEmpty())
            {
                cout<<"Queue is Empty"<<endl;
            }
            Node* temp=front;
            while(temp!=nullptr)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
};

int main()
{
    Queue q;
    q.enqueue(3);
    q.enqueue(70);
    q.enqueue(1);
    q.display();
    cout<<endl;
    q.dequeue();
    q.display();
    cout<<endl;
    q.peek();
    q.display();
}
