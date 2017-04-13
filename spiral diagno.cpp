#include<iostream>
#include<cmath>
using namespace std;
int s[100001];
void prime(long long n,double &c)
{
    long i;
    for(i=3;i<=sqrt(n);i=i+2)
    {
        if(n%i==0)
        {
            break;
        }
    }
    if(i>sqrt(n))
    {
        /*cout<<" yes for "<<n<<endl;*/
        c++;
    }
}
int main()
{
    long t,n,i,c,j,nn;
    double pp;
    cin>>t;
    while(t--)
    {
        c=0;
        cin>>n;
        nn=n;
        double I;
        long long a[(3*n-3)/2];
        I=n*n;
        while(n>1)
        {
            a[c++]=I-n+1;
            while(c%3!=0)
            {
                a[c]=a[c-1]-n+1;
                c++;
            }
            n=n-2;
            I=n*n;
        }
      /*  for(i=0;i<c;i++)
            cout<<a[i]<<" ";
        cout<<endl;*/
        pp=0;
        for(j=0;j<c;j++)
        {
            prime(a[j],pp);
        }
        pp=pp/(2*nn-1)*100;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(6);
        cout<<pp<<endl;
    }
}
