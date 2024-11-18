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
        bool palindrome_LL()
        {
            Node* palindrome;
            palindrome = head;
            while(palindrome->Link!=nullptr)
            {
                stk.push(palindrome->data);
                palindrome = palindrome->Link;
            }
            stk.push(palindrome->data);

            palindrome = head;
            while(palindrome!=nullptr)
            {
                if(palindrome->data != stk.top())
                    {
                        return false;
                    }
                    stk.pop();
                    palindrome = palindrome->Link;
            }
            return true;
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
    s.add_element(2);
    s.add_element(1);
    //s.add_element(5);
    cout<<"Linked Lists: ";
    s.print();
    cout<<endl;
    cout<<s.palindrome_LL();

}
