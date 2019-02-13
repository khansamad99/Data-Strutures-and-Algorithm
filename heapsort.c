#include<stdio.h>
#include<time.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void heapify(int a[],int n,int i)
{
    //printf("hkdsk");
    int largest = i;
    int l=2*i+1;
    int r=2*i+2;
    int temp;

    if(l<n && a[l]>a[largest])
    {
        largest=l;
    }

    if(r<n && a[r]>a[largest])
    {
        largest=r;
    }

    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        heapify(a,n,largest);
    }
}
void heapSort(int a[],int n)
{
    //printf("mhkh");
    int i,temp;
    for(i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(i=n-1;i>=0;i--)
    {

        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }

}
int main()
{
    int n,i,start,end;
    start=clock();
    srand(time(NULL));
    n=rand()%100;
    printf("The value of n is %d\n: ",n);
    int a[1000];
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
    heapSort(a,n);
    printf("\nSorted array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    end=clock();
    printf("\nTime is %d",end-start);

}
