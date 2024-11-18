#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of an array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Element "<<i+1<<": ";
        cin>>arr[i];
    }
    int max=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    int countarray[max+1];
    for(int i=0; i<max+1; i++)
    {
        countarray[i]=0;
    }
    for(int i=0; i<n; i++)
    {
        countarray[arr[i]]++;
    }
    for(int i=1; i<max+1; i++)
    {
        countarray[i] = countarray[i] + countarray[i-1];
    }
    cout<<endl;
    int outputarray[n];
    for(int i=n-1; i>=0; i--)
    {
        outputarray[countarray[arr[i]]-1] = arr[i];
        countarray[arr[i]]--;
    }
    cout<<"Sorted array is: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"Element "<<i+1<<": "<<outputarray[i]<<endl;
    }
}
