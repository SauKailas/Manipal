#include<stdio.h>

int Max(int a, int b){
    return a>b?a:b;
}

int Knapsack(int W, int weights[], int values[], int n){
    int K[n+1][W+1];

    for(int i=0; i<=n; i++)
        for(int w=0; w<=W; w++)
        {
            if(!i || !w)
                K[i][w]=0;
            else if(weights[i-1]<=w)
                K[i][w]=Max(values[i-1]+K[i-1][w-weights[i-1]], K[i-1][w]);
            else
                K[i][w]=K[i-1][w];
        }
    return K[n][W];
}

int main()
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int values[n];
    printf("Enter the values of the items:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &values[i]);

    int weights[n];
    printf("Enter the weights of the items:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &weights[i]);

    int W;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    printf("Profit: %d\n", Knapsack(W, weights, values, n));

    return 0;
}