#include<bits/stdc++.h>
#define ll long long 
#define dbg(x) cerr<< #x <<" is "<<x<<endl;
using namespace std;
// Complexity is O(n^2)
int main()
{
	string s;
	cin>>s;
	ll i,j,k,l,n,m;
	n=s.size();
	ll a[n+1][n+1];
	memset(a,0,sizeof(a));
	for(i=0;i<n;i++)
	{
		a[i][i]=1;   //As we can get pallindrome of length 1 from each character
					 //(we are taking columns as string length(counting starts from diagnol(i,i))
	}
	k=1;
	ll st=0;
	for(i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			a[i][i+1]=1;  //Did not append with 3 case as we can not have middle of (i,i+1) as we are
			k=2;		  // dealing with upper triangle only
			st=i;
		}
	}
	ll comp=3;
	for(i=0;i<n;i++)
	{
		j=i+comp-1;
		if(s[i]==s[j])  // first ==last
		{
			if(a[i+1][j-1]==1) // Checking that if first+1 and last-1 is pallindrome or not
			{
				k=comp;
				st=i;
				a[i][j]=1;
			}
		}
		if(j>=n-1)
		{
			i=0;
			comp++;
		}
		if(comp>n)
			break;
	}
	cout<<"Length of largest pallindrome substring is "<<k<<endl;
	cout<<" String ="<<s.substr(st,k)<<endl;
	return 0;
}