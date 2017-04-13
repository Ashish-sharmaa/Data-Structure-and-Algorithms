//! Ashish Sharma  !//
//! C.S.E (B.Tech) !//
//! Nit Jalandhar  !//
#include<bits/stdc++.h>
#define ll long long
#define lg long
#define dd double
#define fl float
#define ch char
#define modd 1000000007
#define maxx (long long)1e18
#define minn -(long long)1e18
#define scf(a) scanf("%lld",&a)
#define scdf(a) scanf("%ld",&a)
#define prt(a) printf("%lld",a)
#define prts(a) printf("%lld ",a)
#define prdt(a) printf("%ld",&a)
#define prdts(a) printf("%ld ",&a)
#define get(a) cin>>a
#define puts(a) cout<<a<<" "
#define put(a) cout<<a
#define loop(i,a,b) for(i=a;i<=b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)
#define nxt printf("\n")
#define space printf(" ")
#define mem(s) memset(s,0,sizeof(s))
#define memi(s) memset(s,-1,sizeof(s))
#define pb push_back
#define popb pop_back()
#define pbf push_front
#define popf pop_front()
using namespace std;
ll b[105][105];
ll fun(ll a[],ll s[],ll i,ll n,ll w)
{
    if(i>n)
        return 0;
    if(b[i][w]!=-1)
        return b[i][w];
    else
    {
        if(s[i]>w)
        {
             b[i][w]=fun(a,s,i+1,n,w);
        }
        else
        {
            b[i][w]=max(a[i]+fun(a,s,i+1,n,w-s[i]),fun(a,s,i+1,n,w));
        }
        return b[i][w];
    }
}
int main()
{
    ll i,j,k,l,n,m,t,p,w;
    get(t);
    while(t--)
    {
        get(n);
        get(w);
        memi(b);
        ll a[n+1],s[n+1],ans;
        loop(i,1,n)
        {
            get(a[i]);
        }
        loop(i,1,n)
            get(s[i]);
        b[1][w]=fun(a,s,1,n,w);
        put(b[1][w]);
        nxt;
    }
    return 0;
}
