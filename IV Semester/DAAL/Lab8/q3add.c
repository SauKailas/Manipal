#include<stdio.h>
#include<stdlib.h>

void Swap(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int CheckHeap(int arr[], int n){
    int idx=(n/2)-1;

    for(int i=idx; i>=0; i--)
    {
        int left=2*i+1;
        int right=2*i+2;

        if(!(arr[i]>arr[left] && arr[i]>arr[right]))
            return 0;
    }
    return 1;
}

int FindSmallest(int arr[], int n){
    int smallest=arr[0];
    for(int i=1; i<n; i++)
        if(arr[i]<smallest)
            smallest=arr[i];
    return smallest;
}

void Heapify(int arr[], int n, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]>arr[largest])
        largest=left;

    if(right<n && arr[right]>arr[largest])
        largest=right;

    if(i!=largest)
    {
        Swap(arr, i, largest);
        Heapify(arr, n, largest);
    }
}

void DeleteSmallest(int arr[], int n){
    int smallest=FindSmallest(arr, n);
    printf("Smallest Element: %d\n", smallest);

    int i;
    for(i=0; i<n; i++)
        if(arr[i]==smallest)
            break;

    for(int j=i; j<n-1; j++)
        arr[j]=arr[j+1];
    n--;

    int idx=(n/2)-1;
    for(int j=idx; j>=0; j--)
        Heapify(arr, n, j); 

    printf("The modified Heap is: ");
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

    if(!CheckHeap(arr, n))
    {
        printf("It is NOT a Heap!\n");
        exit(0);
    }

    DeleteSmallest(arr, n);

    return 0;
}