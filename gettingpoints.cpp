#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        long long n,p,l,t,cnt=0,task,maxwork,maxday;
        cin>>n>>p>>l>>t;
        task=ceil(n/7.0);
        // cout<<task<<' ';
        maxday=ceil((float)p/((2*t)+l));
        maxwork=(2*t)+l;
        if(maxday<=(task/2))
        {
            cnt=maxday;
            p-=maxday*maxwork;
        }
        else
        {
            cnt=(task/2);
            p-=(task/2)*maxwork;
        }
        // cout<<cnt<<' ';
        if(task&1)
        task=1;
        else
        task=0;
        while(p>0)
        {
            if(task)
            {
                cnt++;
                p-=l+t;
                task=0;
            }
            else{
                cnt+=ceil((float)p/l);
                p=0;
            }
        }
        cout<<n-cnt<<'\n';
    }
}