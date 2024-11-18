#include<iostream>
#include<stack>
using namespace std;

class Node
{
    public:
        int data;
        Node* Link;
};
class SLL
{
    private:
        Node* head;
        stack<int> stk;
    public:
        SLL()
        {
            head=nullptr;
        }
        void add_element(int x)
        {
            Node* temp=new Node();
            Node* ptr;
            temp->data=x;
            temp->Link=nullptr;
            if(head==nullptr)
            {
                head = temp;
            }
            else
            {
                ptr=head;
                while(ptr->Link!=nullptr)
                {
                    ptr = ptr->Link;
                }
                ptr->Link = temp;
            }
        }
        void reverse_LL()
        {
            Node* rev;
            rev = head;
            while(rev->Link!=nullptr)
            {
                stk.push(rev->data);
                rev = rev->Link;
            }
            stk.push(rev->data);

            rev = head;
            while(rev!=nullptr)
            {
               // int item = rev->data;
                rev->data = stk.top();
                stk.pop();
                rev = rev->Link;
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
                    print = print->Link;
                }
            }
        }
};

int main()
{
    SLL s;
    s.add_element(1);
    s.add_element(2);
    s.add_element(3);
    s.add_element(4);
    s.add_element(5);
    cout<<"Linked Lists: ";
    s.print();
    cout<<endl;
    s.reverse_LL();
    cout<<"Reversed Linked Lists: ";
    s.print();
}
