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
    ll pre[1005][1005];
    void solve()
    {
        memset(pre,0,sizeof(pre));
        int n,q;
        cin>>n>>q;
        while(n--)
        {
            int i,j;
            cin>>i>>j;
            pre[i][j]+=i*j;
        }
        for(int i=1;i<=1002;i++)
        {
            for(int j=1;j<=1002;j++)
            {
                pre[i][j]+=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            }
        }
        while(q--)
        {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            cout<<pre[c-1][d-1]-pre[a][d-1]-pre[c-1][b]+pre[a][b]<<'\n';
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