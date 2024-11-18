#include<iostream>
using namespace std;

class Queue{
    int arr[10];
    int f,r;
    int n=sizeof(arr)/sizeof(arr[0]);

   public:
       Queue()
       {
           f=-1;
           r=-1;
       }
    void enqueue(int val)
    {
        if(r==n-1)
        {
            cout<<"Queue is Full";
        }
        else
        {
            if(f==-1 && r==-1)
            {

                f=0;
                r=0;
                arr[r]=val;
            }
            else{
                 r++;
                arr[r]=val;
            }

        }
    }
    void dequeue()
    {
        if(f==-1 && r==-1)
        {
            cout<<"Queue is Empty";
        }
        else if(r<f)
        {
            cout<<"Queue is Empty";
        }
        else{
            cout<<arr[f];
            f++;
        }
    }
};


int main()
{
   Queue q1;
    int q,x;
    cout<<"Enter number Of Times query: ";
    int y;
    cin>>y;

    int m=0;
    while(m<y)
    {
        cout<<"Type Of Query: ";
        cin>>q;

        if(q==1)
        {
            cin>>x;
            m++;
            q1.enqueue(x);
            cout<<endl;
        }
        else if(q==2)
        {
            m++;
            q1.dequeue();
            cout<<endl;
        }
        else{
            break;
        }
    }
}
