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

void Iterative_Merge(int Array[],int n)
{
    int high,low,mid,i,p;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            low=i;
            high=i+p-1;
            mid=(low+high)/2;
            Merge_Sort(Array,low,mid,high);
        }
        if(n-i>p/2) 
        { 
            low = i;  
            high = i+p-1; 
            mid = (low+high)/2; 
            Merge_Sort(Array,low, mid, n-1); 
        }
    }
    if(p/2<n)
    {
        Merge_Sort(Array,0,p/2-1,n-1);
    }

}
int main()
{
    int data[]={165,6,22,189,2,15,156,25,243,447,26,20,201,60,88};
    int n=15;
    Iterative_Merge(data,n);

    for(int i=0;i<n;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    return 0;
}