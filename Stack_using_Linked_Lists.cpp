#include<iostream>
using namespace std;
class Node
{
public:
    int item;
    Node* Link;
};
class Singly_LL
{
private:
    Node* top=NULL;
public:
    void insert_new_node(int data)
    {
       Node* temp = new Node();
       temp->item = data;
       temp->Link = NULL;
       if(top==NULL)
       {
           top=temp;
       }
       else
       {
           temp->Link = top;
           top = temp;
       }
    }

    void pop()
    {
        Node* temp;
        if(top==NULL)
        {
            temp = top;
            top = temp->Link;
            delete temp;
        }
        if(top->Link==NULL)
        {
            delete top;
            top=NULL;
        }
    }

    void print()
    {
        Node* temp;
        temp=top;
        while(temp!=nullptr)
        {
            cout<<temp->item<<" ";
            temp=temp->Link;
        }
    }
};
int main()
{
    Singly_LL S;
    S.insert_new_node(5);
    S.insert_new_node(5);
    S.insert_new_node(5);
    S.insert_new_node(5);
    S.insert_new_node(5);
    S.print();
    cout<<endl;
    S.pop();
    S.pop();
    S.pop();
    //S.pop();
    S.print();
}

