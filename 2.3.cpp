#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cout<<"Enter Test Cases: ";
    cin>>t;
    while(t>0)
    {
        int n;
        cout<<"Enter the size of array: ";
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cout<<"Element-"<<i+1<<": ";
            cin>>arr[i];
        }
        sort(arr,arr+n);
        for(int i=1; i<n; i=i+2)
        {
            if(arr[i-1]>arr[i])
            {
                int temp;
                temp=arr[i];
                arr[i]=arr[i-1];
                arr[i-1]=temp;
            }
            if(arr[i+1]>arr[i])
            {
                int temp;
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<endl;
        }
        t--;
    }
}
