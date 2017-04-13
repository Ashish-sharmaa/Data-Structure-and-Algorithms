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
//!O(nlogn)
int main()
{
    // freopen( "test_case.txt", "r", stdin);
    // freopen( "output.txt", "w", stdout);
    ll i,j,k,l,n,m,p,temp=0,ans=0;
    cin>>n;
    ll a[n+1],t[n+1],r[n+1];
    vector<ll>v;
    v.pb(minn);
    mem(t);
    memi(r);
    loop(i,1,n)
    {
        cin>>a[i];
    }
    t[1]=1;temp=1;
    v.pb(a[1]);
    l=v.size();
    loop(i,2,n)
    {
        if(a[i]>v[l-1])
        {
            v.pb(a[i]);
            t[l]=i;
            r[i]=t[l-1];
            l++;
        }
        else if(a[i]<v[1])
        {
            v[1]=a[i];
            t[1]=i;
        }
        else
        {
            auto pos=lower_bound(v.begin(),v.end(),a[i]);
            j=distance(v.begin(),pos);
            v[j]=a[i];
            t[j]=i;
            r[i]=t[j-1];
        }
    }
    cout<<"Length is "<<l-1<<endl;
    //! Printing sequence
    deque<ll>q;
    q.push_front(a[t[l-1]]);
    i=r[t[l-1]];
    while(1)
    {
        if(i==-1)
            break;
        q.pbf(a[i]);
        i=r[i];
    }
    cout<<"Printing Sequence :";
    for(auto pos=q.begin();pos!=q.end();++pos)
        cout<<*pos<<" ";
    cout<<endl;
    return 0;
}




