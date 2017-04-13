#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll i,j,k,l,n,m;
    cin>>n;
    ll a[n+1];
    for(i=1;i<=n;i++)
        cin>>a[i];
    ll s=0,p=0;
    for(i=1;i<=n;i++)
    {
        s=max(a[i],s+a[i]);//! finding max. value upto ith by either extending previous subarray or starting from this ith index
        p=max(s,p);        //! Overall max. sum
    }
    cout<<p<<endl;
    return 0;
}
