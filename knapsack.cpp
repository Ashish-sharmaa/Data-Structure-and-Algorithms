#include<iostream>
#define ll double
using namespace std;
void rec(ll a[],ll b[],ll c[],long st,long ed,long mid)
{
        long i=st,j=mid+1,c1=0;
    ll a1[ed-st+1],c2[ed-st+1],b1[ed-st+1];
    while(i<=mid&&j<=ed)
    {
        if(a[i]>a[j])
            {
                b1[c1]=b[i];
                c2[c1]=c[i];
                a1[c1++]=a[i++];
            }
        else
            {
                b1[c1]=b[j];
                c2[c1]=c[j];
                a1[c1++]=a[j++];
            }
    }
    while(i<=mid)
        {
            b1[c1]=b[i];
            c2[c1]=c[i];
            a1[c1++]=a[i++];
        }
    while(j<=ed)
        {
            b1[c1]=b[j];
            c2[c1]=c[j];
            a1[c1++]=a[j++];
        }

    c1--;
    while(c1>=0)
        {
            b[ed]=b1[c1];
            c[ed]=c2[c1];
            a[ed--]=a1[c1--];
        }
}
void mer(double a[],ll b[],ll c[],long st,long ed)
{
    long c1=(st+ed)/2;
    if(st!=c1)
    {
        mer(a,b,c,st,c1);
        mer(a,b,c,c1+1,ed);
        rec(a,b,c,st,ed,c1);
    }
    else if(a[st]<a[ed])
    {
        double temp=a[st];
        a[st]=a[ed];
        a[ed]=temp;
        swap(b[st],b[ed]);
        swap(c[st],c[ed]);
    }
}
int main()
{
    long i,k,kk,l,n;
    cin>>n;
    ll a[n],b[n];
    ll j;
    double c[n];
    cout<<" Enter weight and value\n";
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        c[i]=(double)b[i]/a[i];
    }
    cout<<" Enter Knapsack Weight\n";
    cin>>k;
    kk=k;
    do
    {
        j=0;
        k=kk;
        cout<<" Press 1 for greedy about weight, 2 for greedy about profit and 3 for greedy about profit/weight\n";
        cin>>i;
        switch(i)
        {
        case 1:
            mer(a,b,c,0,n-1);
            break;
        case 2:
            mer(b,a,c,0,n-1);
            break;
        case 3:
            mer(c,a,b,0,n-1);
            break;
        }
        i=0;
            while(k>0&&i<n)
            {
                if(k>=a[i])
                {
                    k=k-a[i];
                    j=j+b[i];
                }
                else
                {
                    j=j+k*c[i];
                    k=0;
                }
                i++;
            }
            cout<<"result="<<j<<endl;
        cout<<" Press 1 to continue\n";
        cin>>i;
    }while(i==1);
            return 0;
}
