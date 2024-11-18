#include<iostream>
#include<algorithm>
using namespace std;

int *linear_sort(int *a,int n)
{
    int temp=-1;
    for(int i=1;i<n;i++)
    {
        if(a[i-1]>a[i]){
        if(temp==-1) temp=i-1;
        else{
            if(i==n-1) break;
            swap(a[temp],a[i]);
            return a;
        }
        }
    }
    if(temp!=-1) swap(a[temp],a[n-1]);
    return a;
}

int main()
{
    int n;
    cout<<"Enter number of elements present in array:";
    cin>>n;
    int *v=new int[n];
    cout<<"Enter elements:";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    v=linear_sort(v,n);
    cout<<"Sorted array:";
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
}

