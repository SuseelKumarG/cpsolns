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

ll binexp(ll a,ll b)
{
    ll ans=1;
    while (b)
    {
        if(b&1)
        ans=(ans*a)%MAX;
        b>>=1;
        a=(a*a)%MAX;
    }
    return ans;
}

pair<int,vector<int>> cond(vector<int> &a) {
    int maxSum = 0;
    int curSum = 0;
    int maxL = 0, maxR = 0;
    int L = 0;

    for (int R = 0; R < a.size(); R++) {
        curSum=2*(R-L+1)-(a[R]-a[L]+1);
        if (curSum <= 0) {
            curSum = 1;
            L = R;
        }
        if (curSum > maxSum) {
            maxSum = curSum;
            maxL = a[L]; 
            maxR = a[R];     
        }    
    }    
    return {maxSum,vector<int>{maxL+1, maxR+1}};
}

void solve()
{
    int n;
    cin>>n;
    map<int,vi>pos;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        pos[x].push_back(i);
    }
    int ans=0;
    vi temp;
    int curr=0;
    for(auto &it:pos)
    {
        int now=cond(it.second).first;
        vi ok=cond(it.second).second;
        if((now)>curr)
        {
            curr=(now);
            ans=it.first;
            temp=ok;
        }
    }
    cout<<ans<<' '<<temp[0]<<' '<<temp[1]<<'\n';
}

int main()
{
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