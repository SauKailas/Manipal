#include<stdio.h>

void Swap(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int Partition(int arr[], int left, int right){
    int pivot=right;
    int i=left-1;

    for(int j=left; j<right; j++)
        if(arr[j]<arr[pivot])
        {
            i++;
            Swap(arr, i, j);
        }

    Swap(arr, i+1, right);
    return i+1;
}

void Quicksort(int arr[], int left, int right){
    if(left<right)
    {
        int pivot=Partition(arr, left, right);
        Quicksort(arr, left, pivot-1);
        Quicksort(arr, pivot+1, right);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    Quicksort(arr, 0, n-1);

    printf("Sorted array: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}