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
    cout<<"Enter the Key to find your desired number: ";
    int key;
    cin>>key;
    for(int i=0; i<size; i++)
    {
        if(arr[i]==key)
        {
            cout<<"Number Found: "<<arr[i];
        }
    }

}
