#include<iostream>
#include<cstring>
using namespace std;

void combination(int n);
int main(){
    int n;
    cin>>n;
    combination(n);
}
string alph[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
 string ans;
void combination(int n)
{
    string temp;
    if(n==0)
    {ans=ans+temp+' ';
    return;}
    int r=n%10;
    n=n/10;
    int length=alph[r].length();
    combination(n);
    for(int i=0;i<length;i++)
    {
        ans=ans+alph[r][i];
        cout<<ans;
    }
    cout<<endl;
}
