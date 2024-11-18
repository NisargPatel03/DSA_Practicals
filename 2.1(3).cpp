#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of elements: ";
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
    {
        cout<<"Element "<<i+1<<": ";
        cin>>arr[i];
    }
    int key;
    for(int i=1; i<n; i++)
    {
        key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
}
