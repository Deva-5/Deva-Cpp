#include<bits/stdc++.h>
using namespace std;

int isValid(string s)
{
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        if(st.empty())
        {
            st.push(s[i]);
        }
        else if(s[i]==')' or s[i]==']' or s[i]=='}')
        {
            if(st.top()=='(' and s[i]==')')
            {
                st.pop();
            }
            else if(st.top()=='[' and s[i]==']')
            {
                st.pop();
            }
            else if(st.top()=='{' and s[i]=='}')
            {
                st.pop();
            }
        }
        else
        {
            st.push(s[i]);
        }
    }
    if(st.empty())
    {
        return 1;
    }
    return 0;
}

int main()
{
    string s;cin>>s;
    int x=isValid(s);
    if(x==1)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
}
