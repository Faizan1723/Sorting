#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};

int Find_Passes(int A[],int n)
{
    int i,j;
    int max=A[0];
    for(i=1;i<n;i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    
    int count = 0;
    while (max != 0)
    {
        count++;
        max/=10;
    }
    return count;
}

int Delete(struct node **Bins,int i)
{
    struct node* ptr=Bins[i];
    Bins[i]=Bins[i]->link;
    int x=ptr->data;
    free(ptr);
    return x;
}

void Insert(struct node **Bins,int i)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=i;
    temp->link=NULL;

    if(Bins[i]==NULL)
    {
        Bins[i]=temp;
    }
    else
    {
        struct node* ptr=Bins[i];
        while (ptr->link!=NULL)
        {
            ptr= ptr->link;
        }
        ptr->link=temp;
    }
}

void Radix_Sort(int A[],int n)
{
    int pass=Find_Passes(A,n);
    struct node** Bins;
    Bins=malloc(sizeof(struct node)*(10));

    for(int i=0;i<9;i++)
    {
        Bins[i]=NULL;
    }

    for(int k=0,mul=1;k<pass;k++,mul=mul*10)
    {
        for(int i=0;i<n;i++)
        {
            int y=A[i];
            y=(y/mul)%10;
            Insert(Bins,y);
        }
        int i=0,j=0;
        while(i<10)
        {
            while(Bins[i]!=NULL)
            {
                A[j++]=Delete(Bins,i);
            }
            i++;
        }
    }
}

int main()
{
    int data[]={165,6,22,189,2,15,156,25,243,447,26,20,201,60,88};
    int n=15;
    Radix_Sort(data,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    return 0;
}