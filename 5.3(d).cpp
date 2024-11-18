#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void generatebinarynum(int n)
{
    queue<string> q;
    q.push("1");

    while(n--)
    {
        string s1 = q.front();
        q.pop();
        cout<<s1<<endl;

        string s2 = s1;

        q.push(s1.append("0"));

        q.push(s2.append("1"));
    }
}
int main()
{
    cout<<"Enter the number to get its binary number from 1: ";
    int n;
    cin>>n;

    generatebinarynum(n);
}
