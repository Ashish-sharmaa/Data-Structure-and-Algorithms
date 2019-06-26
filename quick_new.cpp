#include<bits/stdc++.h>
#define ll long long 
using namespace std;
void quick(ll a[],ll st,ll ed)
{
	if(st<ed)
	{
		int i;
		for(i=st;i<ed;i++)
		{
			if(a[i]>a[i+1])
				break;
		}
		if(i!=ed)
		{
			ll piv=a[st];
			i=st+1;
			for(ll j=st+1;j<=ed;j++)
			{
				if(a[j]<piv)
				{
					swap(a[j],a[i]);
					i++;
				}
			}
			swap(a[st],a[i-1]);
			quick(a,st,i-2);
			quick(a,i,ed);
		}
	}
}
int main()
{
	ll n;
	freopen("test_case.txt","r",stdin);
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	quick(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}