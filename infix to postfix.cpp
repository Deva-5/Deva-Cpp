#include<bits/stdc++.h>

using namespace std;

int pri(char x)
{
    if(x=='(')
         return 0;
    if(x=='+' or x=='-')
          return 1;
    if(x=='*' or x=='/')
          return 2;
    return -1;
}
int main()
{
 stack<char>st;
 string s;
 cout<<"Enter the infix\n";
 cin>>s;
 for(int i=0;i<s.size();i++)
 {
     if(isalpha(s[i]))
            cout<<s[i];
     else if(s[i]=='(')
            st.push(s[i]);
     else if(s[i]==')')
     {
        while(st.top()!='(')
        {
            cout<<st.top();
            st.pop();
        }
        st.pop();
     }
     else
     {
        while(!st.empty() && pri(s[i]) <= pri(st.top()))
        {
            cout<<st.top();
            st.pop();

        }
        st.push(s[i]);
     }
 }
  while(!st.empty())
  {
    cout<<st.top();
    st.pop();
  }

}

//Output



