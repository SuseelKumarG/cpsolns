#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
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
#define all(a) a.begin(),a.end()
#define MAX 1000000007
#define N 10010

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << ": "; deb(x); cerr << endl;
#else
#define debug(x)
#endif
 
void deb(int t) { cerr << t; }
void deb(string t) { cerr << t; }
void deb(char t) { cerr << t; }
void deb(double t) { cerr << t; }
void deb(ull t) { cerr << t; }
 
template <class T, class V> void deb(pair<T, V> p) { cerr << "{"; deb(p.ff); cerr << ","; deb(p.ss); cerr << "}"; }
template <class T> void deb(vector<T> v) { cerr << "[ "; for (T i : v) { deb(i); cerr << " "; } cerr << "]"; }
template <class T> void deb(set<T> v) { cerr << "[ "; for (T i : v) { deb(i); cerr << " "; } cerr << "]"; }
template <class T> void deb(multiset<T> v) { cerr << "[ "; for (T i : v) { deb(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void deb(map<T, V> v) { cerr << "[ "; for (auto i : v) { deb(i); cerr << " "; } cerr << "]"; }

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
    int n;
    cin>>n;
    char trump;
    cin>>trump;
    map<char,vector<int>>type;
    string s;
    for(int i=0;i<2*n;i++)
    {
        cin>>s;
        type[s[1]].push_back(s[0]-'0');
    }
    int odd=0;
    vector<pair<string,string>>extra;
    for(auto it:type)
    sort(it.second.begin(),it.second.end());
    // for(auto it:type)
    // {
    //     cout<<it.first<<'\n';
    //     for(auto tit:it.second)
    //     cout<<tit<<' ';
    //     cout<<'\n';
    // }
    // cout<<'\n';
    for(auto &it:type)
    {
        sort(it.second.begin(),it.second.end());
        if(it.first!=trump)
        {
            if(it.second.size()%2)
            {
                if(!type[trump].empty())
                {
                    string a,b;
                    a.push_back(it.second.back()+'0');
                    a.push_back(it.first);
                    b.push_back(type[trump].back()+'0');
                    b.push_back(trump);
                    extra.push_back({a,b});
                    it.second.pop_back();
                    type[trump].pop_back();
                }
                else
                poss=0;
            }
            string pre;
            for(int i=0;i<it.second.size();i++)
            {
                if(!(i&1))
                {
                    pre.clear();
                    pre.push_back(it.second[i]+'0');
                    pre+=it.first;
                }
                else
                {
                    string b;
                    b.push_back(it.second[i]+'0');
                    b+=it.first;
                    extra.push_back({pre,b});
                }
            }
        }
    }
    if(type[trump].size()%2)
    poss=0;
    else
    {
        string pre;
        for(int i=0;i<type[trump].size();i++)
        {
            if(!(i&1))
            {
                pre.clear();
                pre.push_back(type[trump][i]+'0');
                pre+=trump;
            }
            else
            {
                string b;
                b.push_back(type[trump][i]+'0');
                b+=trump;
                extra.push_back({pre,b});
            }
        }
    }
    if(poss)
    {
        for(auto it:extra)
        cout<<it.first<<' '<<it.second<<'\n';
    }
    else
    cout<<"IMPOSSIBLE\n";
    // debug(extra);
    // cout<<'\n';
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