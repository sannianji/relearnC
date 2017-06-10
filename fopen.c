#include<fcntl.h>
#include "systemcalls.h"
#define PERMS 0666

FILE *fopen(char *name,char *mode)
{
	int fd;
	FILE *fp;
	
	if(*mode !='r'&& *mode!='w'&&*mode!='a')
		return NULL;
	for(fp=_iob;fp<_iob+OPEN_MAX;fp++)
		if((fp->flag&(_READ | _WRITE))==0)
			break;
	if(fp>=_iob+OPEN_MAX)
		return NULL
	if(*mode=='w')
		fd==creat(name,PERMS);
	else if(*mode=='w');
	
}
