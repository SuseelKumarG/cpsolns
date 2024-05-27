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
#define eps 0.000000001

void solve()
{
    int n;
    cin>>n;
    vi arr;
    set<int>ans;
    map<int,int>check;
    bool poss=1;
    for(int i=0;i<n;i++)
    {   
        int x; 
        cin>>x;
        check[x]++;
        ans.insert(x);
    }
    for(auto it:check)
    {
        int a=it.first;
        int b=it.second;
        if(b<3)
        for(int i=0;i<b;i++)
        arr.push_back(a);
        else
        for(int i=0;i<3;i++)
        arr.push_back(a);
    }
    n=arr.size();
    if(poss)
    for(int i=0;i<n-2;i++)
    {
        if(!poss)
        break;
        for(int j=i+1;j<n-1;j++)
        {
            if(!poss)
            break;
            for(int k=j+1;k<n;k++)
            {
                if(!poss)
                break;
                if(ans.find(arr[i]+arr[j]+arr[k])==ans.end())
                poss=0;
            }
        }
    }
    cout<<(poss ? "YES" : "NO")<<'\n';
    
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