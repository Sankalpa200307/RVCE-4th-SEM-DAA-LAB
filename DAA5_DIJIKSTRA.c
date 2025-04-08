#include<stdio.h>
#include<stdlib.h>

void dijikstra(int n,int cost[10][10],int s,int dist[10],int pred[10]){
            int v,i,count,visited[30],min;
            for(i=0;i<n;i++){
                visited[i]=0;
                dist[i]=cost[s][i];
                if(dist[i]!=999)
                    pred[i]=s;
            }

            visited[s]=1;
            dist[s]=0;
            pred[s]=-1;
            count=1;
            while(count <n){
                min=999;
                for(i=0;i<n;i++){
                    if(!visited[i] && dist[i]<min){
                        min=dist[i];
                        v=i;
                    }
                }

                visited[v]=1;
                count++;

                for(i=0;i<n;i++){
                    if(!visited[i] && dist[v]+cost[v][i]<dist[i]){
                        dist[i]=dist[v]+cost[v][i];
                        pred[i]=v;
                    }
                }
            }
}

int main(){
    int i,j,n,s,cost[10][10],dist[10],pred[10];
    printf("\nEnter the no of nodes:");
    scanf("%d",&n);
    printf("Read cost matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    printf("Read Source:");
    scanf("%d",&s);
    dijikstra(n,cost,s,dist,pred);

    printf("Shortest path from %d is \n",s);
    for(i=0;i<n;i++){
        if(i!=s){
            printf("\nShortest Distance of vertex %d=%d",i,dist[i]);
            printf("\nPath=%d ",i);
            j=i;
            do{
                j=pred[j];
                printf("<-%d",j);
            }while(j!=s);
        }
    }
        return 0;
    }
