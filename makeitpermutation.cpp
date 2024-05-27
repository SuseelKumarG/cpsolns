// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// typedef pair<int, int> pii;
// typedef map<int, int> mii;
// typedef unordered_map<int, int> umii;
// typedef pair<ll, ll> pll;
// typedef map<ll, ll> mll;
// typedef unordered_map<ll, ll> umll;
// typedef pair<string, string> pss;
// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef vector<pii> vii;
// typedef vector<ll> vl;
// typedef vector<vl> vvl; 
// #define MAX 1000000007
// #define eps 0.000000001

// void solve()
// {
//     int n , c , d; cin>>n>>c>>d ;
//     map<int,int,greater<>>mp ;
//     while(n--){
//         int a; cin>>a ;
//         mp[a]++ ;
//     }
//     unsigned int cnt=0 , ans=LLONG_MAX , doub=0 ;
//     n=mp.size() ;
//     auto it=mp.begin();
//     for( ; it!=mp.end() ; ++it ){
//         unsigned int temp=c*cnt++ + ( it->first-n-- )*d ;
//         //cout<<n<<endl ;
//         ans=min(ans,temp) , doub+=it->second-1 ;//,  mp.erase(it) ;
//     }
//     it=mp.end() , it-- ;
//     if( it->first!=1 ){
//         ans=min(ans,d+(mp.size())*c) ;
//     }
//     else ans=min(ans,(mp.size())*c) ;
//     cout<<ans+doub*c<<'\n';
//     // ll n,c,d;
//     // cin>>n>>c>>d;
//     // ll in=0;
//     // set<ll>check;
//     // vl arr;
//     // for(int i=0;i<n;i++)
//     // {
//     //     int x;
//     //     cin>>x;
//     //     if(check.find(x)==check.end())
//     //     {
//     //         arr.push_back(x);
//     //         check.insert(x);
//     //     }
//     //     else
//     //     in+=c;
//     // }
//     // sort(arr.begin(),arr.end());
//     // n=arr.size();
//     // ll ans=INT_MAX;
//     // ll i=0;
//     // for(auto it:arr)
//     //     ans=min(ans,d*i++ +(it-n--)*c);
//     // if(arr[0]!=1)
//     // ans=min(n*c+d,ans);
//     // else
//     // ans=min(n*c,ans);
//     // cout<<ans+in<<'\n';
// }


// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll t=1;
//     cin>>t;
//     while(t--)
//     solve();
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int p[100005];
typedef long long ll;
void solve()
{
    int n,a,b;scanf("%d%d%d",&n,&a,&b);
    set<int> st;
    ll sol = 0 , ans = 2e18;
    for(int i = 1;i <= n;i++) {
        int x;scanf("%d",&x);
        if(st.find(x) == st.end()) st.insert(x);
        else sol += a;
    }
    int c = 0;
    for(auto x : st) p[c++] = x;
    for(int i = 0;i <c;i++) {
        ans = min(ans , 1LL*(p[i] - i-1)*b + 1LL*(c-i-1)*a);
    }
    ans = min(ans , 1LL*c*a + b) ;
    printf("%lld\n",ans+sol);
}
int main()
{
    int t;scanf("%d",&t);
    while(t--) solve();
}