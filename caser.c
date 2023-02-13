#include<stdio.h>
#include<string.h>
int main()
{
    char msg[100],ch;
    int k;
    printf("Enter the message:");
    gets(msg);
    printf("Enter the key size:");
    scanf("%d",&k);
    int n=strlen(msg);
    for(int i=0;i<n;i++)
    {
        ch=msg[i];
        if(ch>='a' && ch<='z')
        {
            ch=ch+k;
            if(ch>'z')
            {
                ch=ch%'z'+'a';
            }
            msg[i]=ch;
        }
        else if(ch>='A' && ch<='Z')
        {
            ch=ch+k;
            if(ch>'Z')
            {
                ch=ch%'Z'+'A';
            }
            msg[i]=ch;
        }
    }
    printf("Encrypted message:%s",msg);
}