#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int x,y;
        vector<int>in(n),out(n);
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            in[i]=x;
            out[i]=y;
        }
        vector<pair<int,int>>v;
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(in[i+1]<=out[j])
            {
                int a=in[i];
                while(in[i+1]<=out[j])
                {
                    i++;j++;
                }
                v.push_back({a,out[j]});
            }
            if(in[i+1]>out[j])
            {
                v.push_back({in[i],out[j]});
            }
            j++;
        }
        for(int i=0;i<v.size();i++)
        {
            cout<<"("<<v[i].first<<", "<<v[i].second<<")"<<" ";
        }
        cout<<'\n';
    }
}
