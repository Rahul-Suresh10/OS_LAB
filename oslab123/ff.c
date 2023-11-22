#include<stdio.h>
#include<stdlib.h>
int main()
{
  int np,nb,i,j;
  int ps[25],bs[25],allocation[25];
  printf("Enter the no of process: ");
  scanf("%d",&np);
  printf("Enter the no of blocks: ");
  scanf("%d",&nb);
  for(i=0;i<np;i++)
  {
    printf("Enter the size of process: ");
    scanf("%d",&ps[i]);
  }
   for(i=0;i<nb;i++)
  {
    printf("Enter the size of blocks: ");
    scanf("%d",&bs[i]);
  }
  for(i=0;i<np;i++)
  {
    allocation[i]=-1;
  }
  for(i=0;i<np;i++)
  {
    for(j=0;j<nb;j++)
    {
      if(ps[i]<=bs[j]&&allocation[i]==-1)
      {
        allocation[i]=j;
        bs[j]=bs[j]-ps[i];
        break;
      }
    }
  }
  printf("Process no\tProcess size\tBlock no\n");
  for(i=0;i<np;i++)
  {
    printf("%d\t\t%d\t\t",i+1,ps[i]);
    if(allocation[i]!=-1)
    {
      printf("%d\n",allocation[i]+1);
    }
    else
    {
      printf("not allocated");
    }
  }
}
  
