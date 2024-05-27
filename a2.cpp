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



void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    bool poss=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>=k)
        poss=1;
        arr[i]%=k;
    }
    sort(arr.begin(),arr.end());
    cout<<(poss? arr[0]:-1)<<'\n';
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}