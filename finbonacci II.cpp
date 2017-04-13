#include<bits/stdc++.h>
#define ll long long
#define maxx 1000000007
using namespace std;
ll fibon(ll n)
{
    ll nn=n,m,i,ans[4],res[4]={1,0,0,1},a[4];
    while(n>0)
    {
        m=n%2;
        if(nn==n)
        {
            ans[0]=ans[1]=ans[2]=1;
            ans[3]=0;
        }
        else
        {
            a[0]=ans[0];
            a[1]=ans[1];
            a[2]=ans[2];
            a[3]=ans[3];
            ans[0]=((a[0]*a[0])%maxx+(a[1]*a[2])%maxx)%maxx;
            ans[1]=((a[0]*a[1])%maxx+(a[1]*a[3])%maxx)%maxx;
            ans[2]=((a[2]*a[0])%maxx+(a[3]*a[2])%maxx)%maxx;
            ans[3]=((a[2]*a[1])%maxx+(a[3]*a[3])%maxx)%maxx;
        }
        if(m==1)
        {
            a[0]=res[0];
            a[1]=res[1];
            a[2]=res[2];
            a[3]=res[3];
            res[0]=((a[0]*ans[0])%maxx+(a[1]*ans[2])%maxx)%maxx;
            res[1]=((a[0]*ans[1])%maxx+(a[1]*ans[3])%maxx)%maxx;
            res[2]=((a[2]*ans[0])%maxx+(a[3]*ans[2])%maxx)%maxx;
            res[3]=((a[2]*ans[1])%maxx+(a[3]*ans[3])%maxx)%maxx;
        }
        n=n/2;
    }
    return res[1];
}
int main()
{
    ll j,n,t;
    cin>>t;
    while(t--)
    {
        j=0;
        cin>>n;
        j=fibon(n);
        cout<<j<<endl;
    }
    return 0;
}
