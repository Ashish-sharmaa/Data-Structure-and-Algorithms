#include<iostream>
#define ll long long
using namespace std;
void quick(ll a[],ll st,ll ed)
{
    if(st<ed)
    {
    ll pivot=(st+ed)/2;
    ll i=st-1,j=ed+1,c=a[pivot];
    while(1)
    {
        while(1)
        {
            j--;
            if(a[j]<=c)
                break;
        }
        while(1)
        {
            i++;
            if(a[i]>=c)
                break;
        }
        if(i<j)
        {
            ll temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
        {
            if(i==j)
            {
                j--;
                quick(a,st,j);
                quick(a,i+1,ed);
            }
            else if(j<i)
            {
              quick(a,st,j);
              quick(a,i,ed);
            }
            break;
        }
    }
    }
}
int main()
{
    ll n,i,j;
    cout<<" Enter the size\n";
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    quick(a,0,n-1);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
