#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void gen(vector<int> &temp,int sum,int ind,vector<int> &arr);
int main()
{
    int n,sum;
    cin>>n>>sum;
    vector<int>art(n);
    for(int i=0;i<n;i++)
    cin>>art[i];
    set<int>s;
    for(auto it:art)
    s.insert(it);
    vector<int>arr;
    for(auto it:s)
    arr.push_back(it);
    vector<int> temp; 
    gen(temp,sum,0,arr);
    for(auto &it:ans)
    {
        for(auto i:it)
        cout<<i<<' ';
        cout<<'\n';
    }
}
void gen(vector<int> &temp, int sum, int ind,vector<int> &arr)
{
    if(sum==0)
    {
        ans.push_back(temp);
        return;
    }
    for(int i=ind;i<arr.size();i++)
    {
        if(sum-arr[i]>=0)
        {
            temp.push_back(arr[i]);
            gen(temp,sum-arr[i],ind,arr);
            ind++;
            temp.pop_back();
        }
    }
}
