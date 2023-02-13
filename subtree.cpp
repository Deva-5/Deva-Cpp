#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
map<int,vector<int>>mp;
vector<int>intime;
vector<int>outtime;
int t=1;

void solve(map<int,vector<int>>&mp,int child,int parent)
{
    intime[child]=t++;
    for(auto x:mp[child])
    {
        if(x!=parent)
        {
            solve(mp,x,child);
        }
    }
    outtime[child]=t++;
}

signed main()
{
    cin>>n;
    intime.resize(n+1);
    outtime.resize(n+1);
    vector<int>v(n+1);
    for(int i=2;i<=n;i++)
    {
        cin>>v[i];
        mp[v[i]].push_back(i);
        mp[i].push_back(v[i]);
    }
    int p=1;
    solve(mp,p,-1);
    for(int i=1;i<=n;i++)
    {
        cout<<(outtime[i]-intime[i])/2<<" ";
    }
}
