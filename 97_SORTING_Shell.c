#include<stdio.h>

void Shell_Sort(int A[],int n)
{
    int gap,temp,i,j;
    for(gap=n/2;gap>=1;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            temp=A[i];
            j=i-gap;
            while(j>=0 && A[j]>temp)
            {
                A[j+gap]=A[j];
                j=j-gap;
            }
            A[j+gap]=temp;
        }
    }
}
int main()
{
    int data[]={165,6,22,189,2,15,156,25,243,447,26,20,201,60,88};
    int n=15;
    Shell_Sort(data,n);

    for(int i=0;i<n;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    return 0;
}   