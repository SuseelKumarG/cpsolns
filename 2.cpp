#include<bits/stdc++.h>
const unsigned long long int MOD=1e9+7;
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        string s;
        cin>>s;
        long long int count=1;
        for(long long int i=0;i<n-2;i+=2)
        {
            long long int tot=0;
            if(count==0)
            break;
            long long int x=s[i]-'0',y=s[i+1]-'0',z=s[i+2]-'0';
            if((x | y) == z)
            tot++;
            if((x & y) == z)
            tot++;
            if((x ^ y) == z)
            tot++;
            count*=tot;
        }
        cout<<count%MOD<<endl;
    }
}