#include<iostream>
using namespace std;
#define ll long long
long long fac(long long n)
{
    ll i,j=0,p=n-1,cou,carr=0;
    ll a[1000]={};
    while(n>0)
    {
       a[j]=n%10;
       j++;
       n=n/10;
    }
    j--;
    for(cou=p;cou>1;cou--)
    {
        i=0;
        while(i<=j)
        {
            a[i]=(a[i]*cou+carr);
            carr=a[i]/10;
            a[i]=a[i]%10;
            i++;
        }
        while(carr>0)
        {
            j++;
            a[j]=carr%10;
            carr=carr/10;
        }
    }
    for(i=j;i>=0;i--)
        cout<<a[i];
    cout<<endl;
    return 1;
}
int main()
{
    long long  n,t,res;
    cin>>t;
    while(t--)
    {
        cin>>n;
        res=fac(n);
//cout<<res<<endl;
    }
    return 0;
}
