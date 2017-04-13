#include<iostream>
#include<cmath>
#define maxx 1000000007
using namespace std;
long double poww(int n)
{
    int i,j,m=n;
     long double ans,anss=1;
    while(n>0)
    {
        i=n%2;
        if(n==m)
            ans=1.61803;
        else
            {
                ans=(ans*ans);
                long long q=ans/maxx;
                ans=ans-q*maxx;
            }
        if(i==1)
         {
             anss=(anss*ans);
                long long q=anss/maxx;
                anss=anss-q*maxx;
         }
         n=n/2;
    }
    return anss;
}
int main()
{
    int n,i,j;
    cin>>n;
    double p;
    j=poww(n+1)/sqrt(5)+0.5;
    cout<<j<<endl;
}
