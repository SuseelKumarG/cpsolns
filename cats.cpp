#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string s,f;
        cin>>s>>f;
        int s1=0,f1=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]-'0')
            s1++;
            if(f[i]-'0')
            f1++;
            if(s[i]==f[i] && s[i]=='1')
            cnt++;
        }
        int ans=0;
        ans=abs(s1-f1);
        s1=min(s1,f1);
        ans+=s1-cnt;
        cout<<ans<<'\n';
    }
    
}