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
    typedef vector<pll> vll;
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

    void solve()
    {
        int h,n;
        cin>>h>>n;
        vll a(n);
        set<pll>chk;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].first;
        }
        for(int i=0;i<n;i++)
            cin>>a[i].second;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
            chk.insert({1,i});
        ll temp=1;
        while(h>0)
        {
            pll x=*chk.begin();
            temp=x.first;
            chk.erase(chk.begin());
            chk.insert({x.first+a[x.second].second,x.second});
            h-=a[x.second].first;
        }  
        cout<<temp<<'\n';
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