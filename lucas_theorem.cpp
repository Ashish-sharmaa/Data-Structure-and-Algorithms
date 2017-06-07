#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cerr<< #x <<" is "<<x<<endl;
using namespace std;
//! Find nCr mod p  where p is prime no.
ll poww(ll a,ll b)
{
    ll modd=b+2;
    ll m=b, ans=1,temp;
    while(b>0)
    {
        ll n=b%2;
        if(b==m)
        {
            temp=a%modd;
        }
        else
            temp=(temp*temp)%modd;
        if(n==1)
            ans=(ans*temp)%modd;
        b=b/2;
    }
    return ((modd+ans)%modd);
}
void fun(vector<ll>&v,ll n,ll p)
{
    ll i,j,k,l;
    while(n>0)
    {
        j=n%p;
        v.push_back(j);
        n=n/p;
    }
}
ll ncr(ll n,ll r,ll p)
{
    ll j=max(n-r,r);
    ll k1=1,i;
    for(i=n;i>j;i--)
    {
        k1=(k1*i)%p;
    }
    j=min(n-r,r);
    ll k2=1;
    for(i=2;i<=j;i++)
    {
        k2=(k2*i)%p;
    }
     k2=poww(k2,p-2);
     k1=(k1*k2)%p;
     return k1;
}
int main()
{
    cout<<"Enter n and r\n";
    ll i,j,k,l,n,m,r,p;
    cin>>n>>r;
    vector<ll>n1,n2;
    cout<<"Enter prime p\n";
    cin>>p;
    fun(n1,n,p);
    fun(n2,r,p);
    l=min(n1.size(),n2.size());
    ll ans=1;
    ll l1=n1.size();
    for(i=0;i<l;i++)
    {
        ans=(ans*ncr(n1[i],n2[i],p))%p;
    }
    cout<<ans<<endl;
    return 0;
}
