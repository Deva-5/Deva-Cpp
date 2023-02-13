#include <bits/stdc++.h>

using namespace std;

int main() {
  cout<<"Enter No of productions\n";
int n;
cin>>n;
n=n+1;
vector<string>v;
unordered_map<char,vector<int>>m;
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

        string s;
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
      cout<<(char)e<<" ";

      cout<<"]";
      cout<<"\n";
}//m has first;

unordered_map<char,vector<int>>m1;
//m1 will be having follow data;
m1['S'].push_back('$');
for(int i=0;i<n;i++)
{
    for(int j=3;j<v[i].size();j++)
    {
        if(isupper(v[i][j]))
        {  char c=v[i][j];
            if(islower(v[i][j+1]) and j+1<v[i].size())
            {
                m1[c].push_back(v[i][j+1]);//terminal right
            }
            else if(isupper(v[i][j+1]) and j+1<v[i].size())
            {
                char a=v[i][j+1];//non terminal right
                for(auto p:m)
                 {
                 if(p.first==a)
                  {
                   for(auto e:p.second)
                   {
                    m1[c].push_back(e);
                   }
                  }

                 }

            }

        }

    }
}
for(int i=0;i<n;i++)
{
               if(isupper(v[i][v[i].size()-1]))
               {

               char c=v[i][v[i].size()-1];
                for(auto p:m1)
                {
                    if(p.first==v[i][0])
                      {
                          for(auto e:p.second)
                          {
                              m1[c].push_back(e);
                          }
                      }
                }
               }

}
//printing the follow
cout<<"NonTerminal "<<" Follow\n";
for(auto p:m1)
{
    cout<<p.first<<"\t\t";
    cout<<"[";
     for(auto e:p.second)
      cout<<(char)e<<" ";

      cout<<"]";
      cout<<"\n";
}

//LL(1) or Top Down parsing
//for LL(1) parsing check whether any Non terminal has same element in first and follow and also has '@'(null)
//if yes then it does not satisfy the LL(1) parsing else if satisfies LL(1) parsing
//if asked to build table then just print first and follow according to production
set<char>a;
//first pushing the first values of then taking follow values for each non terminal
bool b=false;
//b to check ll(1) or not
for(int i=0;i<n;i++)
{ bool f=false;
//f to check the presence of '@'(null)
    char c=v[i][0];
    for(auto p:m)
    {
        if(p.first==c)
        {
            for(auto e:p.second)
            {
                a.insert(e);
                if(e=='@')
                  f=true;
            }
        }
    }
    if(f)
    {
        for(auto p:m1)
         {
        if(p.first==c)
           {
            for(auto e:p.second)
            {
               if(a.find(e)!=a.end())
               {
                   b=true;
                   break;
               }
            }
            if(b==true)
               break;
           }
       }
       if(b==true)
               break;

    }
    a.clear();
  }
  if(b==true)
    cout<<"Given Grammar not suitable for LL(1) Parsing\n";
    else
    cout<<"Given grammar is suitable for LL(1) Parsing\n";
}

// Output

// Enter No of productions
// 4
// Enter the productions
// S->aA
// A->BcbC
// B->dAS
// C->cB
// NonTerminal  First
// A               [d ]
// C               [c ]
// B               [d ]
//                 [  ]
// S               [a ]
// NonTerminal  Follow
// C               [a $ ]
// A               [a $ ]
// S               [$ c ]
// B               [c a $ ]
// Given grammar is suitable for LL(1) Parsing


