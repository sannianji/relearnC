#include<stdio.h>
int main()
{
	int c,i,nwhite,nother,ndigit[10];
	nwhite=nother=0;
	for(i=0;i<10;i++)
		ndigit[i]=0;
	
	while((c=getchar())!=EOF)
	{
		switch (c)
		{
			case ' ':
			case '\n':
			case '\t':
				++nwhite;
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				++ndigit[c-'0'];
				break;
			default:
				++nother;
				break;
		}
	}
	for(i=0;i<10;i++)
		printf("the number of %d is : %d\n",i,ndigit[i]);
	printf("the number of white is : %d\n",nwhite);
	printf("the number of other is : %d\n",nother);
	return 0;
}
