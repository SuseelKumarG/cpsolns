#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a,b;
        while(n--)
        {
            int x;
            cin>>x;
            if(x>0)
            a.push_back(x);
            else
            b.push_back(x);
        }
        n=min(a.size(),b.size());
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        reverse(b.begin(),b.end());
        reverse(a.begin(),a.end());
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i]+b[i];
            cout<<a[i]<<' '<<b[i]<<'\n';
        }
        cout<<sum<<'\n';
    }
}