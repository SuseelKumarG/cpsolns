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
    int n,m,k;
    cin>>n>>m>>k;
    int day=1;
    ll milk=0;
    // set<pii,greater<pii>>emp;
    pii x;
    ll ans=0;
    int ind=0;
    vii supp(n);
    for(auto &it:supp)
    cin>>it.first>>it.second;
    ll i=0;
    map<ll,set<pii,greater<pii>>>fridge;
    while(ind<n||!fridge[i].empty())
    {
        if(ind<n&&day==supp[ind].first)
        {
            x=supp[ind];
            x.first+=k;
            milk+=x.second;
            fridge[i].insert(x);
            ind++;
        }
        if(!fridge[i].empty())
        {
            auto it=--fridge[i].end();    
            if(it->first==day)
            {
                milk-=it->second;
                fridge[i].erase(it);
            }
        }
        if(milk>=m)
        {
            // cout<<day<<' '<<milk<<'\n';
            ans++;
            milk-=m;
            int h=m;
            while(h)
            {
                if(fridge[i].begin()->second>h)
                {
                    pii temp=*fridge[i].begin();
                    fridge[i].erase(fridge[i].begin());
                    temp.second-=h;
                    fridge[i].insert(temp);
                    h=0;
                }
                else
                {
                    pii temp=*fridge[i].begin();
                    h-=temp.second;
                    fridge[i].erase(fridge[i].begin());
                }
            }
        }
        else
        {
            milk=0;
            i++;
        }
        day++;
    }
    cout<<ans<<'\n';
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