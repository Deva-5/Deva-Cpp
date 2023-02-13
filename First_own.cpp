#include <bits/stdc++.h>

using namespace std;

int main() {
  cout<<"Enter No of productions\n";
int n;
cin>>n;
string x;getline(cin,x);
vector<string>v;
unordered_map<char,vector<char>>m;
cout<<"Enter the productions\n";
//Each production should be entered separately
// use @ for null operator
 for(int i=0;i<n;i++)
 {
    string s;
    getline(cin,s);
    v.push_back(s);
    //first position terminals S-> so starting from index 3
   if(!isupper(s[3]))
     m[s[0]].push_back(s[3]);
 }
 for(int i=0;i<n;i++)
{ //Pushing the first of non terminal
  if(isupper(v[i][3]))
    {
        char c=v[i][3];
        for(auto p:m)
        {
            if(p.first==c)
            {
               for(auto e:p.second)
               {
                  m[v[i][0]].push_back(e);
               }
            }
        }
    }
}
cout<<"NonTerminal "<<" First\n";
for(auto p:m)
{
    cout<<p.first<<"\t\t";
    cout<<"[";
     for(auto e:p.second)
      cout<<e<<" ";
      cout<<"]";
      cout<<"\n";
}
}
