#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        vector<string>inp(q-2);
        for(int i=0;i<q-2;i++)
        cin>>inp[i];
        string ans;
        ans+=inp[0];
        for(int i=1;i<q-2;i++)
        {
            if(ans.back()==inp[i][0])
            ans.push_back(inp[i][1]);
            else
            {
                ans.push_back(inp[i][0]);
                ans.push_back(inp[i][1]);
            }
        }
        while(ans.length()-q)
        ans.push_back('b');
        cout<<ans<<'\n';
    }
}