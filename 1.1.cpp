#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the size of your array: ";
    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    int ar[]={-1,-1,-1,-1,-1,-1};
    int k;
    cin>>k;
    int count;
    int n=sizeof(arr)/sizeof(arr[0]);
    //Checking that given elements are even or not because, if it is even then, pairs formed will be half of it.
    //For odd elements it will not execute code
    if(n%2==1)
    {
        return false;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((arr[i] + arr[j])%k==0 && ar[i]==-1 && ar[j]==-1)
            {
                count++;
                ar[i]=1;
                ar[j]=1;
                cout<<arr[i]<<arr[j]<<endl;
            }
        }
    }
    if(count == n/2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
