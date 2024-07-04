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
typedef vector<pll> vll; 
typedef vector<bool> vb;
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


void solve()
{
    bool poss=1;
    ll n,k;
    cin>>n>>k;
    vi a(n);
    map<int,set<int>>mo;
    for(ll i=0;i<n;i++)
    cin>>a[i];
    for(auto it:a) 
    {
        if(mo[it%k].find(it)!=mo[it%k].end()) 
        mo[it%k].erase(it);
        else 
        mo[it%k].insert(it);
    }
    ll ans=0;
    int cnt=0;
    int val=-1;
    for(auto it:mo)
    {
        if(it.second.size()&1)
        {
            cnt++;
            val=it.first;
        }
    }
    if(cnt>1)
    {
        cout<<-1<<'\n';
        return;
    }
    for(auto it:mo)
    {
        if(it.first==val)
        continue;
        while(it.second.size())
        {int x=*(it.second.begin());
        it.second.erase(it.second.begin());
        if(!(it.second.size()))
        break;
        int y=*(it.second.begin());
        it.second.erase(it.second.begin());
        ans+=(y-x)/k;}
        // if(it.second.size()==0)
        // mo.erase(it.first);
    }
    if(cnt)
    {
        vi v;
        for(auto it:mo[val]) 
        v.push_back(it);
        int m=v.size();
        if(m==1)
        goto A;
        vi pref(m),suf(m);
        pref[1]=v[1]-v[0];
        for(int i=3;i<m;i+=2)
        pref[i]=v[i]-v[i-1]+pref[i-2];
        suf[m-2]=v[m-1]-v[m-2];
        for(int i=m-4;i>=0;i-=2)
        suf[i]=suf[i+2]+v[i+1]-v[i];
        int temp=INT_MAX;
        for(int i=0;i<m;i+=2)
        {
            int x=0;
            if(i > 0)
            x+=pref[i-1];
            if(i + 1 < m)
            x+=suf[i+1];
            temp=min(temp,x);
        }
        ans+=temp/k;
    }
    A:
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
        // cout<<t<<0<<'\n';
        solve();
    }
    return 0;
}