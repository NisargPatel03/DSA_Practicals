#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* link;
        Node(int x)
        {
            data=x;
            link=nullptr;
        }
};

Node* mergeTwoll(Node* L1, Node* L2)
{
    Node* L3;
    if(L1==nullptr)
    {
        return L2;
    }
    if(L2==nullptr)
    {
        return L1;
    }

    if(L1->data<=L2->data)
    {
        L3=L1;
        L3->link = mergeTwoll(L1->link, L2);
    }
    else
    {
        L3=L2;
        L3->link = mergeTwoll(L1, L2->link);
    }
    return L3;
}

int main()
{
    Node* a = new Node(1);
    a->link = new Node(3);
    a->link->link = new Node(4);

    Node* b = new Node(1);
    b->link = new Node(2);
    b->link->link = new Node(5);

    Node* c = mergeTwoll(a, b);

    Node* ptr = c;
    while(ptr!=nullptr)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->link;
    }

}
