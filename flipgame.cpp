#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    bool all1=1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i])
        b[i]=-1;
        else
        b[i]=1;
        if(!a[i])
        all1=0;
    }
    int maxm=0,strt=-1,end=-1,sum=0,s=0;
    for(int i=0;i<n;i++)
    {
        sum+=b[i];
        if(sum>maxm)
        {
            maxm=sum;
            strt=s;
            end=i;
        }
        if(sum<0)
        {
            sum=0;
            s=i+1;
        }
    }
    if(all1)
    cout<<n-1<<'\n';
    else
    {
            // cout<<strt<<' '<<end<<'\n';
            // cout<<maxm<<'\n';
            for(int i=0;i<strt;i++)
            {
                if(a[i])
                maxm++;
            }
            for(int i=end+1;i<n;i++)
            {
                if(a[i])
                maxm++;
            }
            for(int i=strt;i<=end;i++)
            if(a[i])
            maxm++;
        cout<<maxm<<'\n';
    }
}