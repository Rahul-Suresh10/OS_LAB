#include<stdio.h>
#include<stdlib.h>
int main()
{
  int n,h,i,j,k,t[25],p,a[25],d,num,sum=0,temp;
  printf("Enter the no of tracks: ");
  scanf("%d",&n);
  printf("Enter the head: ");
  scanf("%d",&h);
  printf("Enter the direction to be traversed: Right 0 , Left 1\n");
  scanf("%d",&d);
  printf("Enter the tracks: ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&t[i]);
  }
  t[n]=h;
  t[n+1]=0;
  t[n+2]=199;
  n=n+3;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(t[j]>t[j+1])
      {
        temp=t[j];
        t[j]=t[j+1];
        t[j+1]=temp;
      }
    }
  }
  for(i=0;i<n;i++)
  {
    if(t[i]==h)
    {
      k=i;
      break;
    }
  }
  if(d==1)
  {
    for(i=k;i>=0;i--,p++)
    {
      a[p]=t[i];
    }
    for(i=n-1;i>k+1;i--,p++)
    {
      a[p]=t[i];
    }
  }
  else
  {
    for(i=k;i<n;i++,p++)
    {
      a[p]=t[i];
    }
    for(i=0;i<k;i++,p++)
    {
      a[p]=t[i];
    }
  }
  printf("The traversed order is: ");
  printf("%d",h);
  for(i=0;i<p;i++)
  {
     if (i > 0) {
    printf(" => ");
    printf("%d",a[i]);
  }
  }
  for(i=0;i<p;i++)
  {
    num=0;
    num=abs(h-a[i]);
    h=a[i];
    sum=sum+num;
  }
  printf("\nTrack path covered is : %d \n",sum);
}
    
