#include <stdlib.h>
#include <stdio.h>


int main()
{
  int A[2][3] = {1,1,1,2,2,2};
  int B[3][4] = {3,4,5,6,3,4,5,6,3,4,5,6};
  int C[2][4] = {0};
  int i,j,k;


  for(i=0;i<2;i++)
  {
    for(j=0;j<3;j++)
      printf("%d ",A[i][j]);
    printf("\n");
  }
  printf("\n");

  for(i=0;i<3;i++)
  {
    for(j=0;j<4;j++)
      printf("%d ",B[i][j]);
    printf("\n");
  }
  printf("\n");


  for(i=0;i<2;i++)
  {
    for(j=0;j<4;j++)
    {
      for(k=0;k<3;k++)
	C[i][j] += A[i][k] * B[k][j];
     }
  }

  for(i=0;i<2;i++)
  {
    for(j=0;j<4;j++)
      printf("%d ",C[i][j]);
    printf("\n");
  }

  exit(0);
}
