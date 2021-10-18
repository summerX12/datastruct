#include <stdlib.h>
#include <stdio.h>


int fac(int num)
{
	if(num == 1)
		return 1;	
	else 
		return num*fac(num-1);
}

int main(void)
{
	int res,cha;

	printf("Please enter a number:\n");
	scanf("%d",&cha);
	res = fac(cha);
	printf("%d\n",res);

	exit(0);
}
