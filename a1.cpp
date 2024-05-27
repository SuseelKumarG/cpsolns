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
    vi arr(4);
    for(int i=0;i<4;i++)
    cin>>arr[i];
    // sort(arr.begin(),arr.end());
    // cout<<arr[1]+arr[2];
    float ans=ceil((float)arr[0]/(arr[3]*arr[2]-arr[1]));
    cout<<( arr[3]*arr[2]>arr[1]? ans : -1);
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // fact();
    // ll t;
    // cin>>t;
    // while(t--)
    {
        solve();
    }
    return 0;
}