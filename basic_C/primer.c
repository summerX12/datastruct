#include <stdlib.h>
#include <stdio.h>

#define LEFT	2
#define RIGHT	1000

static void primer(void)
{
	int i,j;
	int flag=1;
	int p[1024]={0};

	for(i=LEFT;i<RIGHT;i++)
	{
		flag = 1;
		for(j=2;j<i-1;j++)
		{
			if(i%j==0)
				flag = 0;		
		}

		if(flag)
			printf("%d is a primer\n",i);
/*			p[i] = i;
		else
			p[i] = 0;
*/
	}
/*
	for(i=LEFT;i<1024;i++)
	{
		if(p[i]!=0)
			printf("%d is a primer\n",i);
	}
*/
}

int main()
{

	primer();

	exit(0);
}
