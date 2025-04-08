#include<stdio.h>
#include<stdlib.h>

int min(int a,int b){
    return a<b?a:b;
}

void floyds(int D[10][10],int n){
    int i,j,k;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                for(k=1;k<=n;k++){
                    D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
                }
            }
        }
}


int main(){
    int n,i,j,D[10][10];
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the weighted matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&D[i][j]);
        }
    }
    floyds(D,n);

    printf("All pair shortest path is \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ",D[i][j]);
        }
        printf("\n");
    }

    return 0;

}