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
#define N 400000

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
vector<bool> is_prime(N+1, true);

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    map<int,vi>cnt;
    for(int i=0;i<n;i++)
    cnt[a[i]].push_back(i);
    a.clear();
    for(auto &it:cnt)
    {
        if(it.first!=1)
        {
            if(it.second.size()>1)
            {
                cout<<it.second[1]+1<<' '<<it.second[0]+1<<'\n';
                return;
            }
        }
        a.push_back(it.first);
    }
    n=a.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(!is_prime[a[i]+a[j]] && cnt[a[i]][0]!=cnt[a[j]][0])
            {
                cout<<cnt[a[i]][0]+1<<' '<<cnt[a[j]][0]+1<<'\n';
                return;
            }
        }
    }
    cout<<-1<<'\n';
}

int main()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i] && (long long)i * i <= N) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
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