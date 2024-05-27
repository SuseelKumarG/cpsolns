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
typedef vector<bool> vb;
#define MAX 1000000007

void solve()
{
    string s;
    cin>>s;
    vector<bool> arr(26);
    int m=0;
    for(auto it:s)
    {
        if(arr[it-'a'])
        {
            m+=2;
            // arr[it-'a']=0;
            for(int i=0;i<26;i++)
            arr[i]=0;
        }
        else
        arr[it-'a']=1;
    }
    cout<<s.length()-m<<'\n';
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