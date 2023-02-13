#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q,x,y;
    cout<<"Enter the value of n & q:";
    cin>>n>>q;
    cout<<"Enter the value of x:";
    cin>>x;
    int a=pow(n,x);
    a=a%q;
    cout<<"Enter the value of y:";
    cin>>y;
    int b=pow(n,y);
    b=b%q;
    cout<<"Key for the first person:"<<a<<'\n';
    cout<<"Key for the first person:"<<b<<'\n';
}