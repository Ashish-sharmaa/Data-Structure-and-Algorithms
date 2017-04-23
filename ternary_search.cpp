//! Dividing range in three portions (0,n/3);(n/3+1,2n/3);(2n/3+1,n)
#include<bits/stdc++.h>
#define ll long long
#define modd 1000000007
#define dbg(x) cout<< #x <<" is "<<x<,endl;
using namespace std;
void ter(ll a[],ll st,ll ed,ll ele)
{
    if(st>ed)
    {
        cout<<"Not found\n";
    }
    else
    {
        if(st==ed&&a[st]!=ele)
            cout<<"Not found\n";
        else
        {
            ll j=ed-st+1;
            ll mid1=st+j/3;
            ll mid2=st+2*j/3;
            if(a[mid1]==ele)
                cout<<"Found at "<<mid1+1<<endl;
            else if(a[mid2]==ele)
                cout<<"Found at "<<mid2+1<<endl;
            else
            {
                if(ele<a[mid1])
                {
                    ter(a,st,mid1-1,ele);
                }
                else if(ele<a[mid2])
                {
                    ter(a,mid1+1,mid2-1,ele);
                }
                else
                    ter(a,mid2+1,ed,ele);
            }
        }
    }
}
int main()
{
    ll i,j,k,l,n,m;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<"Enter the element you want to search\n";
    ll e;
    cin>>e;
    ter(a,0,n-1,e);
    return 0;
}
