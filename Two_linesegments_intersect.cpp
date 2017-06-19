#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cerr<< #x <<" is "<<x<<endl;
using namespace std;
//! Orientation 0 anti-clockwise, 1 clockwise, 2 collinear
ll orient(ll x1,ll y1,ll x2,ll y2,ll a1,ll b1)
{
    ll i,j;
    i=(y2-y1)*(a1-x2);
    j=(x2-x1)*(b1-y2);
    if(i==j)
        return 2;
    if(i<j)
        return 0;
    return 1;
}
//! 1 for collinear, 0 for non-collinear
ll collin(ll x1,ll y1,ll x2,ll y2,ll a1,ll b1)
{
    if(a1>=min(x1,x2)&&a1<=max(x1,x2)&&b1>=min(y1,y2)&&b1<=max(y1,y2))
        return 1;
    return 0;
}
void fun(ll x1,ll y1,ll x2,ll y2,ll a1,ll b1,ll a2,ll b2)
{
    ll i=collin(x1,y1,x2,y2,a1,b1);
    i=max(i,collin(x1,y1,x2,y2,a2,b2));
    i=max(i,collin(a1,b1,a2,b2,x1,y1));
    if(i==1)
        cout<<"Lines are collinear\n";
    else
    cout<<"Lines are non-intersecting\n";
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        ll a1,b1,a2,b2;
        cin>>a1>>b1>>a2>>b2;
        ll i,j,k,l,n,m;
        i=orient(x1,y1,x2,y2,a1,b1);
        j=orient(x1,y1,x2,y2,a2,b2);
        if(i==j)
        {
            if(i==2)
                fun(x1,y1,x2,y2,a1,b1,a2,b2);
            else
                cout<<"Lines are non-intersecting\n";
        }
        else
        {
            i=orient(a1,b1,a2,b2,x1,y1);
            j=orient(a1,b1,a2,b2,x2,y2);
            if(i==j)
            {
                if(i==2)
                    fun(a1,b1,a2,b2,x1,y1,x2,y2);
                else
                    cout<<"Lines are non-intersecting\n";
            }
            else
                cout<<"Lines are intersecting\n";
        }
    }
    return 0;
}
