#include<iostream>
#include<cmath>
using namespace std;  
int dectobin(int num){
    int dev=1;
    int bin=0;
    while(num!=0)
    {
        int rem=num%2;
        num/=2;
         bin +=(rem*dev);
        dev*=10;
     }
    return bin;
}
int main()
{
    int n;
    cin>>n;
    int m =pow(2,n);
    int arr[n];
    for (int i=0;i<n;i++)
    cin>>arr[i];
    for(int i=0;i<m;i++)
    {
        int num=dectobin(i);
        int div=pow(10,n-1);
        for(int j=0;j<n;j++)
        {
            int q=num/div;
            int r=num%div;
            if(q!=0)
            cout<<arr[j]<<' ';
            num=r;
            div=div/10;
        }
        cout<<endl;
    }
}