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
typedef vector<vl> vvl; 
typedef vector<pll> vll; 
typedef vector<bool> vb;
typedef vector<vb> vvb;
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

ll modexp(ll base,ll exp) 
{
    ll ans=1;
    while(exp>0)
    {
        if(exp%2==1) ans=(ans*base)%MAX;
        base=(base*base)%MAX;
        exp/=2;
    }
    return ans;
}

void ans(int &u,int x,int n)
{
    if(x==n-1)
    u=-1;
    else
    {
        u=x;
    }
}

void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<n;i++)
    cout<<i<<' '<<i+1<<'\n';
    int curr=n-1;
    while(q--)
    {
        int x;
        cin>>x;
        // int u,v;
        if(x==curr)
        {
            cout<<-1<<' '<<-1<<' '<<-1<<'\n';
            continue;
        }
        cout<<n<<' '<<curr<<' '<<x<<'\n';        
        curr=x;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        // cout<<t<<"YO"<<'\n';
        solve();
    }
    return 0;
}   