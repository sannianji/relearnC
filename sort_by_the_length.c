#include<stdio.h>
#include<string.h>

#define ALLOCSIZE 10000
#define MAXLINES 5000

static char allocbuf[ALLOCSIZE];
char *lineptr[MAXLINES];
static char *allocp=allocbuf;

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);


void qsort(char *lineptr[],int left,int right);

int main()
{
	int nlines;
	if((nlines=readlines(lineptr,MAXLINES))>=0)
	{
		qsort(lineptr,0,nlines-1);
		writelines(lineptr,nlines);
		return 0;
	}
	else
	{
		printf("error: input too big to sort\n");
		return 1;
	}
	
	for(;nlines>=0;nlines--)
		printf("%c\n",*lineptr[nlines]);
	return 0;
}

#define MAXLEN 100
int mygetline(char *,int);
char *alloc(int);

int readlines(char *lineptr[],int maxlines)
{
	int len,nlines;
	char *p,line[MAXLEN];
	nlines=0;
	while((len=mygetline(line,MAXLEN))>0)
		if(nlines>=maxlines||(p=alloc(len))==NULL)
			return -1;
	else
	{
		line[len-1]='\0';
		strcpy(p,line);
		lineptr[nlines++]=p;
	}
	return nlines;
}

void writelines(char *lineptr[],int nlines)
{
	int i;
	for(i=0;i<nlines;i++)
		printf("%s\n",lineptr[i]);
}


char *alloc(int n)
{
	if(allocbuf+ALLOCSIZE-allocp>=n)//out of the buf
	{
		allocp+=n;
		return allocp-n;
	}
	else
		return NULL;
}

void free(char *p)
{
	if(p>=allocbuf&&p<allocbuf+ALLOCSIZE)
		allocp=p;
}

int mygetline(char *line,int number)
{
	int c,i;
	for(i=0;i<number-1&&(c=getchar()!=EOF)&&c!='\n';i++)
	{
		line[i]=c;
	}
	if(c=='\n')
	{
		line[i++]=c;
	}
	line[i]='\0';
	return i;
}

void qsort(char *v[],int left,int right)
{
	if(left>=right)
		return;
	
	int i,last;
	void swap(char *v[],int i,int j);
	
	swap(v,left,(left+right)/2);
	last=left;
	for(i=left+1;i<right;i++)
		if(strcmp(v[i],v[left])<0;)
			swap(v,++last,i);
	swap(v,left,last);
	qsort(v,left,last-1);
	qsort(v,last+1,right);
}

void swap(char *v[],int i,int j)
{
	char *temp;
	
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}
