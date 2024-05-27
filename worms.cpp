#include<bits/stdc++.h>
using namespace std;
long long sum=0;
int ind(long long a[],long long x,int n);
int main()
{
    int n;
    cin>>n;
    long long a[n];
    memset(a,0,n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]+=sum;
        sum=a[i];
    }
    int m;
    cin>>m;
    long long x;
    while(m--)
    {
        cin>>x;
        cout<<ind(a,x,n)<<'\n';
    }
}
int ind(long long a[],long long x,int n)
{
    int i=0,j=n-1;
    while(j-i>1)
    {
        int mid=(j-i)/2+i;
        if(x>a[mid])
        i=mid;
        else
        j=mid;
    }
    if(a[i]>=x)
    return i+1;
    else if(a[j]<x)
    return j+2;
    else
    return j+1;
}