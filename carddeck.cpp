#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr,int x,int n)
{
    int ind;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            ind=i;
            break;
        }
    }
    // vector<int>temp(n);
    // temp[0]=arr[ind];

    for(int i=ind;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=x;
    return ind+1;
}
int main()
{
        int n,m;
        cin>>n>>m;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        cin>>arr[i];
        while(m--)
        {
            int x;
            cin>>x;
            int ans=solve(arr,x,n);
            cout<<ans<<' ';
        }
}