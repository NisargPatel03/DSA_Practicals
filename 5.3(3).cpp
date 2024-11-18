#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int evaluate_postfix(string s)
{
    int ans=0;
    int op1=0;
    int op2=0;
    stack<int> stk;

    for(auto c:s)
    {
        if(isdigit(c))
        {
            stk.push(c- '0');
        }
        else
        {
            if(c=='+')
            {
                op2 = stk.top();
                stk.pop();
                op1 = stk.top();
                stk.pop();
                ans = op1 + op2;
                stk.push(ans);
            }
            else if(c=='-')
            {
                op2 = stk.top();
                stk.pop();
                op1 = stk.top();
                stk.pop();
                ans = op1 - op2;
                stk.push(ans);
            }
            else if(c=='*')
            {
                op2 = stk.top();
                stk.pop();
                op1 = stk.top();
                stk.pop();
                ans = op1*op2;
                stk.push(ans);
            }
            else if(c=='/')
            {
                op2 = stk.top();
                stk.pop();
                op1 = stk.top();
                stk.pop();
                ans = op1/op2;
                stk.push(ans);
            }
            else
            {
                op2 = stk.top();
                stk.pop();
                op1 = stk.top();
                stk.pop();
                ans = pow(op1,op2);
                stk.push(ans);
            }
        }
    }
    return ans;
}
int main()
{
    string s;
    cout<<"Enter the String: ";
    cin>>s;
    int result = evaluate_postfix(s);
    cout<<"Output: "<<result;
}
