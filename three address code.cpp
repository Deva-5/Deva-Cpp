 #include <bits/stdc++.h>

using namespace std;

int main() 
{
    string s;
    char j='A';
    cout<<"Enter the Expression:\n";
    cin>>s;
    cout<<"Three address code:\n";
    int i=2,n,h;
    n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='*' || s[i]=='/')
        {
            cout<<j<<"="<<s[i-1]<<s[i]<<s[i+1]<<"\n";
            s[i-1]=j++;
            for(h=i;h<n-1;h++)
              s[h]=s[h+2];
              n-=2;
              i-=1;
        }
    }
     for(int i=2;i<n;i++)
    {
        if(s[i]=='+' || s[i]=='-')
        {
            cout<<j<<"="<<s[i-1]<<s[i]<<s[i+1]<<"\n";
            s[i-1]=j++;
            for(h=i;h<n-1;h++)
              s[h]=s[h+2];
              n-=2;
              i-=1;
        }
    }
    cout<<s[0]<<"="<<s[2]<<"\n";
}

//input
// a=b*c+g/e*f*h

// Output

// Enter the Expression
//  a=b*c+g/e*f*h
// Three address code:
// A=b*c
// B=g/e
// C=B*f
// D=C*h
// E=A+D
// a=E
