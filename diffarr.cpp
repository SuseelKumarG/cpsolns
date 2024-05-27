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
        int n,m;
        cin>>n>>m;
        deque<long long>arr(n),inp(m);
        vector<long long>v;
        for(int i=0;i<n;i++)
        cin>>arr[i];
        for(int i=0;i<m;i++)
        cin>>inp[i];
        sort(arr.begin(),arr.end());
        sort(inp.begin(),inp.end());
        reverse(arr.begin(),arr.end());
        long long ans=0;
        int i=0;
        while(i<n)
        {
            long long a=abs(arr.back()-inp.back());
            long long b=abs(arr.front()-inp.front());
            if(a>b)
            {
                v.push_back(a);
                arr.pop_back();
                inp.pop_back();
            }
            else
            {
                v.push_back(b);
                arr.pop_front();
                inp.pop_front();
            }
            i++;
        }
        for(auto it:v)
        ans+=it;
        cout<<ans<<'\n';
    }
}