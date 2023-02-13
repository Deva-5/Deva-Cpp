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
        if(msg[i]>='a' && msg[i]<='z')
        {
            msg[i]=msg[i]-'a';
            msg[i]=(msg[i]-k)%26+'a';
        }
        else if(msg[i]>='A' && msg[i]<='Z')
        {
            msg[i]=msg[i]-'A';
            msg[i]=(msg[i]-k)%26+'A';
        }
    }
    printf("Decrypted message:%s",msg);
}