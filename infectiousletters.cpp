#include<bits/stdc++.h>
using namespace std;
void fcn(queue<int>&b,queue<int>&a,string &s);
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    queue<int>b,a;
    int i=0;
    for(auto it:s)
    {
        if(it=='a')
        a.push(i);
        if(it=='b')
        b.push(i);
        i++;
    }
    fcn(b,a,s);
    int count=0;
    for(auto it:s)
    if(it=='a')
    count++;
    cout<<count<<'\n';
}
void fcn(queue<int> &b, queue<int> &a, string &s)
{
    int A=a.front(),B=-1;
    while(!a.empty() && !b.empty())
    {
        if(b.front()>A)
        {
            for(int i=B+1;i<b.front();i++)
            s[i]='a';
            a.pop();
            A=a.front();
        }
        // else if(b.empty() && !a.empty())
        // {
        //     for(int i=B+1;i<s.size();i++)
        //     s[i]='a';
        //     break;
        // }
        else
        {
            B=b.front();
            b.pop();
        }
    }
    if(!a.empty())
    {
        for(int i=B+1;i<s.size();i++)
        s[i]='a';
    }
}
