#include<stdio.h>
#define MAXLINE 100

int mygetline(char line[],int maxline);
void copy(char to[],char frome[]);

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max=0;
	while((len=mygetline(line,MAXLINE))>0)
		if(len>max)
		{
			max=len;
			copy(longest,line);
		}
	if(max>0)
		printf("%s",longest);
	return 0;
}

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

void copy(char to[],char from[])
{
	int i;
	i=0;
	while((to[i]=from[i])!='\0')
		++i;
}
