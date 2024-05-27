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
    ll sum=0;
    vi arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    ll curr=0,max=0,start=0,end=0,s=0;
    for(int i=0;i<n;i++)
    {
        curr+=arr[i];
        if(curr>max)
        {
            end=i;
            start=s;
            max=curr;
        }
        if(curr<=0)
        {
            s=i+1;
            curr=0;
        }
    }
    start++;
    end++;
    bool poss=1;
    if(curr>=sum && !(start==1 && end==n))
    poss=0;
    cout<<(poss ? "YES\n" : "NO\n");

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