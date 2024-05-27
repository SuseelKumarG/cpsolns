#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int>nse(n);
    vector<int>pse(n);
    stack<int>dot;
    for(int i=0;i<n;i++)
    {
        while(!dot.empty() && arr[i]<arr[dot.top()])
        {
            nse[dot.top()]=i;
            dot.pop();
        }
        dot.push(i);        
    }
    if(!dot.empty())
    {
        while(!dot.empty())
        {
            nse[dot.top()]=n;
            dot.pop();
        }
    }
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
    reverse(arr.begin(),arr.end());
    reverse(pse.begin(),pse.end());
    int maxm=0;
    for(int i=0;i<n;i++)
    {
        int area=(nse[i]-pse[i]-1)*arr[i];
        maxm=max(maxm,area);
    }
    cout<<maxm;
}
/*
next smaller element has same logic as next larger element and previous smaller element has same logic as next smaller element for reverse 
of the given array and reversing the output array.
*/