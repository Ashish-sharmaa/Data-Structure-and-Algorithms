//! Ashish Sharma  !//
//! C.S.E (B.Tech) !//
//! Nit Jalandhar  !//
#include<bits/stdc++.h>
#define ll long long
#define lg long
#define dd double
#define fl float
#define ch char
#define maxx 1000000007
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
#define pb push_back
using namespace std;
void make(ll a[],ll b[],ll node,ll st,ll ed)
{
    if(st==ed)
    {
        b[node]=a[st];
    }
    else
    {
        ll c=(st+ed)/2;
        make(a,b,2*node,st,c);
        make(a,b,2*node+1,c+1,ed);
        b[node]=b[2*node]+b[2*node+1];
    }
}
void update(ll a[],ll b[],ll node,ll st,ll ed,ll idx,ll val)
{
    if(st==ed)
    {
        a[st]+=val;
        b[node]+=val;
    }
    else
    {
        ll c=(st+ed)/2;
        if(idx>=st&&idx<=c)
        {
            update(a,b,2*node,st,c,idx,val);
        }
        else
            update(a,b,2*node+1,c+1,ed,idx,val);
        b[node]=b[2*node]+b[2*node+1];
    }
}
void dis(ll b[],ll n)
{
    ll i;
    loop(i,1,n)
    {
        if(b[2*i]!=0){
        cout<<" child of "<<b[i]<<" are "<<b[2*i];
        if(b[2*i+1]!=0)
            cout<<" "<<b[2*i+1]<<endl;
        }
    }
    nxt;
}
ll query(ll b[],ll node,ll st,ll ed,ll ld,ll rd)
{
    if(ld>ed||rd<st)
        return 0;
    if(ld<=st&&rd>=ed)
        return b[node];
    ll c=(st+ed)/2;
    ll p1=query(b,2*node,st,c,ld,rd);
    ll p2=query(b,2*node+1,c+1,ed,ld,rd);
    return (p1+p2);
}
int main()
{
    ll i,j,k,l,n,m,p,temp=0,ans=0,q;
    get(n);
    ll a[n+1],b[4*n+1]; //! Size of segmented tree is 4*n+1
    mem(b);
    loop(i,1,n)
     get(a[i]);
    make(a,b,1,1,n);
    //! Display
    dis(b,n);
    //! Updating Tree
//!    get(q);
//!    while(q--)
//!   {
//!        cout<<" Enter index\n";
//!       get(k);
//!       cout<<" Enter value to be added\n";
//!       get(l);
//!       update(a,b,1,1,n,k,l);
//!   }
//!   dis(b,n);
    //! Query
    get(q);
    while(q--)
    {
        cout<<" Enter st. and end. index\n";
        cin>>l>>k;
        ans=query(b,1,1,n,l,k);
        put(ans);
        nxt;
    }
    return 0;
}
