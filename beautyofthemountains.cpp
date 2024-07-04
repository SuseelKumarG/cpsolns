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

    void chk(int k,int i,int j,vi &co1,vi &co2,vector<string> &types,int t)
    {
        for(int x=0;x<k;x++)
        {
            for(int y=0;y<k;y++)
            {
                if(types[i+x][j+y]=='0') co1[t]++;
                else co2[t]++;
            }
        }
    }

    void solve()
    {
        bool poss=0;
        int n,m,k;
        cin>>n>>m>>k;
        vvi a(n,vi(m,0));
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin>>a[i][j];
        vector<string>types(n);
        for(int i=0;i<n;i++)
        cin>>types[i];
        vvi pre(n,vi(m,0));
        for(int i=0;i<n;i++)
        {
            pre[i][0]=-1;
            if(types[i][0]=='1') pre[i][0]=1;
        }
        for(int i=0;i<=n-1;i++)
        {
            for(int j=1;j<=m-1;j++)
            {
                pre[i][j]=pre[i][j-1];
                if(types[i][j]=='1') pre[i][j]++;
                else pre[i][j]--;
            }
        }
        for(int j=0;j<m;j++)
        {
            for(int i=1;i<n;i++)
            pre[i][j]+=pre[i-1][j];
        }
        ll diff=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(types[i][j]=='0') diff+=a[i][j];
                else diff-=a[i][j];
            }
        }
        diff=abs(diff);
        if(!diff) poss=1;
        int cnt=0;
        int gc=0;
        for(int i=0;i<=n-k;i++)
        {
            for(int j=0;j<=m-k && !poss;j++)
            {
                int x=pre[i+k-1][j+k-1];
                if(i>0) x-=pre[i-1][j+k-1];
                if(j>0) x-=pre[i+k-1][j-1];
                if(i>0&&j>0) x+=pre[i-1][j-1];
                x=abs(x);
                if(x)
                {
                    if(!(diff%x))
                    poss=1;
                    cnt++;
                    gc=gcd(gc,x);   
                }
            }
        }
        if(gc)
        if(!(diff%gc))
        poss=1;
        cout<<(poss?"YES":"NO")<<'\n';
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll t=1;
        cin>>t;
        // cout<<5%0<<'\n';
        while(t--)
        {
            // cout<<t<<"YO"<<'\n';
            solve();
        }
        return 0;
    }