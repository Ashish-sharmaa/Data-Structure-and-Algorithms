#include<bits/stdc++.h>
#define ll long 
using namespace std;
#define dbg(x) cerr<<#x<<" is "<<x<<endl;
// Manacher's algo O(n) to find longest pallindrome substring
string toOddLength(string s)      // Making the string of length 2*n+1 to compensate for even length strings
{
	string ans="#";
	for(int i=0;s[i]!='\0';i++)
	{
		ans=ans+s[i];
		ans=ans+'#';
	}
	return ans;
}
string toOriginal(string s,int j,int ans) // converting back to original
{
	string v;
	ans=ans/2;
	for(int i=0;i<=ans;i++)
	{
		if(s[j-i]!='#')
			v=s[j-i]+v;
		if(s[i+j]!='#'&&i!=0)
			v=v+s[i+j];
	}
	return v;
}
int main()
{
	freopen("test_case.txt","r",stdin);
	string s;
	cin>>s;
	s=toOddLength(s);
	int n=s.size();
	int a[n];
	memset(a,0,sizeof(a));
	int i=0;
	int centre=1;  // next centre to be taken
	int left,right;
	left=right=0;  // leftmost and rightmost portion of the current pallindrome with i as mid
	while(i<n)
	{
		while(left>=0&&right<n)
		{
			if(s[left]==s[right])
			{
				if(left==right)
					a[i]+=1;
				else
					a[i]+=2;
				left--;
				right++;
			}
			else
				break;
		}
		if(right==n)
			break;
		left++;
		right--;
		if(left==right)    // pallindrome of length=1
		{
			i=left=right=centre;
			centre++;
			continue;
		}
		int mm=i-a[i]/2;
		while(centre<=right)    // considering all the possible centres upto right
		{
			int temp1=2*i-centre;
			temp1=temp1-a[temp1]/2;
			if(temp1>mm)                   // case 1
			{
				a[centre]=a[2*i-centre];
			}
			else if(temp1==mm)            // case 3 and important one
			{
				a[centre]=a[2*i-centre];
				left=centre-(a[centre]/2+1);
				right++;
				break;
			}
			else          // case 4
			{
				a[centre]=(right-centre)*2+1;
			}
			centre++;
		}
		if(centre>right)        //  important if centre becomes larger than left in case of 1 character pallindrome
		{
			left=right=centre;
		}
		i=centre;
		centre++;
	}
	int ans=0,j=0;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
		if(a[i]>ans)
		{
			j=i;
			ans=a[i];
		}
	}
	cout<<endl;
	cout<<toOriginal(s,j,ans)<<endl;
	return 0;
}
