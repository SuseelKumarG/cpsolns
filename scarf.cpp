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
    string s;
    cin>>n>>s;
    vector<int>arr(26,0);
    for(int i=0;i<26;i++)
    {
        char curr='a'+i;
        int cnt=0;
        int l=0,r=n-1;
        while(l<r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else{
                if(s[l]==curr)
                {
                    l++;
                    cnt++;
                }
                else if(s[r]==curr)
                {
                    r--;
                    cnt++;
                }
                else
                {
                    cnt=-1;
                    break;
                }
            }
        }
        arr[i]=cnt;
    }
    int min=3276800;
    for(int i=0;i<26;i++)
    {
        if(arr[i]>=0)
        {
            if(min>arr[i])
            min=arr[i];
        }
    }
    cout<<(min==3276800 ? -1 : min)<<'\n';
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