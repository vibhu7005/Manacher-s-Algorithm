//highest length substring using manachers algorithm
#include<stdio.h>
#include<string.h>
int min(int a,int b)
{
    if(a<b)
    return a;
    else
    return b;
}
void generate(char *str)
{
    char mod[100];//to modify str for eg. dod into #d#o#g#
    int len=strlen(str);
    len=2*len+1;
    int i,k=0;
    for(i=0;i<len;i++)//modification steps
    {
        if(i%2==0)
            mod[i]='#';
        else
        {
            mod[i]=str[k];
            k++;
        }
    }
    mod[i]='\0';
    int l=strlen(mod);
    int p[l],temp,max=0;//the main array to store 
    getarray(mod,p);
    for(i=0;i<l;i++)
    {
        if(p[i]>max)
        {
            max=p[i];
            temp=i;
        }
    }
    temp=temp/2;//now from modified to main string so divide by 2
    str=str+temp-(max/2);
    str[max]='\0';//to extract the substring;
    printf("%s",str);
}
void getarray(char *str,int p[])
{
    int n=strlen(str),i;
    int c=0,r=-1,rad;//c for centre of palllindrom,r for rightmost pos and rad is radius pallindrom
    for(i=0;i<n;i++)
    {
        if(i<=r)
        {
            rad=min((r-i),p[2*c-i]);
        }
        else
        rad=0;
        while(i+rad<n && i-rad>=0 && str[i-rad]==str[i+rad])//condition of pallindrom
        rad++;
        p[i]=rad-1;
        if((i+rad-1)>r)
        {
            c=i;
            r=i+rad-1;
        }
    }
}
int main()
{
    char str[100];
    printf("enter the string");//user input
    gets(str);
    generate(str);
}
