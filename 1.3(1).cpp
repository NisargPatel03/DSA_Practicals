#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[],int target,int n)
{
    int mid,left,right;
    left=0;
    right=n-1;
    while(left<=right)
    {

        mid=(left + right)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]<target)
        {
            left=mid+1;

        }
        else
        {
            right=mid-1;

        }
    }
     return -1;
}

int main()
{
    int n;
    cout<<"Enter the size of an array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<"Enter the element to find it in the array:";
    int target;
    cin>>target;
    int answer;
    answer=binarysearch(arr,target,n);
    cout<<answer;
}
