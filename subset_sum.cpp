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
//! only if sum of all elements is <= 1e7
int main()
{
    // freopen( "test_case.txt", "r", stdin);
    // freopen( "output.txt", "w", stdout);
    ll i,j,k,l,n,t,m,p,temp=0,ans=0;
    cout<<"Enter no. of elements\n";
    cin>>n;
    ll a[n],sum;
    loop(i,0,n-1)
    {
        get(a[i]);
    }
    sort(a,a+n); //! So elements are in ascending order
    cout<<"Enter sum you want\n";
    cin>>sum;
    ll dp[n+1][sum+1];
    loop(i,0,n-1)
    {
        dp[0][i]=1;
    }
    loop(i,1,sum)
    {
        if(a[0]==i)
            dp[0][i]=1;
        else
            dp[0][i]=0;
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(j<a[i])
                dp[i][j]=dp[i-1][j];
            else
            {
                if(j==a[i])
                    dp[i][j]=1;
                else if(dp[i-1][j]==1)
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i-1][j-a[i]];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(dp[i][sum]==1)
        {
            cout<<"YES\n";
            break;
        }
    }
    if(i==n)
        cout<<"NO\n";
    return 0;
}
