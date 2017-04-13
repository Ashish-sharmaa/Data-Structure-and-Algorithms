#include<bits/stdc++.h>
#define ll long long 
#define dbg(x) cerr<< #x <<" is "<<x<<endl;
using namespace std;
//! Finding no. of ways to place n-queens in a n*n matrix w/o having them attack one another
//! n<=10
ll ans,n;
deque<pair<ll,ll>>dq;
ll check(ll i,ll j)
{
	if(dq.empty()==1)
		return 1;
	ll k,l;
	for(auto pos=dq.begin();pos!=dq.end();++pos)
	{
		k=pos->first;
		l=pos->second;
		if(l==j||k+l==i+j||k-l==i-j)
			return 0;
	}
	return 1;
}
void rec(ll i)
{
	int j,k;
	if(i>n)
	{
		ans++;
		return ;
	}
	for(j=1;j<=n;j++)
	{
		k=check(i,j);
		if(k==1)
		{
			dq.push_back(make_pair(i,j));
			rec(i+1);
			dq.pop_back();
		}
	}
}
int main()
{
	ll i,j,k,l,m;
	cin>>n;
	rec(1);
	cout<<ans<<endl;
}