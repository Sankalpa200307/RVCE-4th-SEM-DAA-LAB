#include<stdio.h>
#include<stdlib.h>

int n,W,w[10],v[10],V[10][10],x[10];

int max(int a,int b){
    return a>b?a:b;
}

void knapsack(){
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=W;j++){
            if(i==0 || j==0)
                V[i][j]=0;
            else if(j<w[i])
                V[i][j]=V[i-1][j];
            else{
                V[i][j]=max(V[i-1][j],v[i]+V[i-1][j-w[i]]);
            }
            printf("%d\t",V[i][j]);
        }
        printf("\n");
    }
}

void printsolution(){
    int i,j;
    i=n;
    j=W;
    while(i!=0 && j!=0){
        if(V[i][j]!=V[i-1][j]){
            x[i]=1;
            j=j-w[i];
        }
            i--;
    }
}

int main(){
    int i;
    printf("Enter number of objects:");
    scanf("%d",&n);
    printf("Enter the knapsack capacity:");
    scanf("%d",&W);
    printf("Enter the weights of the objects:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("Enter the profits of the objects:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);

    knapsack();
    printsolution();//this will tell which objects are there in the knapsack
    printf("Object\tWeight\tProfit\n");
    for(i=0;i<=n;i++){
        if(x[i]==1){
            printf("%d\t%d\t%d\n",i,w[i],v[i]);
        }
    }
    printf("\nThe maximum profit is %d \n",V[n][W]);
    return 0;
}