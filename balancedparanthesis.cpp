#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int> symb={{'(',-1},{'[',-2},{'{',-3},{')',1},{']',2},{'}',3}};
int solve(string &s);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        if(solve(s))
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
}
int solve(string &s)
{
    stack<char> ans;
    for(auto &ch : s)
    {
        if(symb[ch]<0)
        ans.push(ch);
        else
        {
            if(!(symb[ch]+symb[ans.top()]))
            ans.pop();
            else
            return 0;
        }
    }
    if(ans.empty())
    return 1;
    else
    return 0;
}