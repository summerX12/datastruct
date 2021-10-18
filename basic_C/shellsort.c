#include <stdlib.h>
#include <stdio.h>

int main()
{
	int arr[]={2,78,65,34,8,4,81,73};
	int increment,i,len,j,tmp;	

	len = sizeof(arr)/sizeof(*arr);
	for(i=0; i < len; i++)
		printf("%d ",arr[i]);
	printf("\n");

	increment = len/3+1;
	while(increment)
	{
		for(i=0; i<len-increment; i++)	
		{
			if(arr[i] > arr[i+increment])
			{
				tmp = arr[i];
				arr[i] = arr[i+increment];
				arr[i+increment] = tmp;
			}
		}
		increment--;
	}

	for(i=0; i<sizeof(arr)/sizeof(*arr); i++)
		printf("%d ",arr[i]);
	printf("\n");

	exit(0);
}
