#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* Link;
        Node()
        {
            data=0;
            Link=NULL;
        }
        Node(int value)
        {
            this->data=value;
            this->Link=NULL;
        }
};

class LinkedLists
{
    private:
        Node* head;
    public:
        LinkedLists()
        {
            head=NULL;
        }
        void insert_at_end(int value)
        {
            Node* temp = new Node(value);
            Node* ptr = head;
            if(head==NULL)
            {
                head=temp;
                //cout<<temp->data<<" Inserted"<<endl;
            }
            else
            {
                while(ptr->Link != NULL)
                {
                    ptr = ptr->Link;
                }
                ptr->Link=temp;
                //cout<<temp->data<<" Inserted"<<endl;
            }
        }
        void insert_at_start(int value)
        {
            Node* temp = new Node(value);
            if(head==NULL)
            {
                head=temp;
                //cout<<temp->data<<" Inserted"<<endl;
            }
            else
            {
                temp->Link=head;
                head=temp;
                //cout<<temp->data<<" Inserted"<<endl;
            }
        }
        void insert_at_specific_location(int value, int position)
        {
            Node* new_node = new Node(value);
            if(position==1)
            {
                new_node->Link=head;
                head=new_node;
                return;
            }
            Node* current = head;
            int current_position = 1;

            while (current != nullptr && current_position < position - 1)
            {
                current = current->Link;
                current_position++;
            }

            if (current == nullptr)
            {
                cout << "Position out of bounds!" << endl;
                return;
            }

            new_node->Link = current->Link;
            current->Link = new_node;
        }
        void delete_from_end()
        {
            if(head==NULL)
            {
                cout<<"Linked Lists is Empty"<<endl;
            }
            else if(head->Link==NULL)
            {
                delete head;
                head=NULL;
            }
            else
            {
                Node* ptr = head;
                Node* ptr1 = head->Link;
                while(ptr1->Link!=NULL)
                {
                    ptr1=ptr1->Link;
                    ptr=ptr->Link;
                }
                ptr->Link=NULL;
                delete ptr1;
            }
        }
        void delete_from_start()
        {
            if(head==NULL)
            {
                cout<<"Linked Lists is Empty"<<endl;
            }
            else if(head->Link==NULL)
            {
                delete head;
                head=NULL;
            }
            else
            {
                Node* ptr = head;
                head = head->Link;
                delete ptr;
            }
        }
        void delete_from_specific_position(int position)
        {
            if (head == nullptr)
            {
                cout << "List is empty!" << endl;
                return;
            }

            if (position == 1)
            {
                Node* temp = head;
                head = head->Link;
                delete temp;
                return;
            }

            Node* current = head;
            Node* previous = nullptr;
            int current_position = 1;

            while (current != nullptr && current_position < position)
            {
                previous = current;
                current = current->Link;
                current_position++;
            }

            if (current == nullptr)
            {
                cout << "Position out of bounds!" << endl;
                return;
            }

            previous->Link = current->Link;
            delete current;
        }
        void display()
        {
            Node* ptr=head;
            int count=0;
            if(head==NULL)
            {
                cout<<"Linked Lists is Empty"<<endl;
            }
            else
            {
                while(ptr!=NULL)
                {
                    cout<<ptr->data<<endl;
                    count++;
                    ptr = ptr->Link;
                }
                cout<<"Total Number of Nodes is: "<<count<<endl;
            }
        }
};

int main()
{
    LinkedLists LL;
    LL.insert_at_start(1);
    LL.insert_at_end(2);
    LL.insert_at_start(3);
    LL.insert_at_end(5);
    LL.display();
    LL.insert_at_specific_location(4,2);
    LL.display();
    LL.delete_from_end();
    LL.display();
    LL.delete_from_start();
    LL.display();
    LL.delete_from_specific_position(2);
    LL.display();
    LL.insert_at_end(8);
    LL.insert_at_end(10);
    LL.display();
}
