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
#define MAX 1000000007
const  long long N=2*100010;
vector<int>factrl(N);

// void fact()
// {
//     factrl[0]=1;
//     factrl[1]=1;
//     for(int i=2;i<N;i++)
//     factrl[i]=i*factrl[i-1];
// }


void solve()
{
    int n;
    ll ans=0;
    cin>>n;
    map<ll,ll>arr;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        x-=i+1;
        arr[x]++;
    }
    for(auto it:arr)
    {
        ll x=it.second;
        ans+=x*(x-1)/2;
    }
    cout<<ans<<'\n';
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // fact();
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}