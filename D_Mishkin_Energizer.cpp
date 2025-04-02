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

ll binexp(ll a,ll b)
{
    ll ans=1;
    while (b)
    {
        if(b&1)
        ans=(ans*a)%MAX;
        b>>=1;
        a=(a*a)%MAX;
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n==1)
    {
        cout<<-1<<'\n';
        return;
    }
    unordered_map<char,int>hsh;
    for(auto it:s)
    hsh[it]++;
    int cnt=0;
    vi ans;
    string poss="LIT";
    while(1)
    {
        if(hsh['L']==hsh['I']&&hsh['I']==hsh['T'])
        {
            break;
        }
        int maxm=0;
        for(auto it:hsh)
        maxm=max(it.second,maxm);
        if(maxm==n)
        {
            cout<<-1<<'\n';
            return;
        }
        maxm++;
        string temp;
        int ind=-1;
        char ch;
        for(int i=0;i<(s.length()-1);i++)
        {
            for(auto it:poss)
            {
                if(it!=s[i]&&it!=s[i+1]&&s[i]!=s[i+1])
                {
                    if(hsh[it]<maxm)
                    {
                        maxm=hsh[it];
                        ch=it;
                        ind=i;
                    }
                }
            }
        }
        hsh[ch]++;
        ans.push_back(ind+1);
        for(int i=0;i<s.length();i++)
        {
            temp.push_back(s[i]);
            if(i==ind)
            temp.push_back(ch);
        }
        s=temp;
    }
    if(cnt>(2*n))
    {
        cout<<-1<<'\n';
        return;
    }
    cout<<ans.size()<<'\n';
    for(auto it:ans)
    cout<<it<<'\n';
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