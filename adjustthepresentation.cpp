#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
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
    int n,m,q;
    cin>>n>>m>>q;
    vi a(n);
    vi b(m);
    for(auto &it:a)
    cin>>it;
    for(auto &it:b)
    cin>>it;
    //for stroring positions 
    map<int,int>pos;
    for(int i=0;i<n;i++)
    pos[a[i]]=i+1;
    //to store the indexes
    vector<set<int>>ind(n+1);
    for(int i=0;i<m;i++)
    ind[pos[b[i]]].insert(i+1);
    //default index if number is not repeated
    for(int i=1;i<=n;i++)
    ind[i].insert(m+1);
    // index where the number is first seen
    vi fin(n+2);
    fin[0]=-1;
    fin[n+1]=m+10;
    for(int i=1;i<=n;i++)
    {
        fin[i]=*ind[i].begin();
    }
    //counting pairs that obey fin[i]<=fin[i+1]
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(fin[i]<=fin[i+1])
        ans++;
    }
    for(auto it:fin)
    cout<<it<<' ';
    cout<<'\n';
    cout<<ans<<'\n';
    cout<<((ans==n)?"YA":"TIDAK")<<'\n';
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        bool o,p,q,s,A,B,C,D;
        o=p=q=s=A=B=C=D=0;
        cout<<b[l-1]<<'\n';
        //keeping track of changes
        if(fin[pos[b[l-1]]]<=fin[pos[b[l-1]]+1])
        o=1;
        if(fin[pos[b[l-1]]-1]<=fin[pos[b[l-1]]])
        A=1;
        if(fin[pos[r]]<=fin[pos[r]+1])
        p=1;
        if(fin[pos[r]-1]<=fin[pos[r]])
        B=1;
        //changing
        ind[pos[b[l-1]]].erase(l);
        ind[pos[r]].insert(l);
        fin[pos[b[l-1]]]=*ind[pos[b[l-1]]].begin();
        fin[pos[r]]=*ind[pos[r]].begin();
        if(fin[pos[b[l-1]]]<=fin[pos[b[l-1]]+1])
        q=1;
        if(fin[pos[b[l-1]]-1]<=fin[pos[b[l-1]]])
        C=1;
        if(fin[pos[r]]<=fin[pos[r]+1])
        s=1;
        if(fin[pos[r]-1]<=fin[pos[r]])
        D=1;
        //changing
        if(o^q)
        {
            if(o)
            ans--;
            else
            ans++;
        }
        if(A^C)
        {
            if(A)
            ans--;
            else
            ans++;
        }
        // removing double changes
        if(b[l-1]!=r)
        if(p^s)
        {
            if(p)
            ans--;
            else
            ans++;
        }
        if(b[l-1]!=r)
        if(B^D)
        {
            if(B)
            ans--;
            else
            ans++;
        }
        //assigning after change
        b[l-1]=r;
        for(auto it:fin)
        cout<<it<<' ';
        cout<<'\n';
        cout<<ans<<'\n';
        cout<<o<<' '<<q<<'\n';
        cout<<A<<' '<<C<<'\n';
        cout<<p<<' '<<s<<'\n';
        cout<<B<<' '<<D<<'\n';
        cout<<((ans==n)?"YA":"TIDAK")<<'\n';
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