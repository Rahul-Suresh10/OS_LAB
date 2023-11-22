#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,h,sum=0,d,k,i,j,p=0;
int arr[25],a[25];
 printf("Enter the number of tracks : \n");
 scanf("%d",&n);
 printf("Enter the current head position : \n");
 scanf("%d",&h);
 int temp = h;
 printf("Enter the direction 1 (RIGHT) , 0 (LEFT)\n");
 scanf("%d",&d);
 printf("Enter the tracks to be traversed : \n");
  for(int i=0;i<n;i++)
  
    {
      scanf("%d",&arr[i]);
    }
    arr[n] = h;
    arr[n+1] = 0;
    arr[n+2] = 199;
    n = n+3;
    for(int i=0;i<n-1;i++)
    {
    for(int j = 0;j<n-i-1;j++)
    {
    if(arr[j]>arr[j+1])
    {
    temp = arr[j];
    arr[j] = arr[j+1];
    arr[j+1] = temp;
    }
    }
    }
    for(int i=0;i<n;i++)
    {
    if(arr[i] == h)
    k = i;
    }
    if(d==0)
    {
    for(int i = k;i>=0;i--,p++)
    {
    a[p] = arr[i];
    }
    for(int j = n-1;j>k;j--,p++)
    {
    a[p] = arr[j];
    }    
    }
    else
    {
    for(int j = k;j<n;j++,p++)
    {
    a[p] = arr[j];
    }
    for(int i=0;i<k;i++,p++)
    {
    a[p] = arr[i];
    }
    }
    for(int i = 0;i<p;i++)
    {
    sum = sum + abs(h - a[i]);
    h = a[i];
    }
    printf("Head movement : %d\n",sum);
     printf("Traversed Order :\n");
      //printf("%d",temp);
      for(int i=1;i<p;i++)
      {
      printf("%d--",a[i-1]);
      }
      printf("%d",a[p-1]);
      
    }
   
    
   
    
