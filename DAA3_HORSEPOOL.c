#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 256

int Table[max];

void Shiftable(char p[]){
    int i;
    int m=strlen(p);

    for(i=0;i<max;i++)
        Table[i]=m;

    for(i=0;i<=m-2;i++){
        Table[p[i]]=m-i-1;
    }
}

int horsepool(char T[],char P[]){
    int m,n,i,k,j;
    m=strlen(P);
    n=strlen(T);
    Shiftable(P);
    i=m-1;
    while(i<=n-1){
        k=0;
        while(k<=m-1 && (T[i-k]==P[m-1-k]))
            k=k+1;

        if(k==m){
            return i-m+1;
        }
        else{
            i=i+Table[T[i]];
        }
    }
    return -1;
}

int main(){
    char T[max],P[max];
    printf("Enter the text:");
    gets(T);
    printf("Enter the pattern to be searched:");
    gets(P);

    int x=horsepool(T,P);

    if(x==-1){
        printf("The pattern not found.....!\n");

    }
    else{
        printf("The pattern found at position %d\n",x);
    }
    return 0;
}
