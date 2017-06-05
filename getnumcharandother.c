#include<stdio.h>
int main()
{
	int c,i,nwhite,nother;
	int ndigit[10];
	nwhite=nother=0;
	
	for(i=0;i<10;i++)
		ndigit[i]=0;

	while((c=getchar())!=EOF)
	{
		if(c>='0'&&c<='9')
		{
			++ndigit[c-'0'];
		}
		if(c==' '||c=='\t'||c=='\n')
			++nwhite;
		else
			++nother;
	}
	
	for(i=0;i<10;i++)
		printf("The number of digit %d is : %d\n",i,ndigit[i]);
	printf("The number of white char is: %d\n",nwhite);
	printf("The number of other char is: %d\n",nother);
}
