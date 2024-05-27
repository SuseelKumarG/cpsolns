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
    int m,n;
    cin>>n>>m;
    vi arr(n),find(m);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    for(int i=0;i<m;i++)
    cin>>find[i];
    sort(arr.begin(),arr.end());
    sort(find.begin(),find.end());
    reverse(find.begin(),find.end());
    int arrl=0,arrr=n-1,findl=0,findr=m-1;
    ll sum=0;
    while(arrl<=arrr)
    {
        ll x=abs(arr[arrl]-find[findl]);
        ll y=abs(arr[arrr]-find[findr]);
        if(x>y)
        {
            arrl++;
            findl++;
            sum+=x;
        }
        else
        {
            arrr--;
            findr--;
            sum+=y;
        }
    }
    cout<<sum<<'\n';
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