#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;
};

class DLL
{
    private:
        Node* head;
    public:
        DLL()
        {
            head=nullptr;
        }
        void insert_at_first(int x)
        {
            Node* temp = new Node();
            temp->data=x;
            temp->next=nullptr;

            if(head==nullptr)
            {
                head=temp;
                temp->next=nullptr;
            }
            else if(head->next==nullptr)
            {
                temp->next=head;
                head->prev=temp;
                head=temp;
            }
            else
            {
                temp->next=head;
                head->prev=temp;
                head=temp;
            }
        }
        void insert_at_last(int x)
        {
            Node* newnode=new Node();
            newnode->data=x;
            newnode->next=nullptr;
            Node* temp;
            temp=head;
            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
            newnode->next=nullptr;
        }
        void insert_at_any_position(int x, int pos)
        {
            Node* newnode=new Node();
            newnode->data=x;
            newnode->next=nullptr;
            if(head)
            {
                Node* t1=head;
                Node* t2=nullptr;

                for(int i=1; i<pos; i++)
                {
                    t2=t1;
                    t1=t1->next;
                }
                newnode->prev=t2;
                t2->next=newnode;
                newnode->next=t1;
                t1->prev=newnode;
            }
        }
        void delete_from_first()
        {
            Node* ptr=head;
            if(head->next==nullptr)
            {
                delete head;
                head=nullptr;
            }
            else
            {
                head=ptr->next;
                head->prev=nullptr;
                ptr->next=nullptr;
                delete ptr;
            }
        }
        void delete_from_any_position(int pos)
        {
            Node* ptr=head;
            //cout<<ptr->data;
            for(int i=1; i<pos; i++)
            {
                ptr=ptr->next;
            }

            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
        }
        void delete_from_last()
        {
            Node* ptr;
            if(head==nullptr)
            {
                delete head;
                head=nullptr;
            }
            else
            {
                ptr=head;
                while(ptr->next->next!=nullptr)
                {
                    ptr=ptr->next;
                }
                delete ptr->next;
                ptr->next=nullptr;
            }
        }
        void print()
        {
            Node* print;
            print = head;
            if(head)
            {
                while(print!=nullptr)
                {
                    cout<<print->data<<" ";
                    print = print->next;
                }
            }
        }
        ~DLL()
        {
            if(head)
            {
                while(head->next!=nullptr)
                {
                    head=head->next;
                }
            }

        }
};

int main()
{
    DLL d;
    d.insert_at_first(1);
    d.insert_at_first(2);
    d.insert_at_first(3);
    d.print();
    cout<<endl;
    d.delete_from_last();
    d.print();
    cout<<endl;
    d.insert_at_first(4);
    d.print();
    d.insert_at_last(10);
    d.insert_at_last(12);
    cout<<endl;
    d.print();
    cout<<endl;
    d.insert_at_any_position(15,3);
    d.print();
    cout<<endl;
    d.delete_from_first();
    d.delete_from_first();
    d.print();
    cout<<endl;
    d.delete_from_any_position(3);
    d.print();
}
