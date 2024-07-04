    //in all subarrays of array a of length k have their or same then it is true for any sub array of length > k
    //END
    //to coprime numbers a and b can reproduce any number x greater than a*b-a-b as x= m*a+n*b
    //END
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
    typedef vector<vb> vvb;
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

    int cnt=0;

    void dfs(int i,int j,int n,int m,vector<string> &graph,vector<vector<bool>> &vis)
    {
        if(i<0||j<0)
        return;
        if(i>=n||j>=m)
        return;
        if(vis[i][j])
        return;
        vis[i][j]=1;
        if(graph[i][j]=='#')
        {
            cnt++;
            dfs(i+1,j,n,m,graph,vis);
            dfs(i-1,j,n,m,graph,vis);
            dfs(i,j+1,n,m,graph,vis);
            dfs(i,j-1,n,m,graph,vis);
        }
    }

    void solve()
    {
        int n,m;
        cin>>n>>m;
        vector<string>graph(n);
        for(int i=0;i<n;i++)
        cin>>graph[i];
        vvb vis(n,vb(m,0));
        vvb vis1(n,vb(m,0));
        set<pair<int,pii>>chk;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(graph[i][j]=='#')
                {
                    if(graph[i][j]=='#' && !vis[i][j])
                    {
                        cnt=0;
                        dfs(i,j,n,m,graph,vis);
                        // cout<<cnt<<'\n';
                        chk.insert({cnt,{i,j}});
                    }
                }
            }
        }
        string s;
        auto x=*(--(chk.end()));
        int a=x.second.first;
        int b=x.second.second;
        set<int>ans;
        for(int i=0;i<n;i++)
        {
            s=graph[i];
            for(int j=0;j<m;j++)
            {
                graph[i][j]='#';
            }
            vis=vis1;
            cnt=0;
            dfs(a,b,n,m,graph,vis);
            ans.insert(cnt);
            graph[i]=s;
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