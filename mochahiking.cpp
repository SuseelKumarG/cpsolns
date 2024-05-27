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
#define MAX 1000000007



void solve()
{
    int n;
    cin>>n;
    vi arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    if(arr[n-1]==0)
    {
        for(int i=1;i<=n+1;i++)
            cout<<i<<' ';
        cout<<'\n';
        return;
    }
    if(arr[0]==1)
    {
        cout<<n+1<<' ';
        for(int i=1;i<=n;i++)
            cout<<i<<' ';
        cout<<'\n';
        return;
    }
    bool poss=0;
    int loc=-1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=0 && arr[i-1]==0)
        {
            loc=i;
            poss=1;
            break;
        }
    }
    if(poss)
    {
        for(int i=1;i<=n;i++)
        {
            if(i==loc)
            cout<<i<<' '<<n+1<<' ';
            else
            cout<<i<<' ';
        }
        cout<<'\n';
    }
    else
    cout<<-1<<'\n';
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}