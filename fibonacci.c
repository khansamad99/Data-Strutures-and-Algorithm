#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int n,i,start,end1;
    //printf("Enter the number upto which you want to print fibonacci series\n");
    //scanf("%d",&n);
    start=clock();
    srand(time(NULL));
    n=rand()%1000;
    int fib[1000];
    fib[0]=0;
    fib[1]=1;
    for(i=2;i<=n;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    //printf("Fibonacci series upto %d\n",n);
    printf("%d\n",n);
    for(i=0;i<=n;i++)
    {
        printf("%d ",fib[i]);
    }
    end1=clock();
    printf("Time is %d",end1-start);
}
