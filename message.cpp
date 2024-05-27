#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long long n,f,a,b;
        cin>>n>>f>>a>>b;
        vector<long long>arr(n);
        for(int i=0;i<n;i++)
        cin>>arr[i];
        // cout<<n<<' '<<f<<' '<<a<<' '<<b<<'\n';
        long long messages=n,curr=0;
        bool found=1;
        for(int i=0;i<n && messages && found;i++)
        {
            if((arr[i]-curr)*a<b)
            {
                f-=(arr[i]-curr)*a;
                curr=arr[i];
                if(f>0)
                messages--;
                else
                found=0;
            }
            else
            {
                f-=b;
                curr=arr[i];
                if(f>0)
                messages--;
                else
                found=0;
            }
        }
        if(found)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
}