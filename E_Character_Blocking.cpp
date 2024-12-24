    #include <bits/stdc++.h>
    using namespace std;
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
    
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef pair<ll, ll> pll;
    typedef pair<string, string> pss;
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef vector<pii> vii;
    typedef vector<ll> vl;
    typedef vector<vl> vvl; 
    typedef vector<pll> vll; 
    typedef vector<bool> vb;
    #define MAX 1000000007
    #define N 10010

    long long gcdl(long long a, long long b){
        while(a > 0 && b > 0){
            if(a > b){
                a %= b;
            }
            else{
                b %= a;
            }
        }
        return a + b;
    }  
    ll lcml(ll a,ll b)
    {
        a=(a*b)/gcdl(a,b);
        return a;
    }
    int gcd(int a, int b){
        while(a > 0 && b > 0){
            if(a > b){
                a %= b;
            }
            else{
                b %= a;
            }
        }
        return a + b;
    }
    int lcml(int a,int b)
    {
        a=(a*b)/gcd(a,b);
        return a;
    }

    void rep(string &s1,string &s2,int pos1,int pos2)
    {
        char c=s1[pos1];
        s1[pos1]=s2[pos2];
        s2[pos2]=c;
    }

    void solve()
    {
        vector<string>s(2);
        cin>>s[0]>>s[1];
        int n=s[0].length();
        int t,q;
        cin>>t>>q;
        multiset<pii>block;
        int curr=0;
        for(int i=0;i<n;i++)
        if(s[0][i]!=s[1][i])
        curr++;
        for(int i=0;i<q;i++)
        {
            while(!block.empty())
            {
                if(i==block.begin()->first)
                {
                    int pos=block.begin()->second;
                    if(s[0][pos]!=s[1][pos])
                    curr++;
                    block.erase(block.begin());
                }
                else
                break;
            }
            int type;
            cin>>type;
            if(type==1)
            {
                int pos;
                cin>>pos;
                pos--;
                if(s[0][pos]!=s[1][pos])
                curr--;
                block.insert({i+t,pos});
            }
            else if(type==2)
            {
                int x,pos1,y,pos2;
                cin>>x>>pos1>>y>>pos2;
                pos1--;
                pos2--;
                if(s[0][pos1]!=s[1][pos1])
                curr--;
                if(s[0][pos2]!=s[1][pos2])
                curr--;
                x--;
                y--;
                swap(s[x][pos1],s[y][pos2]);
                if(s[0][pos1]!=s[1][pos1])
                curr++;
                if(s[0][pos2]!=s[1][pos2])
                curr++;
            }
            else
            {
                cout<<(curr?"NO":"YES")<<'\n';
            }
        }
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