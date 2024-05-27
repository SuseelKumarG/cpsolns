#include<bits/stdc++.h>
using namespace std;
/*in this question you will get an 2d array*/
const int N=1e3+10;
int arr[N][N];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[n+1][n+1];
        for(int i=0;i<n;i++)
        arr[0][i]=0;
        for(int i=0;i<n;i++)
        arr[i][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>ar[i][j];
                arr[i][j]=arr[i-1][j] + ar[i][j] + arr[i][j-1] - arr[i-1][j-1];
            }
        }
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<arr[c][d] - arr[c][b-1] - arr[a-1][d] + arr[a-1][b-1];
    }
}