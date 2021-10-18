#include <stdlib.h>
#include <stdio.h>

int main()
{
  int arr[3][3] = {1,5,6,2,54,6,3,5,456};
  int i,j,max=arr[0][0],maxi=0,maxj=0;

  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      if(max<arr[i][j])
      {
	max = arr[i][j];
	maxi = i;
	maxj = j;
      }
      printf("%4d ",arr[i][j]);
    }
    printf("\n");
  }

  printf("max = %d,i = %d,j = %d\n",max,maxi,maxj);

  exit(0);
}
