#include<stdio.h>

void Swap(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void Heapify(int arr[], int n, int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && arr[l]>arr[largest])
        largest=l;

    if(r<n && arr[r]>arr[largest])
        largest=r;

    if(largest!=i)
    {
        Swap(arr, i, largest);
        Heapify(arr, n, largest);
    }
}

void BuildHeap(int arr[], int n){
    int idx=(n/2)-1;

    for(int i=idx; i>=0; i--)
        Heapify(arr, n, i);
}

void DisplayHeap(int arr[], int n){
    printf("\nHeap Constructed: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
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

    BuildHeap(arr, n);
    DisplayHeap(arr, n);

    return 0;
}