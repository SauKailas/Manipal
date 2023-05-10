#include<stdio.h>

void Merge(int A[], int B[], int C[], int nA, int nB, int nC){

    int a=0, b=0, c=0;

    while(b<nB && c<nC)
    {
        if(B[b]<C[c])
            A[a++]=B[b++];
        else    
            A[a++]=C[c++];
    }

    if(b==nB)
        for(int i=c; i<nC; i++)
            A[a++]=C[i];
    else
        for(int i=b; i<nB; i++)
            A[a++]=B[i];
}

void Mergesort(int A[], int n){

    if(n>1)
    {
        int B[n/2], C[n/2];
        int nB=0, nC=0;

        for(int i=0; i<n/2; i++)
            B[nB++]=A[i];

        for(int i=n/2; i<n; i++)
            C[nC++]=A[i];

        Mergesort(B, nB);
        Mergesort(C, nC);
        Merge(A, B, C, n, nB, nC);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    Mergesort(arr, n);

    printf("Sorted array: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}