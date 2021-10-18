#include <stdlib.h>
#include <stdio.h>

int main()
{
  int arr[3][4] = {{1,2,3},{4,5,6}};
  int i,j;

  for(i=0;i<2;i++)
  {
    for(j=0;j<3;j++)
    {
	arr[2][3]+=arr[i][j];
        arr[i][3]+=arr[i][j];
	arr[2][j]+=arr[i][j];
    }
  }

  for(i=0;i<3;i++)
  {
    for(j=0;j<4;j++)
      printf("%4d",arr[i][j]);
    printf("\n");
  }

  exit(0);
}
