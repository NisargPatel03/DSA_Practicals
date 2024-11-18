#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    cout<<"Enter the string to find the longest word in it: ";
    getline(cin,str);

    int count=0;
    int max_length=0;
    max_length=0;
    for(int i=0; i<str.length(); i++)
    {
           if(str[i]==' ' || str[i]=='.')
        {
            if(count>max_length)
            {
                max_length=count;
            }
            count=0;
            if(str[i]=='.')
            {
                break;
            }
            else
            {
                continue;
            }
        }
        count++;

    }
    cout<<"Maximum Length of the word in the sentence with length is: "<<max_length;

}
