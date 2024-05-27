#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<int>ans(n);
    stack<int>dot;
    for(int i=0;i<n;i++)
    {
        while(!dot.empty() && arr[i]>arr[dot.top()])
        {
            ans[dot.top()]=i;
            dot.pop();
        }
        dot.push(i);        
    }
    if(!dot.empty())
    {
        while(!dot.empty())
        {
            ans[dot.top()]=-1;
            dot.pop();
        }
    }
    int j=0;
    for(auto i:ans)
    {
        if(i!=-1)
        cout<<arr[j]<<' '<<arr[i]<<'\n';
        else
        cout<<arr[j]<<' '<<-1<<'\n';
        j++;
    }
    cout<<'\n';
}