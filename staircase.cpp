//in all subarrays of array a of length k have their or same then it is true for any sub array of length > k
//END
//to coprime numbers a and b can reproduce any number x greater than a*b-a-b as x= m*a+n*b
//END
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl; 
typedef vector<pll> vll; 
typedef vector<bool> vb;
#define MAX 1000000007
#define N 20015

long long gcdl(long long a, long long b){
    while(a > 0 && b > 0){
        if(a > b){
            a %= b;
        }
        else{
            b %= a;
        }
    }
    return a + b;
}  
ll lcml(ll a,ll b)
{
    a=(a*b)/gcdl(a,b);
    return a;
}
int gcd(int a, int b){
    while(a > 0 && b > 0){
        if(a > b){
            a %= b;
        }
        else{
            b %= a;
        }
    }
    return a + b;
}
int lcml(int a,int b)
{
    a=(a*b)/gcd(a,b);
    return a;
} 


void solve()
{
    int n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        while(!a[i]&&i<n)
        i++;
        vl chk;
        ll sum=0;
        while(a[i]&&i<n)
        {
            sum+=a[i];
            chk.push_back(a[i]);
            i++;
        }
        if(chk.size()==1)
        ans+=sum;
        else
        {
            sum<<=1;
            if(!((chk.size())&1))
            ans+=sum;
            else
            {
                ll temp=sum;
                for(int j=0;j<chk.size();j+=2)
                {
                    temp=min(temp,sum-chk[j]);
                }
                ans+=temp;
            }
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        // cout<<t<<0<<'\n';
        solve();
    }
    return 0;
}