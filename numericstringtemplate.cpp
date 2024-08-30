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
    vi a(n);
    for(auto &it:a)
    cin>>it;
    int m;
    cin>>m;
    string s;
    while(m--)
    {
        cin>>s;
        if(s.length()!=n)
        {
            cout<<"NO\n";
            continue;
        }
        map<int,char>chk;
        vi hsh(26,MAX);
        bool poss=1;
        for(int i=0;i<n;i++)
        {
            if(chk.find(a[i])==chk.end()&&hsh[s[i]-'a']==MAX)
            {
                chk[a[i]]=s[i];
                hsh[s[i]-'a']=a[i];
            }
            else
            {
                if(chk[a[i]]!=s[i]||hsh[s[i]-'a']!=a[i])
                poss=0;
            }
        }
        cout<<(poss?"YES":"NO")<<'\n';
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