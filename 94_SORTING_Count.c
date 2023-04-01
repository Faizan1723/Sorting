#include<stdio.h>
#include<stdlib.h>

int Find_Max(int A[],int n)
{
    int i,j;
    int max=A[0];
    for(i=1;i<n;i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    return max;
}

void Count_Sort(int A[],int n)
{
    int max;
    max=Find_Max(A,n);
    int *Count_Array=malloc(sizeof(int)*(max+1));

    for(int i=0;i<max+1;i++)
    {
        Count_Array[i]=0;
    }
    
    for(int i=0;i<n;i++)
    {
        Count_Array[A[i]]++;
    }

    int i=0,j=0;
    while(i<max+1)
    {
        if(Count_Array[i]>0)
        {
            A[j++]=i;
            Count_Array[i]--;
        }
        else
            i++;
    }
}
int main()
{
    int data[]={165,6,22,189,2,15,156,25,243,447,26,20,201,60,88};
    int n=15;
    Count_Sort(data,n);

    for(int i=0;i<n;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    
    return 0;
}