#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,k;
    cout<<"Enter the mesaage:";
    cin>>s;
    cout<<"Enter the key:";
    cin>>k;
    int n=k.size();
    for(int i=0; ;i++)
    {
        if(n==i)
        {
            i=0;
        }
        if(k.size()==s.size())
        {
            break;
        }
        else
        {
            k.push_back(k[i]);
        }
    }
    string ans="";
    for(int i=0;i<s.size();i++)
    {
        ans+=(s[i]+k[i])%26+'A';
    }
    cout<<"Cipher Text:"<<ans<<'\n';
    string ans1="";
    for(int i=0;i<s.size();i++)
    {
        ans1+=(ans[i]-k[i]+26)%26+'A';
    }
    cout<<"Decrypted Text:"<<ans1<<'\n';
}
