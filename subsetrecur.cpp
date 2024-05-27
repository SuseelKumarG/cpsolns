#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void gen(int size,vector<int> &qn,int i,int arr[])
{
    if(size==i)
    {
        ans.push_back(qn);
        return;
    }
    gen(size,qn,i+1,arr);
    qn.push_back(arr[i]);
    gen(size,qn,i+1,arr);
    qn.pop_back();
}
int main()
{
    int arr[]={1,2,3};
    int size=sizeof(arr)/4;
    vector<int> qn;
    gen(size,qn,0,arr);
    for(auto &it:ans)
    {
        cout<<"[ ";
        for(auto &i:it)
        cout<<i<<' ';
        cout<<"]\n";
    }
}