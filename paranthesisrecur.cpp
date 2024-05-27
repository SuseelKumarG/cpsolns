#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
void gen(string &s,int l,int r)
{
    if(!l && !r)
    {
        ans.push_back(s);
        return;
    }
    if(r>0)
    {
        if(l<r)
        {
            s.push_back(')');
            gen(s,l,r-1);
            s.pop_back();
        }
    }
    if(l>0)
    {
        s.push_back('(');
        gen(s,l-1,r);
        s.pop_back();
    }
    
}
int main()
{
    int n;
    cin>>n;
    int l,r=n;
    l=r;
    string s;
    gen(s,l,r);
    for(auto &it:ans)
    cout<<it<<'\n';
}