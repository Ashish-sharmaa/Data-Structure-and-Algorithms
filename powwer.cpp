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
#define prdt(a) printf("%ld",a)
#define prdts(a) printf("%ld ",a)
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
int main()
{
    ll a= poww(26,45454);
    cout<<a;
}
