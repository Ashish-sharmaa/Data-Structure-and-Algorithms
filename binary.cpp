#include<bits/stdc++.h>
using namespace std;
void bin(int a[],int st,int ed,int ele)
{
    if(ed<st)
    {
        cout<<"NO";
        return ;
    }
    if(st==ed)
    {
        if(a[st]==ele)
        {
            cout<<"Yes at "<<st<<endl;
        }
        else
            cout<<"No\n";
        return ;
    }
    int c=(st+ed)/2;
    if(a[c]==ele)
    {
        cout<<"Yes at "<<c<<endl;
    }
    else
    {
        if(a[c]>ele)
            bin(a,st,c-1,ele);
        else
            bin(a,c+1,ed,ele);
    }
}
int main()
{
    int i,j,k,l,n;
    cin>>n;
    int a[n+1];
    a[0]=-1000000;
    for(i=1;i<=n;i++)
        cin>>a[i];
    cin>>k;
    sort(a,a+n+1);
    bin(a,1,n,k);
    return 0;
}
