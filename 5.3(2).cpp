#include<iostream>
#include<stack>
#include <string>
using namespace std;

int pres(char c)
    {
        switch(c)
        {
            case '^': return 4;
            case '*': return 3;
            case '/': return 3;
            case '+': return 2;
            case '-': return 1;
            default : return 0;
        }
}

string postfix(string s)
{
    string ans="";
    stack<char> stk;
    for(auto x:s)
    {
        if(x=='(')
        {
            stk.push(x);
        }
        else if(isalnum(x))
        {
            ans+=x;
        }
        else if(x==')')
        {

            while(!stk.empty() && stk.top()!='(')
            {
                ans+=stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            while(!stk.empty() && pres(stk.top())>=pres(x))
            {
                ans+=stk.top();
                stk.pop();
            }
            stk.push(x);
        }

    }
    while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }
return ans;

}
int main()
{

    string s;
    cout<<"Enter String :";
    cin>>s;
    string result=postfix(s);
    cout<<"OUTPUT :"<<result;
}

