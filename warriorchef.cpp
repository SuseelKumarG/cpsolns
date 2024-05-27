#include<iostream>
using namespace std;
void merge(int arr[],int s,int e)
{
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *left=new int[len1];
    int *right=new int[len2];
    for(int i=0;i<len1;i++)
    left[i]=arr[s+i];
    for(int i=0;i<len2;i++)
    right[i]=arr[mid+1+i];
    int index1=0,index2=0,mainarr=s;
    while(index1<len1 && index2<len2)
    {
        if(left[index1]<=right[index1])
        {
            arr[mainarr]=left[index1];
            index1++;
        }
        else
        {
            arr[mainarr]=right[index2];
            index2++;
        }
        mainarr++;
    }
    while(index1<len1)
    {
        arr[mainarr]=left[index1];
        index1++;
        mainarr++;
    }
    while(index2<len2)
    {
        arr[mainarr]=right[index2];
        index2++;
        mainarr++;
    }
    delete[]left;
    delete[]right;
}
void mergesort(int arr[],int s,int e)
{
    if(s>=e)
    return;
    int mid=s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,h;
        cin>>n>>h;
        int enemy[n];
        for(int i=0;i<n;i++)
        cin>>enemy[i];
        mergesort(enemy,0,n-1);
        int sum=0;
        int i=n-1;
        for(;i>=0;i--)
        {
            sum+=enemy[i];
            if(sum>=h)
            break;
        }
        if(i<0)
        cout<<"0\n";
        else
        cout<<enemy[i]<<endl;
    }
}