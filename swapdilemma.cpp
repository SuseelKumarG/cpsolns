//in all subarrays of array a of length k have their or same then it is true for any sub array of length > k
//END
//to coprime numbers a and b can reproduce any number x greater than a*b-a-b as x= m*a+n*b
//END
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl; 
typedef vector<bool> vb;
typedef vector<string> vs;
#define MAX 1000000007
#define N 10010

long long gcdl(long long a, long long b){
    while(a > 0 && b > 0){
        if(a > b){
            a %= b;
        }
        else{
            b %= a;
        }
    }
    return a + b;
}  
ll lcml(ll a,ll b)
{
    a=(a*b)/gcdl(a,b);
    return a;
}
int gcd(int a, int b){
    while(a > 0 && b > 0){
        if(a > b){
            a %= b;
        }
        else{
            b %= a;
        }
    }
    return a + b;
}
int lcml(int a,int b)
{
    a=(a*b)/gcd(a,b);
    return a;
}

ll merge(int *arr, int *temp, ll left, ll mid, ll right)
{
    ll inv_count = 0;
 
    ll i = left; /* i is index for left subarray*/
    ll j = mid;  /* j is index for right subarray*/
    ll k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
 
            /* this is tricky -- see above explanation/
              diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }
 
    /* Copy the remaining elements of left subarray
     (if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    /* Copy the remaining elements of right subarray
     (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];
 
    /*Copy back the merged elements to original array*/
    for (i=left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}
 
/* An auxiliary recursive function that sorts the input
   array and returns the number of inversions in the
   array. */
ll _mergeSort(int *arr, int *temp, ll left, ll right)
{
    ll mid, inv_count = 0;
    if (right > left)
    {
        /* Divide the array llo two parts and call
          _mergeSortAndCountInv() for each of the parts */
        mid = (right + left)/2;
 
        /* Inversion count will be sum of inversions in
           left-part, right-part and number of inversions
           in merging */
        inv_count  = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid+1, right);
 
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid+1, right);
    }
 
    return inv_count;
}
 
/* This function sorts the input array and returns the
   number of inversions in the array */
ll countSwaps(int *arr, ll n)
{
    int temp[n];
    return _mergeSort(arr, temp, 0, n - 1);
}
 

void solve()
{
    bool poss=1;
    int n;
    cin>>n;
    int a[n];
    int b[n];
    // for(auto it:a)
    // cout<<it<<' ';
    // cout<<'\n';
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    multiset<int>ax,bx;
    for(auto it:a) ax.insert(it);
    for(auto it:b) bx.insert(it);
    if(ax!=bx)
    poss=0;
    ll A=countSwaps(a,n);
    ll B=countSwaps(b,n);
    // cout<<A<<' '<<B<<'\n';
    if(A%2!=B%2)
    poss=0;
    cout<<(poss?"YES":"NO")<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    // int c;
    // cin>>c;
    // cout<<(int(sqrt(c))>>1)+1<<'\n';
    while(t--)
    {
        solve();
    }
    return 0;
}