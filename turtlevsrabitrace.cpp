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
#define N 10010

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
    vi a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=1;i<n;i++)
    a[i]+=a[i-1];
    int q;
    cin>>q;
    ll l,u,p,x,y;
    while(q--)
    {
        cin>>l>>u;
        l--;
        p=0;
        if(l)
        p=a[l-1];
        auto it=upper_bound(a.begin(),a.end(),u+p);
        int ans=int(it-a.begin());
        if(ans==l)
        ans++;
        else if(it!=a.end())
        {
            x=*(it),y=*(--it);
            x-=p;
            y-=p;
            // cout<<x<<' '<<y<<' ';
            x-=u+1;
            x=(x*(x+1))/2;
            ll temp=u*(u+1)/2;
            y=u-y;
            y=(y*(y+1))/2;
            if(temp-x>temp-y)
            ans++;
        }
        cout<<ans<<' ';
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
        solve();
    }
    return 0;
}