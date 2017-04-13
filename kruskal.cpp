#include<bits/stdc++.h>
#define ll long
using namespace std;
struct gg
{
    bool operator() (tuple<ll,ll,ll>v1,tuple<ll,ll,ll>v2)
    {
        return(get<2>(v1)<=get<2>(v2));
    }
};
ll find_root(ll a[],ll n)
{
    while(1)
    {
      if(a[n]==n)
            return n;
      else
        n=a[n];
    }
}
int main()
{
    ll i,j,k,l,v,e,n,m,t;
    cout<<"Enter no. of vertices and no. of edges\n";
    cin>>v>>e;   //!vertex index ranges from 1 to v;
    set<tuple<ll,ll,ll>,gg>s;
    for(i=1;i<=e;i++)
    {
        cin>>j>>k>>l;  //!source, destination and weight of edge
        s.insert(make_tuple(j,k,l));
    }
        for(auto pos =s.begin();pos!=s.end();++pos)
    {
        cout<<get<0>(*pos)<<" "<<get<1>(*pos)<<" "<<get<2>(*pos)<<endl;
    }
    ll a[v+1],b[v+1];
    for(i=1;i<=v;i++)
        {
            a[i]=i;
            b[i]=1;
        }
    vector<tuple<ll,ll,ll>>vv;
    ll ans=0;
    for(auto pos=s.begin();pos!=s.end();++pos)
    {
        i=get<0>(*pos);
        j=get<1>(*pos);
        k=get<2>(*pos);
        i=find_root(a,i);
        j=find_root(a,j);
        if(i!=j)
        {
            vv.push_back(make_tuple(get<0>(*pos),get<1>(*pos),k));
            if(b[i]<b[j])    //! making larger size root element as root of the union thus balancing the tree
            {
                a[i]=j;
                b[j]+=b[i];      //! With this it will take log v time each time,so overall e(log v) time
            }
            else
            {
                a[j]=i;
                b[i]+=b[j];
            }
            ans+=k;
        }
    }
    cout<<"min. spanning weight is "<<ans<<"\nMST :\n";
    for(auto pos=vv.begin();pos!=vv.end();++pos)
    {
        cout<<get<0>(*pos)<<" "<<get<1>(*pos)<<" with weight="<<get<2>(*pos)<<endl;
    }
    cout<<endl;
    return 0;
}
l
