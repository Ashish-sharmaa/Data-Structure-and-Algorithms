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
    ll ele;
    cin>>ele;
    k=1;
    for(ll b=n/2;b>=1;b=b/2)
    {
        while(k+b<=n&&a[k+b]<ele)
            k=k+b;
        if(k>n)
        {
            cout<<"NOT found\n";
            return 0;
        }
        if(a[k]==ele)
        {
            cout<<"Found at ="<<k+b<<endl;
            return 0;
        }
        if(k==n||(a[k]<ele&&a[k+1]>ele))//!Either last element or(next element is > and current is < than ele)
        {
            cout<<"NOT found\n";
            return 0;
        }
    }
}
