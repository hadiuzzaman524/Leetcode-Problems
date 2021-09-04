#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


void mergesort(int x[], int first, int last);
void merge(int x[], int first, int mid, int last);

int main()
{
    int x[100],n,i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the elements of array: \n ");
    for(i=0; i<n; i++)
        scanf("%d",&x[i]);
    mergesort(x,0,n-1);
    printf("Merge sorted elements are: ");
    for(i=0; i<n; i++)
        printf("%d", x[i]);
    return 0;

}
void mergesort(int x[], int first, int last)
{
    int mid;
    if(first<last)
    {
        mid=(first+last)/2;
        mergesort(x, first, mid);
        mergesort(x, mid+1, last);
        merge(x, first, mid, last);
    }
}
void merge(int x[], int first, int mid, int last)
{
    int y[100];
    int i, j, k;
    i=first;
    j=mid+1;
    k=first;
    while(i<=mid&&j<=last)
    {
        if(x[i]<=x[j])
        y[k++]=x[i++];
        else
            y[k++]=x[j++];
    }
    if(i>mid)
    {
        while (j<=last)
            y[k++]=x[j++];
    }
    else
    {
        while (i<=mid)
            y[k++]=x[i++];
    }
    for (i=first; i<=last; i++)
        x[i]=y[i];
}
