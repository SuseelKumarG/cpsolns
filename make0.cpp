#include <bits/stdc++.h>
using namespace std;
void check(vector<int> &arr,int &ans,int bot)
{
    if(!bot)
    {
        if(arr[bot])
        {
            ans+=1;
            return;
        }
        else
        return;
    }
    int ind=-1;
    int min=1000000007;
    for(int i=bot-1;i>=0;i--)
    {
        if(arr[i]<min)
        {
            min=arr[i];
            ind=i;
        }
    }
    ans+=bot-ind-1;
    if(min<ind+1)
    ans+=min;
    else
    {
        ans+=ind+1;
        return;
    }
    for(int i=0;i<=ind;i++)
        arr[i]-=min;
    check(arr,ans,ind);
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        cin>>arr[i];
        int ans=0;
        int ind=-1;
        int min=1000000007;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]<min)
            {
                min=arr[i];
                ind=i;
            }
        }
        ans+=n-ind-1;
        if(min<ind+1)
        ans+=min;
        else
        ans+=ind+1;
        for(int i=0;i<=ind;i++)
        arr[i]-=min;
        check(arr,ans,ind);
        ans=ans>n? n:ans ;
        cout<<ans<<'\n';
    }
}
/*
my code here uses recursion 
i will check min of the given array and index of it from the right (so we can extend the range of type 1 deletion) and then check if min is
greater than the size ( if it is greater then why use 'min' type 1 deletions better to use 'n' type 2 deletions) and numbers to the right of
min can only be deleted by type 2 deletion.I am passing ind as length for the function and the function is recursive type
*/