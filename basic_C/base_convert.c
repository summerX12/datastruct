#include <stdlib.h>
#include <stdio.h>


int main()
{
	int num,base,i;
	int res[128];

	printf("Please enter num:");
	scanf("%d",&num);
	printf("\nPlease enter base:");
	scanf("%d",&base);

	if(num != 0)
	{
		do
		{
			res[i] = num%base;
			num = num/base;
			i++;
		}while(num);
	}
	else
		printf("0\n");

	for(;i--;i>0)
		printf("%d",res[i]);

	exit(0);
}
