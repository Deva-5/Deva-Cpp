#include<bits/stdc++.h>
using namespace std;

int main()
{
    int rails,count,len,code[100][100],j=0;
    string str;
    cout<<"Enter a secret message:\n";
    cin>>str;
    cout<<"Enter number of rails:\n";
    int n=str.size();
    cin>>rails;
    /*for(int i=0;i<rails;i++)
    {
        for(int j=0;j<n;j++)
        {
            code[i][j]=0;
        }
    }*/
    count=0;
    while(j<n)
    {
        if(count%2==0)
        {
            for(int i=0;i<rails;i++)
            {
                code[i][j]=(int)str[j];
                j++;
            }
        }
        else
        {
            for(int i=rails-2;i>=0;i--)
            {
                code[i][j]=(int)str[j];
                j++;
            }
        }
        count++;
    }
    for(int i=0;i<rails;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(code[i][j]!=0){
            cout<<(char)code[i][j];}
        }
    }
}