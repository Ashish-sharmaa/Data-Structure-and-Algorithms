#include<iostream>
#include<cmath>
using namespace std;
int a[1000001];
int B[1000001];
void seive()
{
    int i,j;
    a[0]=a[1]=0;
    for(i=2;i<=1000000;i++)
        a[i]=1;
    for(i=2;i<=sqrt(1000000);i++)
    {
        if(a[i]==1)
        {
            for(j=i*i;j<=1000000;j=j+i)
                a[j]=0;
        }
    }
    B[0]=B[1]=0;
    int c=0;
    for(i=2;i<=1000000;i++)
    {
            B[i]=B[i-1]+a[i];

    }
}
int main()
{
    seive();
    int t,A,b,res,i,j;
    cin>>t;
    while(t--)
    {
        res=0;
        cin>>A>>b;
        if(a[A]==1)
        {
                j=B[b]-B[A]+1;
        }
        else
        {
                j=B[b]-B[A];
        }
        double p;
        p=b-A+1;
        p=j/p;
       // cout<<"j is and p is "<<j<<" "<<p<<endl;
        cout.precision(6);
        cout.setf(ios::floatfield,ios::fixed);
        cout<<p<<endl;
    }
    return 0;
}
