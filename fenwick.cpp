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
//!Finding sum of elements with every query of form (0-r)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen( "test_case.txt", "r", stdin);
    // freopen( "output.txt", "w", stdout);
    ll i,j,k,l,n,t,m,p,temp=0,ans=0;
    cin>>n;
    ll a[n+1];
    loop(i,1,n)
     get(a[i]);
    ll b[n+1];
    mem(b);
    loop(i,1,n)
    {
        j=i;
        while(j<=n)
        {
            b[j]+=a[i];
            j=j+(j&((~j)+1));
        }
    }
    ll q;
    cin>>q;
//    cout<<"Initial Binary Indexed Tree\n";
//    for(i=1;i<=n;i++)
//        cout<<b[i]<<" ";
    while(q--)
    {
        cin>>k;
        ans=0;
        while(k>0)
        {
            ans=ans+b[k];
            k=k-(k&((~k)+1));
        }
        cout<<"ans="<<ans<<endl;
    }
    return 0;
}





