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
    ll lcm(ll a,ll b)
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

    void solve()
    {
        int n;
        cin>>n;
        vl a(n);
        int ans=0;
        ll maxm=0,l=1;
        map<int,int>cnt;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(maxm<a[i])
            maxm=a[i];
            cnt[a[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            l=lcm(l,a[i]);
            if(l>1e9)
            {
                ans=n;
                break;
            }
        }
        if(maxm<l)
        ans=n;
        // cout<<maxm<<'\n';
        for(ll i=1;i*i<=maxm;i++)
        {
            if(!(maxm%i))
            {if(cnt.find(i)==cnt.end())
            {
                int temp=0;
                ll x=1;
                for(auto it:cnt)
                {
                    ll y=it.first;
                    if(!(i%y))
                    {
                        temp+=it.second;
                        x=lcm(x,y);
                    }
                }
                if(x==i)
                ans=max(ans,temp);
            }
            if(cnt.find(maxm/i)==cnt.end())
            {
                int temp=0;
                ll x=1;
                for(auto it:cnt)
                {
                    ll y=it.first;
                    if(!((maxm/i)%y))
                    {
                        temp+=it.second;
                        x=lcm(x,y);
                    }
                }
                if(x==(maxm/i))
                ans=max(ans,temp);
            }
        }}
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
            solve();
        }
        return 0;
    }