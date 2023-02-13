#include<bits/stdc++.h>
using namespace std;


int n;
map<int,vector<int>>mp;
vector<int>intime;
vector<int>outtime;
vector<int>v;
int t=1;

void solve(map<int,vector<int>>mp,int par,int child)
{
    intime[par]=t++;
    for(auto x:mp[par])
    {
        if(x!=par)
        {
            solve(mp,x,par);
        }
    }
    outtime[par]=t++;
}

int main()
{
    cin>>n;
    intime.resize(n+1);
    outtime.resize(n+1);
    v.resize(n+1);
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        mp[v[i]].push_back(i);
        mp[i].push_back(v[i]);
    }
    int p=1;
    for(auto x:mp[p])
    {
        solve(mp,p,x);
    }
    for(int i=1;i<n;i++)
    {
        cout<<(outtime[i]-intime[i])/2<<'\n';
    }
}
