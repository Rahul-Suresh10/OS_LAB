#include<stdio.h>
#include<stdlib.h>

int main(){
 	int n,h,i,a[25],new,sum=0,temp,j,d,arr[25],k,p=0;
	printf("ENTER THE NO OF TRACKS\t");
	scanf("%d",&n);
	printf("ENTER THE HEAD POSITION\t");
	scanf("%d",&h);
	printf("ENTER THE DIRECYION OF TRAVERSAL\nRIGHT=0\tLEFT=1");
	scanf("%d",&d);
	int he=h;
	printf("ENTER THE TRACKS COVERED\n");
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		}
        a[n]=h;
	a[n+1]=0;
	a[n+2]=199;
	n=n+3;
	for(i=0;i<n-1;i++){
	    for(j=0;j<n-i-1;j++){
	        if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
             }
       }
     }
     for(i=0;i<n;i++)
     {
      if(a[i]==h)
      {
          k=i;
          break;
       }
     }
     
     
     if(d==1)
     {
      
      for(i=k;i>=0;i--,p++)  {
        arr[p]=a[i];
        
       }
      for(i=n-1;i>k;i--,p++){
      arr[p]=a[i];
      }
      }
    else
     {
      
      for(i=k;i<n;i++,p++)  {
        arr[p]=a[i];
        
       }
      for(i=0;i<k;i++,p++){
      arr[p]=a[i];
      }
      }
      
      for(i=0;i<p;i++){
      new=0;
      new=abs(h-arr[i]);
      h=arr[i];
      sum=sum+new;
      }
      printf("THE TRAVERSED ORDER IS\t");
	printf("%d",arr[0]);
	for(i=1;i<p;i++){
		printf(" ->%d",arr[i]);
	
		}
		printf("\nTHE TRACK PATH COVERED: %d\n",sum);
		
}
      
      
