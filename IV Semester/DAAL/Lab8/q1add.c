#include<stdio.h>

int Check_Heap(int arr[], int n){
    int idx=(n/2)-1;

    for(int i=idx; i>=0; i--)
    {
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;    

        if(!(arr[largest]>=arr[left] && arr[largest]>=arr[right]))
            return 0;
    }   
    return 1;
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    if(Check_Heap(arr, n))
        printf("It IS a Heap!\n");
    else
        printf("It is NOT a Heap!\n");

    return 0;
}