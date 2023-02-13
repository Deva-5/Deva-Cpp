#include<bits/stdc++.h>

using namespace std;

int i=0,j=0,z=0,n=0,k=0;
string ac,s,act;
//important to keep stk as char array instead of string
char stk[100];

void check(){

ac ="REDUCE TO E";

for(z=0;z<n;z++)
    if(stk[z]=='i' and stk[z+1]=='d')
    {
        stk[z]='E';
        stk[z+1]='\0';
        cout<<"$"<<stk<<"\t";
        cout<<s<<"$\t";
        cout<<ac<<"\n";
        j++;

    }
for(z=0;z<n;z++)
    if(stk[z]=='E' and stk[z+1]=='+' and stk[z+2]=='E')
    {
        stk[z]='E';
         stk[z+1]='\0';
          stk[z+2]='\0';
        cout<<"$"<<stk<<"\t";
        cout<<s<<"$\t";
        cout<<ac<<"\n";
        i-=2;

    }
for(z=0;z<n;z++)
    if(stk[z]=='E' and stk[z+1]=='*' and stk[z+2]=='E')
    {
        stk[z]='E';
        stk[z+1]='\0';
        stk[z+2]='\0';
        cout<<"$"<<stk<<"\t";
        cout<<s<<"$\t";
        cout<<ac<<"\n";
        i-=2;
    }
}

int main(){
cout<<"Productions are E->E+E,E->E*E,E->id\n";
cout<<"Enter the String\n";
cin>>s;
n=s.size();
act="SHIFT->";
cout<<"stack\t"<<"input\t\t"<<"action\n";
for(i=0,j=0;j<n;i++,j++)
 {
    if(s[j]=='i' and s[j+1]=='d')
    {//for id shift
        stk[i]=s[j];
        stk[i+1]=s[j+1];
        stk[i+2]='\0';
        s[j]=32;
        s[j+1]=32;
        cout<<"$"<<stk<<"\t";
        cout<<s<<"$\t";
        cout<<act<<"id\n";
        check();

    }
        else
        {
            //for +.-.*,/ symbols shift
            stk[i]=s[j];
            stk[i+1]='\0';
            s[j]=32;
            cout<<"$"<<stk<<"\t";
            cout<<s<<"$\t";
            //only change
             cout<<act<<"symbols\n";
        }

    }
}
