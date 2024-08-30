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
    set<int>unique;
    set<int>ind;
    map<int,int>li;
    for(int i=0;i<n;i++)
    li[a[i]]=i;
    for(auto it:li)
    {
        ind.insert(it.second);
        unique.insert(it.first);
    }
    cout<<ind.size()<<'\n';
    int turn=0;
    int prev=0;
    int last=0;
    vi ans;
    multiset<int>curr;
    while(!ind.empty())
    {
        int x=*(ind.begin());
        for(int i=prev;i<=x;i++)
        if(unique.find(a[i])!=unique.end())
        curr.insert(a[i]);
        int chk;
        if(turn&1)
        chk=*(curr.begin());
        else
        chk=*(--(curr.end()));
        for(int i=last;i<=x;i++)
        {
            if(unique.find(a[i])!=unique.end())
            {
                if(a[i]==chk)
                {
                    last=i+1;
                    curr.erase(a[i]);
                    unique.erase(a[i]);
                    ans.push_back(a[i]);
                    turn++;
                    ind.erase(li[a[i]]);
                    if(a[i]==a[x])
                    break;
                    if(turn&1)
                    chk=*(curr.begin());
                    else
                    chk=*(--(curr.end()));
                }
                else
                curr.erase(curr.find(a[i]));
            }
        }
        prev=x+1;
    }
    for(auto it:ans)
    cout<<it<<' ';
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