//! finding no. of ways to tile a 4*n grid with tiles of 4*1 only
#include<bits/stdc++.h>
#define ll long long
#define modd 1000000007
#define dbg(x) cout<< #x <<" is "<<x<,endl;
using namespace std;
int main()
{
    ll i,j,k,l,n,m;
    cin>>n;
    ll til[n+1];
    til[0]=0;
    til[1]=til[2]=til[3]=1;
    til[4]=2;
    for(i=5;i<=n;i++)
    {
        til[i]=til[i-1]+til[i-4];
        //! If in ith column, a tile is placed vertically than it will be (i-1) and if it is placed horizontally
        //! than three more horizontal tiles are required to fill all the rows, therefore it will be (i-4)
        til[i]%=modd;
    }
    cout<<til[n];
    return 0;
}
