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
    int min_index;
    for(int i=0; i<n-1; i++)
    {
        min_index=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index=j;
            }
        }
        if(min_index!=i)
        {
            int temp;
            temp=arr[i];
            arr[i]=arr[min_index];
            arr[min_index]=temp;
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
}
