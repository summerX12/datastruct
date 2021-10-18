#include <stdlib.h>
#include <stdio.h>

int arr[]={45,46,8,46,13,47,48,4,83,1,3,1,47,31};

void quick(int start,int end)
{
	int temp;
	int i,j;

	if(start >= end)
		return ;

	i = start;
	j = end;
	temp = arr[start];

	while(i<j)
	{
		while(i<j && arr[j] > temp)
			j--;
		arr[i] = arr[j];

		while(i<j && arr[i] <= temp)
			i++;
		arr[j] = arr[i];
	}
	arr[i] = temp;

	quick(start,i-1);
	quick(i+1,end);
	
}

int main()
{
	int i;

	for(i=0; i< sizeof(arr)/sizeof(*arr); i++)
		printf("%d ",arr[i]);
	printf("\n");

	quick(0,sizeof(arr)/sizeof(*arr)-1);	

	for(i=0; i< sizeof(arr)/sizeof(*arr); i++)
		printf("%d ",arr[i]);
	printf("\n");
	exit(0);
}
