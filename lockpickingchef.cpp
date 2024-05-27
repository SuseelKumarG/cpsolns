#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string s,k;
        cin>>s>>k;
        int size=n-m+1;
        int soln[size];
        int total=32767;
        for(int i=0;i<size;i++)
        {
            int res=0;
            for(int j=0;j<m;j++)
            {
                int sum=0;
                sum=abs(s[i+j]-k[j]);
                res+=std::min(sum,10-sum);
            }
            total=std::min(res,total);
        }
        cout<<total<<endl;
    }
}