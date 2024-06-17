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

    ll rec(vii &a,vvl &dp,int x,int w)
    {
        if(!w)
        return 0;
        if(x<0)
        return 0;
        if(dp[x][w]!=-1)
        return dp[x][w];
        ll temp=rec(a,dp,x-1,w);
        if(w-a[x].second>=0)
        temp=max(temp,rec(a,dp,x-1,w-a[x].second)+a[x].first);
        dp[x][w]=temp;
        return dp[x][w];
    }

    void solve()
    {
        int n,m;
        cin>>n>>m;
        vector<string>a(n);
        for(int i=0;i<n;i++)
        cin>>a[i];
        int r,c;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='#')
                {
                    r=i;
                    c=j;
                    goto A;
                }
            }
        }
        A:
        // cout<<r<<' '<<c<<'\n';
        int cnt=0;
        for(int i=r;i<n;i++)
        {
            if(a[i][c]=='#')
            cnt++;
            else
            break;
        }
        // cnt;
        cnt>>=1;
        cout<<r+1+cnt<<' '<<c+1<<'\n';
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