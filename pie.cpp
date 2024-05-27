#include<bits/stdc++.h>
#define pi 3.14159265358979323846264338327950
using namespace std;
const long double eps=1e-6;
int n,f;
bool poss(int f,long double mid,vector<int>&arr);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>f;
        f++;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        if(n>=f)
        {
            cout<<setprecision(15)<<pi*pow(arr[n-f],2)<<'\n';
            continue;
        }
        long double lo=0,hi=pi*pow(arr[n-1],2);
        while(hi-lo>eps)
        {
            long double mid=(hi-lo)/2+lo;
            if(poss(f,mid,arr))
            {
                lo=mid;
            }
            else
            hi=mid;
        }
        if(poss(f,hi,arr))
        cout<<setprecision(15)<<hi<<'\n';
        else
        cout<<setprecision(15)<<lo<<'\n';
    }
}
bool poss(int f,long double mid, vector<int> &arr)
{
    for(auto it:arr)
    {
        long double vol=pi*pow(it,2);
        int a=(vol/mid);
        f-=a;
    }
    return f<=0;
}
/*
it gave error because we need to give more accuurate number
*/