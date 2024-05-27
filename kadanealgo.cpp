#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int maxm=INT_MIN,start=-1,end=-1,s=0,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>maxm)
        {
            maxm=sum;
            start=s;
            end=i;
        }
        if(sum<0)
        {
            sum=0;
            s=i+1;
        }
    }
    cout<<maxm<<'\n';
    for(int i=start;i<=end;i++)
    cout<<arr[i]<<' ';
    cout<<'\n';
}