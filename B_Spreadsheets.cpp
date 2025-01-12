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

bool done(string &s)
{
    for(auto it:s)
    {
        if(it>'Z'||it<'A')
        return 0;
    }
    return 1;
}

void type1(string &s)
{
    int n=s.length();
    ll r=0,c=0;
    bool ok=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='C')
        {
            ok=1;
            continue;
        }
        if(ok)
        {
            c*=10;
            c+=s[i]-'0';
        }
        else
        {
            r*=10;
            r+=s[i]-'0';
        }
    }
    ll po=26*26*26*26;
    string ans;
    while(po)
    {
        int x=c/po;
        if(x==0)
        ans.push_back('0');
        else
        ans.push_back(x-1+'A');
        c-=x*po;
        po/=26;
    }
    reverse(ans.begin(),ans.end());
    while(!done(ans))
    {
        while(ans.back()=='0')
        ans.pop_back();
        int ind=-1;
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(ans[i]=='0')
            {
                ind=i;
                break;
            }
        }
        if(ind==-1)
        break;
        ans[ind]='Z';
        ans[ind+1]--;
        if(ans[ind+1]<'A')
        ans[ind+1]='0';
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<r<<'\n';
}

void type2(string &s)
{
    string ans;
    ll r=0,c=0;
    bool ok=0;
    for(auto it:s)
    {
        if(it>'Z'||it<'A')
        {
            ok=1;
        }
        if(ok)
        {
            r*=10;
            r+=it-'0';
        }
        else
        {
            ans.push_back(it);
        }
    }
    ll po=1;
    reverse(ans.begin(),ans.end());
    for(auto it:ans)
    {
        c+=po*(it-'A'+1);
        po*=26;
    }
    cout<<'R'<<r<<'C'<<c<<'\n';
}

void solve()
{
    string s;
    cin>>s;
    int cnt=0;
    for(auto it:s)
    {
        if(it>='A'&&it<='Z')
        cnt++;
    }
    if(cnt==2)
    {
        if(s[1]>'Z'||s[1]<'A')
        type1(s);
        else
        type2(s);
    }
    else
    type2(s);
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