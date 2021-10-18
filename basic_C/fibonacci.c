#include <stdlib.h>
#include <stdio.h>

int fab(int num)
{
	if(num == 1)
		return 1;
	else if(num == 2)
		return 1;
	else
		return fab(num-1)+fab(num-2);
}

int main(void)
{
	int cha;

	printf("please enter a number:");
	scanf("%d",&cha);

	printf("%d\n",fab(cha));

	exit(0);
}
