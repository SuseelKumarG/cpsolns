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
    // cout<<1<<'\n';
    string s;
    cin>>s;
    int n=s.length();
    vi arr(26);
    for(int i=0;i<26;i++)
    {
        char ch='a'+i;
        int turn=0;
        vi temp(n);
        for(int j=0;j<n;j++)
        {
            if(s[j]==ch)
            temp[j]=0;
            else
            temp[j]=1;
        }
        while(1)
        {
            bool same=1;
            int ind=-1;
            for(int j=0;j<n;j++)
            {
                if(temp[j]==1)
                {
                    if(ind==-1 || ind!=j-1)
                    {
                        ind=j;
                        temp[j]=-1;
                    }
                    else
                    ind=-1;
                    same=0;
                }
                else if(temp[j]==0)
                ind=-1;
                else
                {
                    if(ind!=-1){
                        ind=j;
                    }
                }
            }
            if(same)
            break;
            turn++;
        }
        arr[i]=turn;
    }
    int min=INT_MAX;
    for(int i=0;i<26;i++)
    {
        if(arr[i]<min)
        min=arr[i];
    }
    cout<<min<<'\n';
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