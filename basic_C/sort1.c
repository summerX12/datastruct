#include <stdlib.h>
#include <stdio.h>

#define N 10

int main(void)
{
	int arr[N] = {12,8,45,30,98,67,2,7,68,11};
	int i,j,tmp;

	for(i=0; i<N-1; i++)
	{
		for(j=0;j<N-i-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				tmp = arr[j];
				arr[j] =arr[j+1];
			        arr[j+1] = tmp;	
			}
		}
	}

	for(i=0;i<N;i++)
		printf("%d  ",arr[i]);
	printf("\n");

	exit(0);
}
