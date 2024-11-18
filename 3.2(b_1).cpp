#include<iostream>
using namespace std;

class Node
{
public:
    int item;
    Node* next;

};
class a
{

private:
    Node* head;

public :
    a()
    {
        head=nullptr;

    }
    void insert(int x)
        {
            Node* temp;
            Node* t=new Node();
            t->item=x;
            t->next=nullptr;

            if(head==nullptr)
            {
                head=t;
            }
            else
            {
                temp=head;
                while(temp->next!=nullptr)
                {
                    temp=temp->next;
                }
                temp->next=t;

            }
        }
    Node* reverseList(Node* head) {

    Node *curr = head, *prev = nullptr, *next;


    while (curr != nullptr) {

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
    bool palindrom()
    {
        int c=0;

        Node* t;
        t=head;
        if(head)
        {
            while(t->next!=nullptr)
            {
                c++;
                t=t->next;
            }

        }
        t=head;
        Node* head1;
        Node* t2;
        if(c%2==0)
        {
            //int mid=c/2;
            for(int i=0;i<c/2;i++)
            {
                t=t->next;
            }
            head1=t;
            t2=reverseList(head1);
            t=head;
            while(t->next!=t2)
            {
                if(t->item!=t2->item
                   )
                {
                    return false;
                }
                t=t->next;
                t2=t2->next;
            }
        }
        if(c%2==1)
        {
            for(int i=0;i<(c+1)/2;i++)
            {
                t=t->next;
            }
            head1=t;
            t2=reverseList(head1);
            t=head;
            while(t->next->next!=t2)
            {
                if(t->item!=t2->item
                   )
                {
                    return false;
                }
                t=t->next;
                t2=t2->next;
            }
        }

        return true;

    }

};
int main()
{
    a a1;
    a1.insert(1);
    a1.insert(2);
    a1.insert(2);
    a1.insert(1);
    a1.insert(1);
    cout<<a1.palindrom();
}
