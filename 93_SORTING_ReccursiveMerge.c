#include<stdio.h>

void Merge_Sort(int Array[],int low, int mid,int high)
{
    int i=low,k=low,j=mid+1;
    int B_Array[high+1];

    while(i<=mid && j<=high)
    {
        if(Array[i]<Array[j])
        {
            B_Array[k++]=Array[i++];
        }
        else
        {
            B_Array[k++]=Array[j++];
        }
    }    

    for(;i<=mid;i++)
    {
        B_Array[k++]=Array[i];
    }
    for(;j<=high;j++)
    {
        B_Array[k++]=Array[j];
    }

    for(i=low;i<=high;i++)
    {
        Array[i]=B_Array[i];
    }
}

void Recursive_Merge(int A[],int low,int high)
{
    int  mid;
    if(low<high)
    {
        mid=(low+high)/2;
        Recursive_Merge(A,low,mid);
        Recursive_Merge(A,mid+1,high);
        Merge_Sort(A,low,mid,high);
    }
}
int main()
{
    int data[]={165,6,22,189,2,15,156,25,243,447,26,20,201,60,88};
    int n=15;
    Recursive_Merge(data,0,n-1);

    for(int i=0;i<n;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    return 0;
}