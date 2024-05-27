#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl; 
#define MAX 1000000007
#define eps 0.000000001

void solve()
{
    int n;
    cin>>n;
    vi arr(n);
    bool poss=1;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vi cnt(n+1);
    for(int i=0;i<n;i++)
    {
        if(cnt[arr[i]]<2)
        cnt[arr[i]]++;
        else
        poss=0;
    }
    if(poss)
    {
      stack<int>zero,two;
      vi dir(n+1);
      for(int i=1;i<=n;i++)
      {
        if(cnt[i]==0)
        zero.push(i);
        if(cnt[i]==2)
        two.push(i);
      }  
      if(zero.size()!=two.size())
      poss=0;
    //   cout<<zero.size()<<' '<<two.size()<<"HI\n";
      while(!zero.empty() && poss)
      {
        if(two.top()<zero.top())
        poss=0;
        else
        {
            dir[two.top()]=zero.top();
            two.pop();
            zero.pop();
        }
      }
      vi p=arr,q=arr;
      if(poss)
      {
        cout<<"YES\n";
        
        for(int i=0;i<n;i++)
        {
            if(cnt[arr[i]]==2)
            {
                p[i]=dir[arr[i]];
                cnt[arr[i]]--;
            }
            else if(cnt[arr[i]]==1 && dir[arr[i]])
            {
                q[i]=dir[arr[i]];
                cnt[arr[i]]--;
            }
        }
        for(auto it:p)
        cout<<it<<' ';
        cout<<'\n';
        for(auto it:q)
        cout<<it<<' ';
        cout<<'\n';
        return;
      }
    }
    // cout<<(poss? "YES":"NO")<<'\n';
    cout<<"NO\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    solve();
    return 0;
}