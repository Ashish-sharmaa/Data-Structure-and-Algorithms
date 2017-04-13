#include<bits/stdc++.h>
#define ll long
using namespace std;
int main()
{
    ll i,j,k,l,n,m,k1,ans,j1,pp;
    cout<<" Enter no. of elements\n";
    cin>>n;
    ll a[n+1];
    for(i=1;i<=n;i++)
    {
        cout<<"Enter value\n";
        cin>>a[i];
    }
    ll p[n+1][n+1],w[n+1][n+1],r[n+1][n+1];
    memset(p,0,sizeof(p));
    memset(r,0,sizeof(r));
    memset(w,0,sizeof(w));
    for(i=0;i<=n;i++)
        p[i][i]=w[i][i]=r[i][i]=0;
    for(j=1;j<=n;j++)
        p[0][j]=p[0][j-1]+a[j];
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            p[i][j]=p[i-1][j]-a[i];
        }
    }
    cout<<" First matrix\n";
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            cout<<p[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    k1=1;
    while(k1<=n)
    {
        k=k1;
        i=0;
        while(k<=n)
        {
            ans=10000007;
            for(j=i;j<k;j++)
            {
                if(w[i][j]+w[j+1][k]<ans)
                {
                    ans=w[i][j]+w[j+1][k];
                    j1=j;
                }
            }
            w[i][k]=p[i][k]+ans;
            r[i][k]=j1+1;
            k++;
            i++;
        }
        k1++;
    }
    cout<<" Weight matrix\n";
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            cout<<w[i][j]<<" ";
        cout<<endl;
    }
    cout<<" Root matrix\n";
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            cout<<r[i][j]<<" ";
        cout<<endl;
    }
    ll vv[n+1][2],cc[n+1];
    memset(cc,0,sizeof(cc));
    cc[r[0][n]]=1;
    memset(vv,0,sizeof(vv));
    pp=1;
    i=0;
    while(i<n)
    {
        j=n;
        while(r[i][j]!=0)
        {
            if(pp==1)
            {
                if(r[i][j]!=r[i][j-1]&&r[i][j-1]!=0&&cc[r[i][j-1]]==0)
                {
                    vv[r[i][j]][0]=r[i][j-1];
                    cc[r[i][j-1]]=1;
                }
                j--;
            }
            else if(pp==0||pp==2)
            {
                if(r[i][j]!=r[i-1][j]&&cc[r[i][j]]==0)
                {
                    pp=1;
                    vv[r[i-1][j]][1]=r[i][j];
                    cc[r[i][j]]=1;
                }
                else
                {
                    pp=2;
                    j--;
                }
            }
        }
        i++;
        pp=0;
    }
    cout<<" Root is "<<r[0][n]<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<"For element "<<i<<" Left element ="<<vv[i][0]<<" and right element ="<<vv[i][1]<<endl;
    }
return 0;
}
