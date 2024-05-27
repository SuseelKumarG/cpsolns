#include<iostream>
using namespace std;
void mergesort(int arr[],int s,int e);
void merge(int arr[],int s,int e);
void input(int arr[],int n);
int main()
{
    int n;
    cin>>n;
    int arr[n];
    input(arr,n);
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<' ';
}
void mergesort(int arr[], int s, int e)
{
    if(s>=e)
    return;
    int mid=s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
}

void merge(int arr[], int s, int e)
{
    int mid=s+(e-s)/2;
    int lenl=mid-s+1;
    int lenr=e-mid;
    int *first=new int[lenl];
    int *second=new int[lenr];
    for(int i=0;i<lenl;i++)
    {
        first[i]=arr[s+i];
    }
    for (int i=0;i<lenr;i++)
    {
        second[i]=arr[mid+1+i];
    }
    int index1=0;
    int index2=0;
    int mainarr=s;
    while((index1<lenl)&&(index2<lenr))
    {
        if(first[index1]<=second[index2])
        {
            arr[mainarr]=first[index1];
            index1++;
        }
        else{
            arr[mainarr]=second[index2];
            index2++;
        }
        mainarr++;
    }
        while(index2<lenr)
        {
            arr[mainarr]=second[index2];
            index2++;
            mainarr++;
        }
        while(index1<lenl)
        {
            arr[mainarr]=first[index1];
            index1++;
            mainarr++;
        }
    delete [] first;
    delete[] second;
}
void input (int arr[],int n)
{
    if(n==0)
    return;
    n--;
    input(arr,n);
    cin>>arr[n];
}