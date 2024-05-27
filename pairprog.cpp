#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k,n,m;
        cin>>k>>n>>m;
        vector<int>a(n);
        vector<int>b(m);
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<m;i++)
        cin>>b[i];
        vector<int>ans(n+m);
        int p=0,q=0,r=0;
        while(p<n && q<m)
        {
            if(a[p]<b[q])
            {
                if(!a[p])
                {
                    k++;
                    p++;
                    ans[r]=0;
                    r++;
                }
                else if(a[p]<=k)
                {
                    ans[r++]=a[p++];
                }
                else
                break;
            }
            else
            {
                if(!b[q])
                {
                    ans[r]=0;
                    k++;
                    q++;
                    r++;
                }
                else if(b[q]<=k)
                ans[r++]=b[q++];
                else
                break;
            }
        }
        while(p<n)
        {
            if(!a[p])
            {
                ans[r++]=0;
                p++;
                k++;
            }
            else if(a[p]<=k)
            ans[r++]=a[p++];
            else
            break;
        }
        while (q<m)
        {
            if(!b[q])
            {
                ans[r++]=0;
                q++;
                k++;
            }
            else if(b[q]<=k)
            ans[r++]=b[q++];
            else
            break;
        }
        if(r!=n+m)
        cout<<-1<<'\n';
        else
        {
            for(auto it:ans)
            cout<<it<<' ';
            cout<<'\n';
        }
    }
}