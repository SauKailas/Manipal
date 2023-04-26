#include<stdio.h>

void Swap(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void Heapify(int arr[], int n, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]>arr[largest])
        largest=left;
    
    if(right<n && arr[right]>arr[largest])
        largest=right;

    if(largest!=i)
    {
        Swap(arr, i, largest);
        Heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n){
    int idx=(n/2)-1;

    for(int i=idx; i>=0; i--)
        Heapify(arr, n, i);

    for(int i=n-1; i>=0; i--)
    {
        Swap(arr, i, 0);
        Heapify(arr, i, 0);
    }
}

void DisplayHeap(int arr[], int n){
    printf("\nHeapsorted Array: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
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

    HeapSort(arr, n);
    DisplayHeap(arr, n);

    return 0;
}