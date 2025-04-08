#include<stdio.h>
#include<stdlib.h>
#define max 1000

int count;

int merge(int a[],int low,int mid,int high){
    int i,j,k;
    int b[max];
    i=low;
    j=mid+1;
    k=low;

    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            b[k++]=a[i++];
            count++;
        }
        else{    
            b[k++]=a[j++];
            count++;
        }
    }

    while(i<=mid){
        b[k++]=a[i++];
        count++;
    }

    while(j<=high){
        b[k++]=a[j++];
        count++;
    }

    for(i=low;i<=high;i++)
        a[i]=b[i];
}

void mergesort(int a[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main(){
    int c1,c2,c3,a[max],b[max],c[max],n;
    printf("Enter the number of elements to be sorted:");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    mergesort(a,0,n-1);
    printf("Sorted elements are:\n");

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nSIZE\tASC\tDESC\tRAND\n");
    for(int i=16;i<520;i=i*2){
        for(int j=0;j<i;j++){
            a[j]=j;
            b[j]=i-j;
            c[j]=rand()%i;
        }
            count=0;
            mergesort(a,0,i-1);
            c1=count;

            count=0;
            mergesort(a,0,i-1);
            c2=count;

            count=0;
            mergesort(a,0,i-1);
            c3=count;

            printf("%d\t%d\t%d\t%d\n",i,c1,c2,c3);
        
    }

    return 0;
}