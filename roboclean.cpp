#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,rb,cb,rd,cd;
        cin>>n>>m>>rb>>cb>>rd>>cd;
        int ans=0;
        int dc=1,dr=1;
        while(rb!=rd && cb!=cd)
        {
            if(rb==n && dc==1)
            dc*=-1;
            if(rb==1 && dc==-1)
            dc*=-1;
            if(cb==m && dr==1)
            dr*=-1;
            if(cb==1 && dr==-1)
            dr*=-1;
            ans++;
            rb+=dc;
            cb+=dr;
        }
        cout<<ans<<'\n';
    }
}