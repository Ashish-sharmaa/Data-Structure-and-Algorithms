#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cerr<< #x <<" is "<<x<<endl;
using namespace std;
ll poww(ll a,ll b)
{
    ll modd=b+2;
    ll m=b, ans=1,temp;
    while(b>0)
    {
        ll n=b%2;
        if(b==m)
        {
            temp=a%modd;
        }
        else
            temp=(temp*temp)%modd;
        if(n==1)
            ans=(ans*temp)%modd;
        b=b/2;
    }
    return ((modd+ans)%modd);
}
//! only if gcd(a,n)==1
int main()
{
	ll a,n,m,k;
	cin>>a>>n;
	k=__gcd(a,n);
	if(k==1)
	{
		m=poww(a,n-2);
		cout<<m<<endl;
		return 0;
	}
	cout<<"Not possible\n";
	return 0;
}