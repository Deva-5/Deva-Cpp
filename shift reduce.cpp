#include <bits/stdc++.h>

using namespace std;

string s,ac,sh;
int n=0,i=0,z=0,j=0;
char stk[100]={'\0'};

void check()
{
	ac="REDUCE TO E";
	for(z=0;z<n;z++)
	{
		if(stk[z]=='i' and stk[z+1]=='d')
		{
			stk[z]='E';
			stk[z+1]='\0';
			cout<<"$"<<stk<<'\t';
			cout<<s<<"$"<<'\t';
			cout<<ac<<'\n';
			i++;
		}
	}
	for(z=0;z<n;z++)
	{
		if(stk[z]=='E' and stk[z+1]=='+' and stk[z+2]=='E')
		{
			stk[z]='E';
			stk[z+1]='\0';
			stk[z+2]='\0';
			cout<<"$"<<stk<<'\t';
			cout<<s<<"$"<<'\t';
			cout<<ac<<'\n';
			j-=2;
		}
	}
	for(z=0;z<n;z++)
	{
		if(stk[z]=='E' and stk[z+1]=='*' and stk[z+2]=='E')
		{
			stk[z]='E';
			stk[z+1]='\0';
			stk[z+2]='\0';
			cout<<"$"<<stk<<'\t';
			cout<<s<<"$"<<'\t';
			cout<<ac<<'\n';
			j-=2;
		}
	}
}


int main() {
	cout<<"Enter the expression:\n";
	cin>>s;
	sh="SHIFT->";
	n=s.size();
	cout<<"stack\t"<<"Input\t"<<"action\n";
	for(i=0,j=0;i<n;i++,j++)
	{
		if(s[i]=='i' and s[i+1]=='d')
		{
			stk[j]=s[i];
			stk[j+1]=s[i+1];
			stk[j+2]='\0';
			s[i]='\0';
			s[i+1]='\0';
			cout<<"$"<<stk<<'\t';
			cout<<s<<"$"<<'\t';
			cout<<sh<<"id\n";
			check();
		}
		else
		{
			stk[j]=s[i];
			stk[j+1]='\0';
			s[i]='\0';
			cout<<"$"<<stk<<'\t';
			cout<<s<<"$"<<'\t';
			cout<<sh<<"Symbol"<<'\n';
			check();
		}
	}
	return 0;
}
