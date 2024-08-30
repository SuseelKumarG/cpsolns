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
    int n;
    cin>>n;
    string s;
    cin>>s;
    vii cnt;
    map<int,int>hsh;
    for(auto it:s)
    hsh[it-'a']++;
    for(auto &it:hsh)
    cnt.push_back({it.first,it.second});
    int l=0;
    int r=cnt.size()-1;
    while(l<r)
    {
        cout<<char(cnt[l].first+'a');
        cout<<char(cnt[r].first+'a');
        cnt[l].second--;
        cnt[r].second--;
        if(!cnt[l].second)
        l++;
        if(!cnt[r].second)
        r--;
    }
    if(l==r)
    {
        while(cnt[l].second--)
        {
            cout<<char(cnt[l].first+'a');
        }
    }
    cout<<'\n';
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