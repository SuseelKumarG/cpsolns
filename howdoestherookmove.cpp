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
const int N =3e5+10;

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
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans[N]={1,1};
    for(int i=2;i<N;i++)
    ans[i]=(((2*(i-1))%MAX*1LL*ans[i-2])%MAX+ans[i-1])%MAX;
    ll t=1;
    cin>>t;
    while(t--)
    {
        // cout<<t<<"YO"<<'\n';
        int n;
        cin>>n;
        int k;
        cin>>k;
        int x,y;
        int ind=n;
        while(k--)
        {
            cin>>x>>y;
            if(x!=y)ind-=2;
            else ind--;
        }
        cout<<ans[ind]<<'\n';
    }
    return 0;
}   