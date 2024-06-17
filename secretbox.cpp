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
        vl sl(3);
        ll k;
        for(int i=0;i<3;i++)
        cin>>sl[i];
        cin>>k;
        sort(sl.begin(),sl.end());
        vl fl(3,-1);
        ll ans=0;
        for(int i=1;i<=sl[0];i++)
        {
            for(int j=1;j<=sl[1];j++)
            {
                if(!(k%(i*j*1LL))&&(k/(i*j*1LL)<=sl[2]))
                {
                    fl[0]=i;
                    fl[1]=j;
                    fl[2]=k/(i*j*1LL);
                    ans=max((sl[0]-fl[0]+1LL)*(sl[1]-fl[1]+1LL)*(sl[2]-fl[2]+1LL),ans);
                    // break;
                }
            }
        }
        // if(fl[0]==-1)
        // {
        //     cout<<0<<'\n';
        //     return;
        // }
        // for(int i=0;i<3;i++)
        // {
        //     fl[i]=(sl[i]-fl[i]+1);
        // }
        // cout<<fl[0]*fl[1]*fl[2]<<'\n';
        cout<<ans<<'\n';
        // for(int i=0;i<3;i++)
        // cout<<fl[i]<<' ';
        // cout<<'\n';
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