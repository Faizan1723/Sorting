/*
    THE DIFFERENT TYPES OFF SORTING TECHNIQUES ARE:-

    *** COMPARISON BASED SORTS ***

        * O(n^2) SORTS *
            1> BUBBLE SORT.
            2> INSERT SORT.
            3> SELECTION SORT.

        * O(nlogn) SORTS *
            4> HEAP SORT.
            5> MERGE SORT.
            6> QUICK SORT.
            7> TREE SORT.

        * O(n^3/2) SORT *
            8> SHELL SORT.

    *** INDEX BASED SORTS ***

        * O(n) SORTS *
            9> COUNT SORT.
           10> BUCKET/BIN SORT.
           11> RADIX SORT.
*/


// BUBBLE SORT //
/*
    *) BUBBLE SORT IS ADAPTIVE.
    *) BUBBLE SORT IS STABLE.
    *) IF THE LIST IS ALREADY SORTED THEN IT TAKES O(n) TIME TO COMPLETE THE SORTING.
       i.e., MIN. TIME TAKEN O(n).
             MAX. TIME TAKEN O(n^2).

    *) FIRST SORT WILL GIVE THE GREATEST ELEMENT AND THE SECOND ELEMENT GIVES THE SECOND LARGEST ELEMENT.
*/

#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void Bubble_Sort(int A[],int n)
{
    int flag=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
int main()
{
    int data[]={165,6,22,189,2,15,156,25,243,447,26,20,201,60,88};
    int n=15;
    Bubble_Sort(data,n);

    for(int i=0;i<n;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    return 0;
}
