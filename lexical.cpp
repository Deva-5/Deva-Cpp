#include<bits/stdc++.h>

using namespace std;

int iskw(char buf[])
{
    char k[32][32]={"int","void","return","break","if"};
    int f=0;
    for(int i=0;i<32;i++)
    {
        if(strcmp(k[i],buf)==0)
        {
            f=1;
            break;
        }
    }
    return f;
}

int main()
{
    int  j=0;
    char ch,buf[15],opr[]="+-/*%=";
    ifstream fin("program.txt");
    if(!fin.is_open())
    {
         cout<<"File not Found\n";
    }
    while(!fin.eof())
    {
        ch=fin.get();
        for(int i=0;i<6;i++)
        {
            if(ch==opr[i])
            {
                cout<<ch<<" is a operator\n";
            }
        }
        if(isalnum(ch))
            buf[j++]=ch;
        else if((ch==' ' or ch=='\n') and (j!=0))
        {
            buf[j]='\0';
            j=0;
            if(iskw(buf))
            {
                cout<<buf<<" is a keyword\n";
            }
            else
            {
                cout<<buf<<" is a identifier\n";
            }
        }
    }
    return 0;
}
