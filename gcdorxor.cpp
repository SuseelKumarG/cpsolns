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
        int n,k;
        cin>>n>>k;
        vi a(n);
        for(auto &it:a)
        cin>>it;
        int x=-1,y;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=k)
            {
                if(x==-1)
                x=i;
                y=i;
            }
        }
        if(count(a.begin(),a.end(),k)==n)
        cout<<0<<'\n';
        else if(count(a.begin(),a.end(),1)==n)
        cout<<1<<'\n';
        else
        {
            int gc=1,xo=1;
            for(int i=1;i<n;i++)
            if(gcd(a[i],k)!=k)
            gc=0;
            int o=a[x]^k;
            for(int i=x;i<=y;i++)
            if((a[i]^k)!=o)
            xo=0;
            if(gc||xo)
            cout<<1<<'\n';
            else
            cout<<2<<'\n';
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
            solve();
        }
        return 0;
    }