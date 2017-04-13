#include<bits/stdc++.h>
#define ll long long
#define maxx 100000007
using namespace std;
void print(ll *s,ll st,ll ed,ll n)
{
    ll c=*(s+ed+(st)*n);
 if(st==ed)
        cout<<st;
    else
    {
        cout<<"(";
        print(s,st,c,n);
        print(s,c+1,ed,n);
        cout<<")";
    }
}
int main()
{
    ll i,j,k,l,n,m,ans=0,c;
    cout<<"Enter no. of matrices\n";
    cin>>n;
    ll p[n+1];
    for(i=0;i<n;i++)
    {
        cin>>j>>k;
        p[i]=j;
        if(i==n-1)
            p[++i]=k;
    }
    ll a[n+1][n+1],s[n+1][n+1];
    for(i=0;i<=n;i++)
    {
        a[i][i]=0;
        s[i][i]=i;
    }
    j=2;
    i=1;
    while(j-i<n)
    {
        k=j;
        for(;k<=n;k++)
        {
            ans=maxx;
             cout<<" Element is "<<i<<" "<<k<<endl;
            for(c=i;c<k;c++)
            {
                if(ans>a[i][c]+a[c+1][k]+p[i-1]*p[c]*p[k])
                {
                    ans=a[i][c]+a[c+1][k]+p[i-1]*p[c]*p[k];
                    s[i][k]=c;
                }
            }
            a[i][k]=ans;
            i++;
        }
        j++;
        i=1;
    }
//    for(i=1;i<=n;i++)
//    {
//        for(j=i;j<=n;j++)
//            cout<<a[i][j]<<" ";
//        cout<<endl;
//    }
//    cout<<endl;
//    for(i=1;i<=n;i++)
//    {
//        for(j=i;j<=n;j++)
//            cout<<s[i][j]<<" ";
//        cout<<endl;
//    }
    //!Printing subsequence
    cout<<" minimum length is "<<a[1][n]<<endl;
    print(&s[0][0],1,n,n+1);  //! As size is n+1
}
