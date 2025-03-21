#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
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

vector<int> is_prime(2e5+10, 0);

void solve()
{
    int n;
    cin>>n;
    vl a(n);
    for(auto &it:a)
    cin>>it;
    ll curr=0;
    map<ll,ll>hsh;
    for(auto it:a)
    {
        hsh[it]++;
    }
    vi extr;
    for(auto it:hsh)
    extr.push_back(it.first);
    ll ans=0;
    for(int i=0;i<extr.size();i++)
    {
        if(is_prime[extr[i]]==extr[i])
        {
            curr+=hsh[extr[i]];
        }
        else if(is_prime[(extr[i]/is_prime[extr[i]])]==(extr[i]/is_prime[extr[i]]))
        {
            ans+=(hsh[extr[i]]*(hsh[extr[i]]+1))/2;
            if(hsh.count(is_prime[extr[i]]))
            ans+=hsh[is_prime[extr[i]]]*hsh[extr[i]];
            if(is_prime[extr[i]]*is_prime[extr[i]]!=extr[i])
            if(hsh.count(extr[i]/is_prime[extr[i]]))
            ans+=hsh[extr[i]/is_prime[extr[i]]]*hsh[extr[i]];
        }
    }
    ll temp=0;
    for(int i=0;i<extr.size();i++)
    {
        if(is_prime[extr[i]]==extr[i])
        {
            temp+=(curr-hsh[extr[i]])*hsh[extr[i]];
        }
    }
    temp/=2;
    ans+=temp;
    cout<<ans<<'\n';
}

int main()
{
is_prime[0] = is_prime[1] = -1;
for (int i = 2; i <= 2e5+5; i++) {
    if (!is_prime[i]) {
        is_prime[i]=i;
        if((long long)i * i <= 2e5+5)
        for (int j = i * i; j <is_prime.size(); j += i)
            is_prime[j] = i;
    }
}
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}