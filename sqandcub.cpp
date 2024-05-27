#include<bits/stdc++.h>
using namespace std;
const unsigned int N=1000000000;
int main()
{
    // vector<int>checker(31622)
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        set<int>ans;
        for(int i=1;i*i<=n;i++)
            ans.insert(i*i);
        for(int i=1;(i*i*i)<=n;i++)
            ans.insert(i*i*i);
        // vector<int>finaling;
        cout<<ans.size()<<'\n';
        // for(auto it:ans)
        // finaling.push_back(it);
        // cout<<finaling.size();
    }
}