    #include <bits/stdc++.h>
    using namespace std;
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
    
    #define int long long
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef pair<ll, ll> pll;
    typedef pair<string, string> pss;
    typedef vector<int> vi;
    typedef vector<long double> vd;
    typedef vector<vd> vvd;
    typedef vector<vi> vvi;
    typedef vector<pii> vii;
    typedef vector<ll> vl;
    typedef vector<vl> vvl; 
    typedef vector<pll> vll; 
    typedef vector<bool> vb;
    #define MAX 998244353
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

    void solve()
    {
        int n;
        cin>>n;
        vi a(n);
        for(auto&i:a)
        {
            cin>>i;
        }
        int l=0,r=0;
        for(int i=1;i<n;i++)
        {
            if(abs(a[i])>abs(a[0]))
            r++;
            else
            l++;
        }
        int x=(n+1)/2-1;
        bool poss=0;
        if(x<=r)
        poss=1;
        if((x<=l+r)&&(x>=l))
        poss=1;
        cout<<(poss?"YES":"NO")<<'\n';
    }

    int32_t main()
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