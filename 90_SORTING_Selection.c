// SELECTION SORT //
/*
    *) SELECTION SORT IS NOT ADAPTIVE.
    *) SELECTION SORT IS NOT STABLE.
    *) FIRST SORT WILL GIVE THE LEAST ELEMENT AND THE SECOND ELEMENT GIVES THE SECOND LEAST ELEMENT AND SO ON.
*/
#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void Selection_Sort(int A[],int n)
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(A[j]<A[k])
            {
                k=j;
            }
        }
        swap(&A[i],&A[k]);
    }
}
int main()
{
    int data[]={10,25,24,21,26,85,29,351,15,554};
    int n=10;

    Selection_Sort(data,n);

    for(int i=0;i<n;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    return 0;
}