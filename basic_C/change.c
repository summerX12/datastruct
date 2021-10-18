#include <stdlib.h>
#include <stdio.h>


int main()
{
  int arr[2][2] = {1,1,2,2};
  int i,j;

  for(i=0;i<2;i++)
  {
    for(j=0;j<2;j++)
      printf("%4d ",arr[i][j]);
    printf("\n");
  }

  printf("\n");

  for(i=0;i<2;i++)
  {
    for(j=0;j<2;j++)
      printf("%4d ",arr[j][i]);
    printf("\n");
  }


  exit(0);
}

