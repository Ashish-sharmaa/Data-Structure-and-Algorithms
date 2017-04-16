#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cerr<< #x <<" is "<<x<<endl;
using namespace std;
//! diophantine equation is that for which only integral solutions are required
//! equation is ax+by=c
//! Idea is Let GCD of ‘a’ and ‘b’ be ‘g’. g divides a and b.
//! This implies g also divides (ax + by) (if x and y are integers).
//! This implies gcd also divides ‘c’
ll gcd(ll i,ll j)
{
    if(j==0)
        return i;
    return (gcd(j,i%j));
}
int main()
{
    ll a,b,c,x,i,j;
    cin>>a>>b>>c;
    x=gcd(a,b);
    if(c%x==0)
        cout<<"Possible\n";
    else
        cout<<"Not possible\n";
    return 0;
}
