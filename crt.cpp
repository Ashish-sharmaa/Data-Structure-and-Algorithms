#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cerr<< #x <<" is "<<x<<endl;
using namespace std;
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
int main()
{
    ll i,k,l,j,m,n;
    cout<<" Enter no. of equations ";
    cin>>n;
    ll a[n+1][2];
    for(i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    ll M=1;
    for(i=1;i<=n;i++)
    {
        M=M*a[i][1];
    }
    ll inv[n+1];
    for(i=1;i<=n;i++)
    {
        inv[i]=poww(M/a[i][1],a[i][1]-2);
    }
    ll x=0;
    for(i=1;i<=n;i++)
    {
        x=(x+a[i][0]*(M/a[i][1])*inv[i])%M;
    }
    cout<<x<<" modd "<<M<<endl;
    return 0;
}
