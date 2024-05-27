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
const  long long N=2*100010;
vector<int>factrl(N);

// void fact()
// {
//     factrl[0]=1;
//     factrl[1]=1;
//     for(int i=2;i<N;i++)
//     factrl[i]=i*factrl[i-1];
// }


void solve()
{
    int n;
    cin>>n;
    map<int,string>arr;
    string ans;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr[x].push_back(i+'0'+1);
        sum+=x;
    }
    for(auto it:arr)
    {
        int x=it.first;
        ll temp=sum-x;
        if(!(temp&1) && arr.find(temp/2)!=arr.end())
        ans+=it.second;
    }
    if(ans.size())
    {
        cout<<ans.size()<<'\n';
        for(auto it:ans)
        cout<<it<<' ';
        cout<<'\n';
    }
    else
    cout<<0<<'\n';
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // fact();
    // ll t;
    // cin>>t;
    // while(t--)
    // {
        solve();
    // }
    return 0;
}