#include<iostream>
using namespace std;
void merge(int arr[],int start, int end)
{
    int mid=(start+end)/2;
    int len1=mid-start+1;
    int len2=end-mid;
    int *first=new int [len1];
    int *second=new int[len2];
    int mainidx=start;
    for(int i=0;i<len1;i++)
    {
        first[i]=arr[mainidx++];
    }
    mainidx=mid+1;
    for(int i=0;i<len2;i++)
    {
        second[i]=arr[mainidx++];
    }
    //merge 2 sorted arrays;
    int idx1=0;
    int idx2=0;
    mainidx=start;
    while(idx1<len1&&idx2<len2)
    {
        if(first[idx1]<second[idx2])
        {
            arr[mainidx++]=first[idx1++];
        }
        else
        {
            arr[mainidx++]=second[idx2++];
        }
    }
    while(idx1<len1)
    {
        arr[mainidx++]=first[idx1++];
    }
    while(idx2<len2)
    {
        arr[mainidx++]=second[idx2++];
    }
    delete [] first;
    delete [] second;
}
void mergesort(int arr[],int start,int end)
{
    //base case
    if(start>=end)
    {
        return;
    }
    int mid=(start+end)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,end);
}
int main()
{
    int arr[]={12,11,13,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}