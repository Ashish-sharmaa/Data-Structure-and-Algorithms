#include<bits/stdc++.h>
#define ll long
using namespace std;
int main()
{
    ll i,j,k,l1,l2,n,m,p;
    string s1,s2;
    cout<<" enter the two strings\n";
    cin>>s1;
    cin>>s2;
    l1=s1.size();
    l2=s2.size();
    ll a[l1][l2],b[l1][l2];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    b[0][0]=1;
    for(i=0;i<l2;i++)
    {
        if(s1[0]==s2[i])
        {
            a[0][i]=1;
            b[0][i]=3;
        }
        else
        {
            if(i!=0)
                a[0][i]=a[0][i-1];
            b[0][i]=1;
        }
    }
    for(i=0;i<l1;i++)
    {
        if(s1[i]==s2[0])
        {
            a[i][0]=1;
            b[i][0]=3;
        }
        else
        {
            if(i!=0)
            {
                a[i][0]=a[i-1][0];
                b[i][0]=2;
            }
        }
    }
    for(i=1;i<l1;i++)
    {
        for(j=1;j<l2;j++)
        {
            if(s1[i]==s2[j])
            {
                a[i][j]=a[i-1][j-1]+1;
                b[i][j]=3;
            }
            else
            {
                if(a[i-1][j]>a[i][j-1])
                {
                    a[i][j]=a[i-1][j];
                    b[i][j]=2;
                }
                else
                {
                    a[i][j]=a[i][j-1];
                    b[i][j]=1;
                }
            }
        }
    }
    i=l1-1;
    j=l2-1;
    cout<<"length is "<<a[i][j]<<endl;
    string ans;
    while(i>=0&&j>=0)
    {
        if(b[i][j]==3)
        {
            ans=s1[i]+ans;
            i--;
            j--;
        }
        else if(b[i][j]==2)
        {
            i--;
        }
        else
            j--;
    }
    cout<<"The LCS is: "<<ans<<endl;
    return 0;
}
