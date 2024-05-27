#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        string s;
        cin>>n>>q>>s;
        int curr=1,maxm=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            curr++;
            else
            {
                maxm=max(curr,maxm);
                curr=1;
            }
        }
        cout<<maxm<<' ';
        vector<char>arr(q);
        for(int i=0;i<q;i++)
        {
            cin>>arr[i];
            if(i==0)
            {
                char init=arr[0],fin=s[n-1];
                if(init==fin)
                {
                    curr++;
                    maxm=max(curr,maxm);
                }
                else
                {
                    maxm=max(curr,maxm);
                    curr=1;
                }
                cout<<maxm<<' ';
            }
            else
            {
                if(arr[i]==arr[i-1])
                {
                    curr++;
                    maxm=max(curr,maxm);
                }
                else
                {
                    maxm=max(curr,maxm);
                    curr=1;
                }
                cout<<maxm<<' ';
            }
        }
        cout<<'\n';
    }
}