#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter the size of array: ";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Element "<<i+1<<": ";
        cin>>arr[i];
    }
    bool result;
    for(int i=0; i<n-1; i++)
    {
        result=false;
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                result=true;
            }
        }
        if(result==false)
        {
            break;
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
}
