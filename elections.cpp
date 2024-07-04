//in all subarrays of array a of length k have their or same then it is true for any sub array of length > k
//END
//to coprime numbers a and b can reproduce any number x greater than a*b-a-b as x= m*a+n*b
//END
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<ull> vul;
typedef vector<vl> vvl; 
typedef vector<pll> vll; 
typedef vector<bool> vb;
#define all(x) x.begin(),x.end()
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
    int n,c;
    cin>>n>>c;
    vi a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    a[0]+=c;
    int maxm=0;
    map<int,vi>chk;
    for(int i=0;i<n;i++)
    {
        if(maxm<a[i])
        maxm=a[i];
        chk[a[i]].push_back(i);
    }
    vul pref(n);
    pref[0]=a[0];
    for(int i=1;i<n;i++)
    {
        pref[i]=pref[i-1]+a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]<maxm)
        {
            if(pref[i]<maxm)
            cout<<i+1<<' ';
            else
            cout<<i<<' ';
        }
        if(a[i]==maxm)
        {
            if(chk[a[i]][0]!=i)
            cout<<i<<' ';
            else
            cout<<0<<' ';
        }
    }
    cout<<'\n';
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
        // cout<<t<<'\n';
        solve();
    }
    return 0;
}