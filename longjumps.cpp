// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;
//         vector<int>arr(n+10);
//         for(int i=1;i<=n;i++)
//             cin>>arr[i];
//         vector<int>ans(n+10,-1);
//         for(int i=n;i>0;i--)
//         {
//             if(i+arr[i]<=n)
//             {
//                 ans[i]=arr[i]+ans[i+arr[i]];
//             }
//             else
//             ans[i]=arr[i];
//         }
//         int max=-1;
//         for(int i=1;i<=n;i++)
//         {
//             if(max<ans[i])
//             max=ans[i];
//         }
//         cout<<max<<'\n';
//     }
// }
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
        vector<int>arr(n+1),dp(n+1);
        for(int i=1;i<=n;i++)
        cin>>arr[i];
        for(int i=n;i>0;i--)
        {
            if(i+arr[i]>n)
            dp[i]=arr[i];
            else
            dp[i]=arr[i]+dp[i+arr[i]];
        }
        sort(dp.begin(),dp.end());
        cout<<dp[n]<<'\n';
    }
}