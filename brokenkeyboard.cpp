#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--)
    {
        string inp,ans;
        cin>>inp;
        stack<int>upper,lower;
        for(int i=0;i<inp.size();i++)
        {
            char it=inp[i];
            if(it!='b' && it!='B')
            {
                if(it<='Z')
                upper.push(i);
                else
                lower.push(i);
            }
            else
            {
                if(it=='B' && !upper.empty())
                upper.pop();
                if(it=='b' && !lower.empty())
                lower.pop();
            }
        }
        vector<int>arr;
        while(!upper.empty())
        {
            int x=upper.top();
            arr.push_back(x);
            upper.pop();
        }
        while(!lower.empty())
        {
            int x=lower.top();
            arr.push_back(x);
            lower.pop();
        }
        sort(arr.begin(),arr.end());
        for(auto i:arr)
        {
            ans.push_back(inp[i]);
        }
        cout<<ans<<'\n';
    }
}