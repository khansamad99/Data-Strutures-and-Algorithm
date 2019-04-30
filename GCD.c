#include<stdio.h>
#include<time.h>
#include<stdlib.h>
long long int gcd(long long int a,long long int b){
    long long int temp;
    while(b!=0){
        temp = a%b;
        a = b;
        b= temp;
    }
    return a;
}
long long int main(){
    int t;
    long long int a,b;
    FILE *ptr,*ptr1,*ptr2;
    ptr = fopen("C:\\a.txt","a");
    ptr1 = fopen("C:\\t.txt","a");
    ptr2 = fopen("C:\\b.txt","a");
    clock_t start,end;
    scanf("%d",&t);
    while(t--){
        srand(time(NULL));
        start=clock();
        a=rand()%1000000+a;
        srand(time(NULL));
        b=rand()%a+b;
        //printf("\nEnter two numbers: ");
        //scanf("%d %d",&a,&b); // 2 numbers are taken as input from the user.
        if(a == 0 || b == 0){
            continue;
        }
        else    {
            printf("\nGCD of %lld %lld is: %lld",a,b,gcd(a,b));
            end=clock();
            printf("\nTime: %d Milliseconds ",end-start);
            fprintf(ptr,"%lld ",a);
            fprintf(ptr2,"%lld ",b);
            fprintf(ptr1,"%d ",end-start);
        }
    }
}
