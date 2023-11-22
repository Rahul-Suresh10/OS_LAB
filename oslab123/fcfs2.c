#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,h,sum=0;
int arr[25];
 printf("Enter the number of tracks : \n");
 scanf("%d",&n);
 printf("Enter the current head position : \n");
 scanf("%d",&h);
 int temp = h;
 printf("Enter the tracks to be traversed : \n");
  for(int i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
    }
    
    for(int i=0;i<n;i++)
     {
      sum = sum+abs(h-arr[i]);
      h = arr[i];
     }
      printf("Traversed Order :\n");
      printf("%d",temp);
      for(int i=0;i<n;i++)
      {
      
      printf("--%d",arr[i]);
      }
    printf("\nhead movement = %d",sum);
    
    
      
    }
    
      
  
