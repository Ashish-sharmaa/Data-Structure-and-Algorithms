#include<bits/stdc++.h>
#define ll long
using namespace std;
int main()
{
    ll i,j,k,l1,l2,c=0,I=0,J=0;
    string s1,s2;
    cout<<" enter the two strings\n";
    cin>>s1>>s2;
    l1=s1.size();
    l2=s2.size();
    ll a[l1+1][l2+1],b[l1+1][l2+1];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(i=1;i<=l1;i++)
    {
        for(j=1;j<=l2;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                a[i][j]=a[i-1][j-1]+1;
                if(a[i][j]>c)
                    c=a[i][j];
                b[i][j]=3;
                I=i;
                J=j;
            }
            else
            {
                if(a[i-1][j]>=a[i][j-1])
                {
                    a[i][j]=a[i-1][j];
                    b[i][j]=1;
                }
                else
                {
                    a[i][j]=a[i][j-1];
                    b[i][j]=2;
                }
            }
        }
    }
    for(i=0;i<=l1;i++)
    {
        for(j=0;j<=l2;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<"\nlength of lcs is "<<c<<endl;
//        for(i=0;i<=l1;i++)
//    {
//        for(j=0;j<=l2;j++)
//            cout<<b[i][j]<<" ";
//        cout<<endl;
//    }
    string ans;
    char cc;
    while(I!=0&&J!=0)
    {
        if(b[I][J]==3)
        {
            cc=s1[I-1];
            ans=cc+ans;
            I--;
            J--;
        }
        else if(b[I][J]==2)
            J--;
        else
            I--;
    }
    if(ans.empty()==0)
    cout<<ans<<endl;
    else
        cout<<"No  common subsequence\n";
    return 0;
}
