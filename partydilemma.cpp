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
    int n,q;
    cin>>n>>q;
    vector<ll>arr(n),summation(n);
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        summation[i]=sum;
    }
    // for(int i=0;i<n;i++)
    // cout<<arr[i]<<' '<<summation[i]<<'\n';
    while(q--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        int dist=r-l+1;
        l-=2;
        r--;
        int tot;
        if(l>=0)
        tot=sum-summation[r]+summation[l]+dist*k;
        else
        tot=sum-summation[r]+dist*k;
        if(tot&1)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // fact();
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}