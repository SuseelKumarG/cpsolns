#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>arr(m);
        for(int i=0;i<m;i++)
        cin>>arr[i];
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<i;j++)
            {
                int temp=0;
                if(arr[j]<arr[i])
                temp++;
                ans+=temp;
            }
        }
        cout<<ans<<'\n';
    }
}