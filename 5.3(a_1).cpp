#include<iostream>
#include<stack>
using namespace std;
bool isValid(string s)
{
      stack<char> stk;
      for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            stk.push(s[i]);
        }
        else if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
            if(stk.empty())
                return 0;
            else if(stk.top()=='(' && s[i]==')')
                stk.pop();
            else if(stk.top()=='{' && s[i]=='}')
                stk.pop();
            else if(stk.top()=='[' && s[i]==']')
                stk.pop();
            else
                return 0;
        }
    }
    return stk.empty();
}
int main()
{
    string str;
    cout<<"Enter the String: ";
    cin>>str;
    cout<<isValid(str);
}
