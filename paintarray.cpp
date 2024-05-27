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
        vector<long long>arr(n);
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long gc=0;
        bool real=1,fake=1;
        for(int i=0;i<n;i+=2)
        gc=__gcd(gc,arr[i]);
        for(int i=1;i<n;i+=2)
        {
            if(!(arr[i]%gc))
            {
                real=0;
                break;
            }
        }
        if(!real)
        {
            gc=0;
            for(int i=1;i<n;i+=2)
            gc=__gcd(gc,arr[i]);
            for(int i=0;i<n;i+=2)
            {
                if(!(arr[i]%gc))
                {
                    fake=0;
                    break;
                }
            }
        }
        if(real || fake)
        cout<<gc<<'\n';
        else
        cout<<0<<'\n';
    }
}