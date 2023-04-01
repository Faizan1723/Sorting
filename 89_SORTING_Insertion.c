// INSERTION SORT //
/*
    *) INSERTION SORT IS ADAPTIVE BY NATURE.
    *) INSERTION SORT IS STABLE.
    *) IF THE LIST IS ALREADY SORTED THEN IT TAKES O(n) TIME TO COMPLETE THE SORTING.
       i.e., MIN. TIME TAKEN O(n).
             MAX. TIME TAKEN O(n^2).

    *) INSERTION SORT IS NOT USEFUL TO FIND GREATEST ELEMENT OR SECOND GREATEST ELEMENT BEFORE THE SORT IS COMPLETE.
*/


#include<stdio.h>

void Insert_Sort(int A[],int n)
{
    int x;
    int j,i;
    for(i=1;i<n;i++)
    {
        x=A[i];
        j=i-1;

        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}
int main()
{
    int data[]={10,25,24,21,26,85,29,351,15,554};
    int n=10;

    Insert_Sort(data,n);

    for(int i=0;i<n;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    return 0;
}