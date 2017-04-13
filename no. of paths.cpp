//Moves right, up and diagonal right
#include<iostream>
#define ll long long
#define maxx 1000000007
using namespace std;
int main()
{
    ll i,j,k,l,n;
    ll a[104][104];
    for(i=0;i<104;i++)
        a[i][0]=1;
    for(j=0;j<104;j++)
        a[103][j]=1;
    for(i=102;i>=0;i--)
    {
        for(j=1;j<104;j++)
            a[i][j]=((a[i+1][j]+a[i][j-1])%maxx+a[i+1][j-1])%maxx;
    }
//    for(i=100;i<104;++i)
//    {
//        for(j=0;j<5;j++)
//            cout<<a[i][j]<<"  ";
//        cout<<endl;
    //}
    cin>>n;
    while(n--)
    {
        cin>>i>>j>>k>>l;
        k=k-i;
        l=l-j;
        cout<<a[103-k][l]<<endl;
    }
    return 0;
}
