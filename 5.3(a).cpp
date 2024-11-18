#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string str;
    cout<<"Enter the String: ";
    cin>>str;
    stack<char> stk;
    bool isValidString=true;

    for(char c:str)
    {
        switch(c)
        {
            case '(':
            case '{':
            case '[':
                stk.push(c);
                break;

            case ')':
                if(stk.empty() || stk.top()!='(')
                    {
                        isValidString=false;
                    }
                else
                    {
                        stk.pop();
                    }
                    break;
             case '}':
                if(stk.empty() || stk.top()!='{')
                    {
                        isValidString=false;
                    }
                else
                    {
                        stk.pop();
                    }
                    break;
            case ']':
                if(stk.empty() || stk.top()!='[')
                    {
                        isValidString=false;
                    }
                else
                    {
                        stk.pop();
                    }
                    break;

            default:
                isValidString=false;
        }
        if(!isValidString)
            break;
    }
    if(isValidString==true && stk.empty())
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }

}

