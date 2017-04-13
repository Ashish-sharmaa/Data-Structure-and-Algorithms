#include<iostream>
#define ll long long
using namespace std;
void rec(ll a[],ll st,ll ed,ll mid)
{
    ll i=st,j=mid+1,b[ed-st+1],c=0;
    while(i<=mid&&j<=ed)
    {
        if(a[i]<a[j])
            b[c++]=a[i++];
        else
            b[c++]=a[j++];
    }
    while(i<=mid)
        b[c++]=a[i++];
    while(j<=ed)
        b[c++]=a[j++];
    c--;
    while(c>=0)
        a[ed--]=b[c--];
}
void mer(long long a[],long long st,long long ed)
{
    long long c=(st+ed)/2;
    if(st!=c)
    {
        mer(a,st,c);
        mer(a,c+1,ed);
        rec(a,st,ed,c);
    }
    else if(a[st]>a[ed])
    {
        long long temp=a[st];
        a[st]=a[ed];
        a[ed]=temp;
    }
}
int  main()
{
	 long long i,j,t,n;
	cin>>n;
	long long a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	mer(a,0,n-1);
	for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
	return 0;
}

