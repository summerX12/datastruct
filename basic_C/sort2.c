#include <stdlib.h>
#include <stdio.h>

#define N 10

int main(void)
{
	int arr[N] = {12,8,45,30,98,67,2,7,68,11};
	int i,j,min_idx,tmp;

	for(i=0; i<N-1; i++)
	{
		min_idx = i;
		for(j=i+1;j<N;j++)
		{
			if(arr[min_idx] > arr[j])
				min_idx = j;
		}
		tmp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = tmp;
	}

	for(i=0;i<N;i++)
		printf("%d  ",arr[i]);
	printf("\n");

	exit(0);
}
