#include<bits/stdc++.h>
using namespace std;

vector<int> x4={-1,0,1,0};
vector<int> y4={0,1,0,-1};
int r;
//vector<vector<char>>m;
int bfs(vector<vector<int>>&m)
{
    queue<pair<int,int>>q;
    int c=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<r;j++)
        {
            if(m[i][j]==2)
            {
                q.push({i,j});
            }
            else if(m[i][j]==1)
            {
                c++;
            }
        }
    }
    int time = -1;
    while(!q.empty())
    {
        int l = q.size();
        while(l--)
        {
        	auto x = q.front();
        	q.pop();
        	for(int d=0;d<4;d++)
        	{
            	int ni = x.first+x4[d];
            	int nj = x.second+y4[d];
            	if((ni>=0 and ni<r) and (nj>=0 and nj<r) and m[ni][nj]==1)
            	{
                	c--;
                	q.push({ni,nj});
                	m[ni][nj]=2;
            	}
        	}
        }
    
    return time;
}


int main(){ 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;cin>>t;
   while(t--)
   {
       cin>>r;
       vector<vector<int>>m(r,vector<int>(r));
       char c;
       for(int i=0;i<r;i++)
       {
           for(int j=0;j<r;j++)
           {
           	  cin>>c;
              m[i][j]= c-'0';
           }
       }
       /*for(int i=0;i<r;i++)
       {
           for(int j=0;j<r;j++)
           {
           		cout<<m[i][j];
           }
           cout<<'\n';
       }*/
       int ans = bfs(m);
       cout<<ans<<'\n';
   }
    return 0;
}