#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partision(int A[],int low,int high)
{
    int pivot=A[low];
    int i=low,j=high;

    do
    {
        do{i++;}while (A[i]<=pivot);
        do{j--;}while (A[j]>pivot);

        if(i<j)
        swap(&A[i],&A[j]);
    }while (i<j);

    swap(&A[low],&A[j]);
    return j;
}

void Quick_Sort(int A[],int low,int high)
{
    int j;
    if(low<high)
    {
        j=partision(A,low,high);
        Quick_Sort(A,low,j);
        Quick_Sort(A,j+1,high);
    }
}

int main()
{
    int data[]={165,6,22,189,2,15,156,25,243,447,26,20,201,60,88,__INT32_MAX__};
    int n=16;
    Quick_Sort(data,0,n-1);

    for(int i=0;i<n-1;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    return 0;
}