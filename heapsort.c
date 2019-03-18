#include<stdio.h>

void Build_Max_Heap(int *a, int len);
void Heapsort(int* a, int len);
void Max_Heapify(int *a, int key, int len);//to keep the max_heapify 

int main()
{
    int arr[10]={4,1,3,2,16,9,10,14,8,7};
    Heapsort(arr,10);

}
void Build_Max_Heap(int *a, int len)
{
    int heapsize=len;
    for(int i=heapsize/2;i>=0;i--)
    {
        Max_Heapify(a,i,len);
    }
}

void Max_Heapify(int *a, int key,int len)
{
    int largest;
    int l=key*2;
    int r=l+1;
    if(l<len && a[l]>a[key]) largest=l;
    else largest =key;
    if(r<len && a[r]>a[largest]) largest=r;
    if(largest != key)
    {
        int temp;
        temp=a[key];
        a[key]=a[largest];
        a[largest]=temp;
        Max_Heapify(a,largest,len);
    } 
}

void Heapsort(int *a ,int len)
{
    Build_Max_Heap(a,len);
    int heapsize=len;
    for(int i=len-1;i>0;i--)
    {
        int temp=0;
        temp=a[0];
        a[0]=a[i];
        printf("%d ",temp);
        heapsize--;
        Max_Heapify(a,0,heapsize);
    }
}



