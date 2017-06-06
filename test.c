#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#define MAXLINE 100


int mygetline(char line[],int maxline)
{
	int c,i;
	
	for(i=0;i<maxline-1 &&(c=getchar())!=EOF && c!='\n';++i)
		line[i]=c;
	if(c=='\n')
	{
		line[i]=c;
		++i;
	}
	
	line[i]='\0';
	return i;
}

double myatof(char s[])
{
	double val,power;
	int i,sign;
	for(i=0;isspace(s[i]);i++)
		;
	sign=(s[i]=='-')?-1:1;
	if(s[i]=='+'||s[i]=='-')
		i++;
	for(val = 0.0;isdigit(s[i]);i++)
		val=10.0*val+(s[i]-'0');
	if(s[i]=='.')
		i++;
	for(power=1.0;isdigit(s[i]);i++)
	{
		val=10.0*val+(s[i]-'0');
		power*=10;
	}
	return sign*val/power;
}

int main()
{
	double sum,myaot(char []);
	char line[MAXLINE];
	int mygetline(char line[],int max);
	sum=0;
	while (mygetline(line,MAXLINE)>0)
		printf("\t%g\n",sum+=myatof(line));
	exit(0);
}
