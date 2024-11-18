#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int counter(int arr[], int n, int target)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=target)
        {
            ans++;
        }
    }
    return ans;
}
int binarysearch(int arr[], int n)
{
    int left=0;
    int right=n;
    while(left<=right)
    {
        int mid = (left+right)/2;
        int ans = counter(arr,n,mid);

        if(ans==mid)
        {
            return ans;
        }
        else if(ans>mid)
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
    for(int X=0; X<n; X++)
    {
        cin>>arr[X];
    }
    sort(arr,arr+n);
    int result = binarysearch(arr,n);
    cout<<"Result: "<<result;
}
