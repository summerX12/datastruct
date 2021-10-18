#include <stdlib.h>
#include <stdio.h>



int main()
{
	int arr[] = {23,5,45,6,87,78,8,9,56,7,98,43,76};
	int i,j=0,k,tmp;

	for(i=0; i<sizeof(arr)/sizeof(*arr); i++)
		printf("%d ",arr[i]);
	printf("\n");

	for(i=1; i<sizeof(arr)/sizeof(*arr); i++)
	{
		while(j<i && arr[j] < arr[i])
		{
			j++;
		}
		tmp = arr[i];
		//j->insert position;  tmp->insert number
		k=i;
		while(k != j)
		{
			arr[k] = arr[k-1];
			k--;
		}
		arr[j] = tmp;
		j=0;
	}

	for(i=0; i<sizeof(arr)/sizeof(*arr); i++)
		printf("%d ",arr[i]);

	exit(0);
}
