#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define dbg(x) cerr<< #x<<" ="<<x<<endl;
#define dbg2(x,y) cerr<< #x<<" ="<<x<<" "<<#y<<" ="<<y<<endl;
ll modd;
ll poww(ll a,ll b)
{
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
    return ans;
}
ll inv(ll r1,ll r2)
{
    ll q,r,t1,t2,t;
    r=r1%r2;
    q=r1/r2;
    t1=0;
    t2=1;
    t=t1-q*t2;
    while(r!=1)
    {
        r1=r2;
        r2=r;
        q=r1/r2;
        r=r1%r2;
        t1=t2;
        t2=t;
        t=t1-q*t2;
    }
    return t;
}
ll a[100000];
void seive()
{
    ll i,j;
    for(i=2; i<=sqrt(100000); i++)
    {
        if(a[i]==0)
            for(j=i*i; j<=100000; j=j+i)
                a[j]=1;
    }
    a[0]=a[1]=2;
    ll p=2;
    for(i=2; i<=100000; i++)
    {
        if(a[i]==0)
            p=i;
        a[i]=p;
    }
}
int main()
{
    seive();
    ll i,j,k,l,n,m;
    ll p=101,q=103;
    ll e=a[p*q];
    modd=p*q;
    ll d=inv((p-1)*(q-1),e);
    n=(p-1)*(q-1);
    d=(d+n)%(n);
    cin>>m;
    ll ans=poww(m,e);
    cout<<"Encrypted "<<ans<<endl;
    ans=poww(ans,d);
    cout<<"Decrypted "<<ans<<endl;
    return 0;
}
