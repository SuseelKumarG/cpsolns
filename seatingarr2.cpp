#include<bits/stdc++.h>
using namespace std;
bool sortbysec(pair<int,int> &a, pair<int,int> &b)
{
    return (a.second < b.second);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>arr(n*m);
        for(int i=0;i<n*m;i++)
        {
            int x;
            cin>>x;
            pair<int,int>temp;
            temp.first=x;
            temp.second=i;
            arr[i]=temp;
        }
        sort(arr.begin(),arr.end());
        // sort(arr.begin(),arr.end(),sortbysec);
        for(int i=0;i<n;i++)
        {
            sort(arr.begin()+i*m,arr.begin()+(i+1)*m,sortbysec);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int temp=0;
                for(int k=0;k<j;k++)
                {
                    if(arr[i*m+k].first<arr[i*m+j].first)
                    temp++;
                }
                ans+=temp;
            }
        }
        cout<<ans<<'\n';
    }
}