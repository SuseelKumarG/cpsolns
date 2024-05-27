#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n),pse(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    reverse(arr.begin(),arr.end());
    stack<int>bot;
    for(int i=0;i<n;i++)
    {
        while(!bot.empty() && arr[i]<arr[bot.top()])
        {
            pse[bot.top()]=n-1-i;
            bot.pop();
        }
        bot.push(i);        
    }
    if(!bot.empty())
    {
        while(!bot.empty())
        {
            pse[bot.top()]=-1;
            bot.pop();
        }
    }
    reverse(pse.begin(),pse.end());
    for(auto it:pse)
    cout<<it<<' ';
    cout<<'\n';
}