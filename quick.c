#include<stdio.h>
#include<time.h>
void swap1(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int partition2(int *a,int start,int end1)
{
int pivot=a[start],p1=start+1,i,temp;
for(i=start+1;i<=end1;i++)
{
if(a[i]<pivot)
    {
        if(i!=p1)
      {
           swap1(&a[p1],&a[i]);
      }    p1++;
    }
}
swap1(&a[start],&a[p1-1]);

return p1-1;
}

int partition1 (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap1(&arr[i], &arr[j]);
        }
    }
    swap1(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition2(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    int i,n,start,end1;
    start=clock();
    srand(time(NULL));
    n=rand()%500;
    printf("Number of elements are %d\n",n);
    int a[1200];
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    a[i]=rand()%100;
    quickSort(a,0,n-1);
    printf("The elements are\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    end1=clock();
    printf("Time taken is %d",end1-start);
}
